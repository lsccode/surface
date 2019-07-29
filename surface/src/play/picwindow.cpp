#include "picwindow.h"
#include <string>
using namespace std;
picWindow::picWindow()
{
    video_index = -1;
    audio_index = -1;
    format_opts = NULL;
    pFormatCtx = NULL;
    pVideocodecCtx = NULL;
    pAudiocodecCtx = NULL;
    setAcceptDrops(true);
    connect(&videoThread,SIGNAL(genNewImg(QImage)),this,SLOT(showNewImage(QImage)));
    connect(&videoThread,SIGNAL(genNewImg(IplImage *)),this,SLOT(showNewImage(IplImage *)));

//    QPalette palette;
//    palette.setColor(QPalette::Background, QColor(0,0,0));
//    setPalette(palette);
//    setAutoFillBackground(true);

    startAction = new QAction("start",this);
    stopAction = new QAction("stop",this);
    addAction(startAction);
    addAction(stopAction);

    connect(startAction,SIGNAL(triggered()), this, SLOT(startPlay()));
    connect(stopAction,SIGNAL(triggered()), this, SLOT(stopPlay()));
    winH = 0;
    winW = 0;
    setContextMenuPolicy(Qt::ActionsContextMenu);
    setFocusPolicy(Qt::StrongFocus);
    curIplImage = NULL;

    connect(this,SIGNAL(setPlayUrl(QString)),SLOT(PlayStream(QString)));
}
void picWindow::closeEvent(QCloseEvent *event)
{
    videoThread.stop();
    recvThread.stop();
    videoThread.wait();
    recvThread.wait();
    event->accept();
}
void picWindow::releaseCurSrc(QCloseEvent *event)
{
    videoThread.stop();
    recvThread.stop();
    videoThread.wait();
    recvThread.wait();
    if(format_opts != NULL)
    {
        av_dict_free(&format_opts);
        format_opts = NULL;
    }
    if(pVideocodecCtx != NULL)
    {
        avcodec_close(pVideocodecCtx);
        pVideocodecCtx = NULL;
    }
    if(pAudiocodecCtx != NULL)
    {
        avcodec_close(pAudiocodecCtx);
        pAudiocodecCtx = NULL;
    }

    if(pFormatCtx != NULL)
    {
        avformat_free_context(pFormatCtx);
        pFormatCtx = NULL;
    }
    video_index = -1;
    audio_index = -1;
}
void picWindow::startPlay()
{
#if 1
    QString localUrl;
    string str = urlInfo.url.toStdString();
    string tempUser = urlInfo.user.toStdString();
    string tempPass = urlInfo.passWord.toStdString();
    TimeDateUser syncTime;
    if(urlInfo.type == "onvif")
    {
        int ret;
        DeviceBindingProxy deviceMg;
        MediaBindingProxy mediaMg;
        _tds__GetSystemDateAndTime reqGetSystemDateAndTime;
        _tds__GetSystemDateAndTimeResponse resGetSystemDateAndTime;
        _tds__GetDeviceInformation tds__GetDeviceInformation;
        _tds__GetDeviceInformationResponse tds__GetDeviceInformationResponse;

        _tds__GetNetworkProtocols reqGetNetworkProtocols;
        _tds__GetNetworkProtocolsResponse resGetNetworkProtocols;
        _trt__GetProfiles reqGetProfiles;
        _trt__GetProfilesResponse resGetProfilesResponse;
        _trt__GetStreamUri reqGetStreamUri;
        _trt__GetStreamUriResponse resGetStreamUriResponse;
        deviceMg.soap_endpoint = str.c_str();
        {

            ret = deviceMg.GetSystemDateAndTime(&reqGetSystemDateAndTime, &resGetSystemDateAndTime);
            if(ret != SOAP_OK)
            {
                return;
            }
            syncTime.setTimeDate(resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Year,
                                 resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Month,
                                 resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Day,
                                 resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Hour,
                                 resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Minute,
                                 resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Second,
                                 0);

        }
        {
            if(urlInfo.user != "none" && urlInfo.passWord != "none")
            {

                soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",tempUser.c_str(),tempPass.c_str(),syncTime.created());
            }
            ret = deviceMg.GetDeviceInformation(&tds__GetDeviceInformation,&tds__GetDeviceInformationResponse);
            if(ret != SOAP_OK)
            {
                return;
            }
        }
        {
            _tds__GetCapabilities reqGetCapabilities;
            _tds__GetCapabilitiesResponse resGetCapabilities;
            if(urlInfo.user != "none" && urlInfo.passWord != "none")
            {
                soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",tempUser.c_str(),tempPass.c_str(),syncTime.created());
            }
            ret = deviceMg.GetCapabilities(&reqGetCapabilities,&resGetCapabilities);
            if(ret != SOAP_OK)
            {
                return;
            }
            mediaMg.soap_endpoint = resGetCapabilities.Capabilities->Media->XAddr;
        }
        {
            if(urlInfo.user != "none" && urlInfo.passWord != "none")
            {
                soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",tempUser.c_str(),tempPass.c_str(),syncTime.created());
            }
            ret = deviceMg.GetNetworkProtocols(&reqGetNetworkProtocols,&resGetNetworkProtocols);
            if(ret != SOAP_OK)
            {
                return;
            }
        }

        {
            tt__StreamSetup StreamSetup;
            tt__Transport Transport;
            tt__MediaUri *mediaUri;
            if(urlInfo.user != "none" && urlInfo.passWord != "none")
            {
                soap_wsse_add_UsernameTokenDigestCreated((soap *)&mediaMg, "User",tempUser.c_str(),tempPass.c_str(),syncTime.created());
            }
            ret = mediaMg.GetProfiles(&reqGetProfiles,&resGetProfilesResponse);
            if(ret != SOAP_OK)
            {
                return;
            }
            tt__Profile **Profile = resGetProfilesResponse.Profiles;
            if(resGetProfilesResponse.__sizeProfiles == 1)
            {

                reqGetStreamUri.ProfileToken = (*Profile)->token;
            }
            else
            {
                reqGetStreamUri.ProfileToken = Profile[0]->token;
            }


//            reqGetStreamUri.StreamSetup = &StreamSetup;
//            StreamSetup.Transport = &Transport;
//            StreamSetup.Stream = tt__StreamType__RTP_Unicast;
//            Transport.Protocol = tt__TransportProtocol__RTSP;

            reqGetStreamUri.StreamSetup = &StreamSetup;
            StreamSetup.Transport = NULL;
            StreamSetup.Stream = tt__StreamType__RTP_Multicast;
            //Transport.Protocol = tt__TransportProtocol__RTSP;
            if(ret != SOAP_OK)
            {
                return;
            }
            if(urlInfo.user != "none" && urlInfo.passWord != "none")
            {
                soap_wsse_add_UsernameTokenDigestCreated((soap *)&mediaMg, "User",tempUser.c_str(),tempPass.c_str(),syncTime.created());
            }

            ret = mediaMg.GetStreamUri(&reqGetStreamUri,&resGetStreamUriResponse);
            if(ret != SOAP_OK)
            {
                return;
            }
            mediaUri = resGetStreamUriResponse.MediaUri;
            if(urlInfo.user != "none" && urlInfo.passWord != "none")
            {//rtsp://user:pass@192.168.9.63/onvif-media/medi
                localUrl.sprintf("%s//%s:%s@%s","rtsp:",tempUser.c_str(),tempPass.c_str(),mediaUri->Uri+7);
            }
            else
                localUrl = mediaUri->Uri;
            //cout<<mediaUri->Uri<<endl;

        }
    }
    else if(urlInfo.type == "rtsp")
    {
        localUrl = devUrl;
    }
    else
    {
        localUrl = devUrl;
    }
    emit setPlayUrl(localUrl);

#endif

}
int picWindow::PlayStream(QString url)
{
    this->url = url;
    videoThread.setPlayRef(this);
    recvThread.setPlayRef(this);
    recvThread.start();
    videoThread.start();
}
void picWindow::stopPlay()
{
    releaseCurSrc(NULL);
}
void picWindow::showNewImage(QImage CurImg)
{
    Pic = CurImg;
    update();
}
void picWindow::showNewImage(IplImage *img)
{
    curIplImage = img;
    update();
}
int picWindow::initPlayCodec(/*QString url*/)
{
#if CONFIG_AVDEVICE
    avdevice_register_all();
#endif
#if CONFIG_AVFILTER
    avfilter_register_all();
#endif
    av_register_all();
    avformat_network_init();


    pFormatCtx = avformat_alloc_context();

    av_dict_set(&format_opts, "rtsp_transport", "tcp", 0);

    err = avformat_open_input(&pFormatCtx, url.toLatin1(), NULL, &format_opts);
    if (err < 0) {
       return -1;
    }
    err = avformat_find_stream_info(pFormatCtx, NULL);
    if(err < 0)
      return -1;

    for(int i=0; i < pFormatCtx->nb_streams; i++) {
      if(pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO &&video_index < 0) {
        video_index=i;
      }
      if(pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_AUDIO &&audio_index < 0) {
        audio_index=i;
      }
    }

    if(audio_index >= 0)
    {
        openAudioComp(pFormatCtx, audio_index);
    }
    if(video_index >= 0)
    {
        openVideoComp(pFormatCtx, video_index);
    }
}

