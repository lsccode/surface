#ifndef PICWINDOW_H
#define PICWINDOW_H
#include "commonHeader.h"
#include "commonDef.h"
class picWindow;
class VideoDecoderTherad : public QThread
{
    Q_OBJECT
public:
    explicit VideoDecoderTherad(QObject *parent = 0);
    void setPlayRef(picWindow *window);
    void stop();
protected:
    void run();
private:
    volatile bool stopped;
    picWindow *win;
signals:
    void genNewImg(QImage img);
    void genNewImg(IplImage *img);
    void genNewImg(QPixmap pixmap);
public slots:


};
class RecvThread : public QThread
{
    Q_OBJECT
public:
    explicit RecvThread(QObject *parent = 0);
    void setPlayRef(picWindow *window);
    void stop();
protected:
    void run();

private:
    volatile bool stopped;
    picWindow *win;
signals:

public slots:

};
class picWindow : public QWidget
{
    Q_OBJECT
public:
    picWindow();
    IplImage *ptImage;
    AVFormatContext *pFormatCtx;
    AVCodecContext *pVideocodecCtx;
    AVCodecContext *pAudiocodecCtx;
    AVDictionary *format_opts;
    int initPlayCodec();
    int openAudioComp(AVFormatContext *pFormatCtx,int stream_index);
    int openVideoComp(AVFormatContext *pFormatCtx,int stream_index);
    void setNoVideoRef(QString url);
    QLinkedList<AVPacket> videoPacketList;
    QLinkedList<AVPacket> audioPacketList;
    int err;
    int video_index;
    int audio_index;
    QImage Pic;
    VideoDecoderTherad videoThread;
    RecvThread          recvThread;
    QString devUrl;
    QString devType;
    UrlInfo urlInfo;
    int winH;
    int winW;
    int startX;
    int startY;
    IplImage *curIplImage;
    void releaseCurSrc(QCloseEvent *event);
protected:
    void paintEvent(QPaintEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void draw(QPainter *painter);
    void focusInEvent(QFocusEvent *event);
protected:
    void closeEvent(QCloseEvent *event);
public slots:
    void showNewImage(QImage CurImg);
    void showNewImage(IplImage *img);
    void startPlay();
    void stopPlay();
private:
    QAction *startAction;
    QAction *stopAction;
private slots:
    //void Menu1Act1Handle();
    int PlayStream(QString url);

signals:
    int setPlayUrl(QString url);
private:
    QString url;
};

#endif // PICWINDOW_H
