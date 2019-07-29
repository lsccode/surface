#include "commonDef.h"

ComboBoxUrl::ComboBoxUrl(QWidget *parent = 0):QComboBox(parent)
{

}
void ComboBoxUrl::addNewItemStHdl(QString type, QString url)
{
    QVariant variant;
    variant.setValue(UrlInfo(type,url,"none","none"));
    addItem(url,variant);
}
void ComboBoxUrl::clearItemStHdl()
{
    clear();
}
void ComboBoxUrl::modItemStHdl(UrlInfo info)
{
    int index = findText(info.url);
    if(index != -1)
    {
        QVariant variant;
        variant.setValue(info);
        setItemData(index,variant);
    }
}
TimeDateUser::TimeDateUser()
{
    year = 0;
    month = 0;
    day = 0;
    hour =0;
    minute = 0;
    second = 0;
    msecond = 0;
    start.tv_sec = 0;
    start.tv_usec = 0;
    end.tv_sec = 0;
    end.tv_usec = 0;
}
TimeDateUser::TimeDateUser(int ye, int mo, int da, int ho, int mi, int se, int ms)
{
    setTimeDate(ye,mo,da,ho,mi,se,ms);
}
void TimeDateUser::setTimeDate(int ye, int mo, int da, int ho, int mi, int se, int ms)
{
    year = ye;
    month = mo;
    day = da;
    hour =ho;
    minute = mi;
    second = se;
    msecond = ms;
    gettimeofday(&start,NULL);
}
char *TimeDateUser::created()
{
    int diff_mi;
    int diff_se;
    int diff_ms;
    unsigned long long diffmse;
    static char buf[32];
    gettimeofday(&end,NULL);
    memset(buf,0,sizeof(buf));
    diffmse = (end.tv_sec - start.tv_sec)*1000 + (end.tv_usec - start.tv_usec)/1000;
    diff_mi = diffmse/(60*1000);
    diff_se = (diffmse/1000)%60;
    diff_ms = diffmse%1000;
    sprintf(buf,"%4d-%02d-%02dT%02d:%02d:%02d.%03dZ",year,month,day,hour,minute+diff_mi,second+diff_se,msecond+diff_ms);
    return buf;
}
