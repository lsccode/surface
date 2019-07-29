#include "discoverybasic.h"

DisCoveryBasic::DisCoveryBasic(QObject *parent):QObject(parent)
{

}
OnvifDisImp::OnvifDisImp(QObject *parent):DisCoveryBasic(parent)
{

}
void OnvifDisImp::start()
{
//    int ret = 0;
//    wsddProxy myProxy;
//    myProxy.soap_header_init(const_cast<char *>(soap_wsa_rand_uuid((soap *)&myProxy)));

//    wsdd__ProbeType wsdd__Probe = {0};
//    __wsdd__ProbeMatches wsdd_ProbeMatchs = {0};
//    ret = myProxy.send_Probe(&wsdd__Probe);
//    if(ret < 0)
//    {
//        printf("ret = %d\n",ret);
//    }
//    myProxy.recv_timeout = 5;
//    listWidget->clear();
//    while(1)
//    {
//        QString newStrUrl;
//        ret = myProxy.recv_ProbeMatches(wsdd_ProbeMatchs);
//        if(ret != SOAP_OK)
//        {
//            break;
//        }
//        if(wsdd_ProbeMatchs.wsdd__ProbeMatches != NULL)
//        {
//            for(int i = 0;i < wsdd_ProbeMatchs.wsdd__ProbeMatches->__sizeProbeMatch;++i)
//            {
//               // cout << "addr = "<<wsdd_ProbeMatchs.wsdd__ProbeMatches->ProbeMatch[i].XAddrs<<endl;
//                newStrUrl.sprintf("%s\n%s","onvif",wsdd_ProbeMatchs.wsdd__ProbeMatches->ProbeMatch[i].XAddrs);
//                listWidget->addItem(newStrUrl);
//            }
//        }
//    }

}
