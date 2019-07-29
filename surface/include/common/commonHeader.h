#ifndef COMMONHEADER_H
#define COMMONHEADER_H
//#include "commonHeader.h"

#include <QApplication>
#include <QtGui>



#include <QApplication>
#include <QtGui>
#include <QAction>
#include <QActionGroup>
#include <QCheckBox>
#include <QColor>
#include <QColorDialog>
#include <QComboBox>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QFont>
#include <QFontMetricsF>
#include <QGroupBox>
#include <QGridLayout>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QHBoxLayout>
#include <QLine>
#include <QHeaderView>
#include <QInputDialog>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMap>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QPixmap>
#include <QPainterPath>
#include <QPushButton>
#include <QRadioButton>
#include <QStackedLayout>
#include <QStackedWidget>
#include <QStylePainter>
#include <QStyleOptionFocusRect>
#include <QSplitter>
#include <QStatusBar>
#include <QSpinBox>
#include <QScrollBar>
#include <QSlider>
#include <QToolButton>
#include <QToolBar>
#include <QTableWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QVector>
#include <QWidget>
//#include <QWebView>
 //#include <QWebView>


//other include
#include <cmath>
#ifdef __cplusplus
extern "C"
{
#endif

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/avutil.h>
#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include "libavutil/avstring.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "libavutil/dict.h"
#include "libavutil/parseutils.h"
#include "libavutil/samplefmt.h"
#include "libavutil/avassert.h"
#include "libavformat/avformat.h"
#include "libavdevice/avdevice.h"
#include "libswscale/swscale.h"
#include "libavutil/opt.h"
#include "libavcodec/avfft.h"

#if CONFIG_AVFILTER
# include "libavfilter/avcodec.h"
# include "libavfilter/avfilter.h"
# include "libavfilter/avfiltergraph.h"
# include "libavfilter/vsink_buffer.h"
#endif
#ifdef __cplusplus
}
#endif

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "nvtwsddProxy.h"
#include "nvtDeviceBindingProxy.h"
#include "nvtMediaBindingProxy.h"
#include "nvtNotificationProducerBindingProxy.h"
#include "nvtNotificationConsumerBindingService.h"
#include "wsaapi.h"
#include "wsseapi.h"

#endif // COMMONHEADER_H