int picWindow::openAudioComp(AVFormatContext *pFormatCtx, int stream_index)
{
    //    AVCodec *codec = NULL;
    //    pAudiocodecCtx = pFormatCtx->streams[stream_index]->codec;
    //    codec = avcodec_find_decoder(pAudiocodecCtx->codec_id);
    //    if(!codec || (avcodec_open(pAudiocodecCtx, codec) < 0)) {
    //      fprintf(stderr, "Unsupported codec!\n");
    //      return -1;
    //    }

    //    return 0;
}
int picWindow::openVideoComp(AVFormatContext *pFormatCtx, int stream_index)
{
    AVCodec * codec = NULL;
    pVideocodecCtx = pFormatCtx->streams[stream_index]->codec;
    codec = avcodec_find_decoder(pVideocodecCtx->codec_id);
    pVideocodecCtx->codec_id = codec->id;
    avcodec_open2(pVideocodecCtx, codec,NULL);
}
void picWindow::paintEvent(QPaintEvent */*event*/)
{
    QPainter widgetPaint(this);
    widgetPaint.eraseRect(rect());

    winH = 0,winW = 0,startX = 0,startY = 0;
    if(Pic.width()*1.0/Pic.height() >= width()*1.0/height())
    {
        winW = width();
        winH = width()*Pic.height()*1.0/Pic.width();
        startX = 0;
        startY = (height() - winH) / 2;
    }
    else
    {
        winW = height()*Pic.width()*1.0/Pic.height();
        winH = height();
        startX = (width()-winW)/2;
        startY = 0;
    }
    widgetPaint.setViewport(startX,startY,winW,winH);
    widgetPaint.setWindow(0, 0, Pic.width(), Pic.height());
    widgetPaint.drawImage(0,0,Pic);
}
void picWindow::setNoVideoRef(QString url)
{
    Pic.load(url);
    //update();
}
void picWindow::dragEnterEvent(QDragEnterEvent *event)
{
//    QListWidget *source = qobject_cast<QListWidget *>(event->source());
    /*if (source && source != this)*/ {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}
void picWindow::dropEvent(QDropEvent *event)
{
    QString devInfo = event->mimeData()->text();
    urlInfo.type = devInfo.section('\n', 0, 0);
    urlInfo.url  = devInfo.section('\n',1,1);
    urlInfo.user = devInfo.section('\n',2,2);
    urlInfo.passWord = devInfo.section('\n',3,3);
    event->setDropAction(Qt::MoveAction);
    event->accept();
    startPlay();

}
void picWindow::focusInEvent(QFocusEvent *event)
{

}
RecvThread::RecvThread(QObject *parent) :
    QThread(parent)
{
    stopped = false;
}
void RecvThread::setPlayRef(picWindow *window)
{
    this->win = window;
}
void RecvThread::run()
{
    int ret = -1;
    AVPacket pkt1, *packet = &pkt1;
    ret = win->initPlayCodec();
    if(ret < 0)
    {
        win->releaseCurSrc(NULL);
        return;
    }
    while(!stopped)
    {
        ret = av_read_frame(win->pFormatCtx, packet);
        if(ret < 0)
        {
            Sleep(5);
            continue;
        }
        if(packet->stream_index == win->video_index)
        {
          win->videoPacketList.append(pkt1);
        }
        else if(packet->stream_index == win->audio_index)
        {
          win->audioPacketList.append(pkt1);
        }
        else
        {
          av_free_packet(packet);
          free(packet);
        }
        Sleep(3);
    }
    Sleep(10);
    while(win->videoPacketList.count() > 0)
    {
        pkt1 = win->videoPacketList.first();
        av_free_packet(&pkt1);
        win->videoPacketList.removeFirst();
    }

    stopped = false;
    return;
}
void RecvThread::stop()
{
    stopped = true;
}
VideoDecoderTherad::VideoDecoderTherad(QObject *parent) :
    QThread(parent)
{
    stopped = false;
}
void VideoDecoderTherad::setPlayRef(picWindow *window)
{
    this->win = window;
}
void VideoDecoderTherad::run()
{
    AVCodecContext *pCodecContext = win->pVideocodecCtx;
    AVFrame *pFrame = avcodec_alloc_frame();;
    struct SwsContext *pSwsContext = NULL;
    AVFrame *pFrameRGB = NULL;
    unsigned char *rgbBuf = NULL;
    IplImage *ptImage = NULL;
    IplImage *ptImageShow = NULL;
    unsigned int rgbBufSize = 0;
    AVPacket packet;
    while(!stopped)
    {

        int frameFinished = 0;
        int length = 0;
        if(win->videoPacketList.count() > 1)
        {
            packet = win->videoPacketList.first();
            if(pCodecContext == NULL)
            {
                pCodecContext = win->pVideocodecCtx;
            }
            length = avcodec_decode_video2(pCodecContext, pFrame, &frameFinished,&packet);
            if(length > 0)//PIX_FMT_BGR24 PIX_FMT_RGB24
            {
                if(pSwsContext == NULL)
                {
                    pSwsContext =
                            sws_getContext(pCodecContext->width,pCodecContext->height,pCodecContext->pix_fmt,
                                           pCodecContext->width,pCodecContext->height,PIX_FMT_RGB24,
                                           SWS_BICUBIC,NULL, NULL, NULL);
                    if(pFrameRGB == NULL)
                    {
                        pFrameRGB = avcodec_alloc_frame();
                        if(pFrameRGB == NULL)
                        {
                            return ;
                        }
                        rgbBufSize = avpicture_get_size(PIX_FMT_RGB24,pCodecContext->width,pCodecContext->height);
                        rgbBuf=(uint8_t *)av_malloc(rgbBufSize*sizeof(uint8_t));
                        avpicture_fill((AVPicture *)pFrameRGB, rgbBuf, PIX_FMT_RGB24,pCodecContext->width, pCodecContext->height);
                    }
                }
                sws_scale(pSwsContext, pFrame->data, pFrame->linesize, 0, pCodecContext->height,pFrameRGB->data, pFrameRGB->linesize);
                if(ptImage == NULL)
                {
                    ptImage = cvCreateImageHeader(cvSize(pCodecContext->width,pCodecContext->height),IPL_DEPTH_8U,3);
                }
                ptImage->imageData = (char*)pFrameRGB->data[0];
                ptImage->widthStep = pFrameRGB->linesize[0];

                emit genNewImg(QImage((uchar *)ptImage->imageData,ptImage->width,ptImage->height,QImage::Format_RGB888));
            }
            av_free_packet(&packet);
            win->videoPacketList.removeFirst();
            cvWaitKey(1);
        }
        else
        {
            Sleep(40);
        }
        Sleep(20);
    }
    Sleep(10);
    cvReleaseImageHeader(&ptImage);
    av_free(rgbBuf);
    av_free(pFrameRGB);
    av_free(pFrame);
    stopped = false;
    return;
}


void VideoDecoderTherad::stop()
{
    stopped = true;
}
