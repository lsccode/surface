greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
ROOT_PATH = $$_PRO_FILE_
TEMPLATE      = app
HEADERS += \
    include/common/mainwindow.h \
    script/isp_common/ispcommon.h \
    script/isp_common/ispcminputport.h \
    script/isp_common/ispcmglobal.h \
    script/isp_pingpong/ispppca_correction.h \
    script/isp_pingpong/ispppccm.h \
    script/isp_pingpong/ispppcnr.h \
    script/isp_pingpong/ispppdemosaic_rgbir.h \
    script/isp_pingpong/ispppframe_stitch.h \
    script/isp_pingpong/ispppinput_formatter.h \
    script/isp_pingpong/ispppmesh_shading.h \
    script/isp_pingpong/ispppmetering_af.h \
    script/isp_pingpong/ispppmetering_awb.h \
    script/isp_pingpong/ispppmetering_ihist.h \
    script/isp_pingpong/ispppradial_shading.h \
    script/isp_pingpong/ispppraw_frontend.h \
    script/isp_pingpong/ispppsensor_offset.h \
    script/isp_pingpong/ispppsinter.h \
    script/isp_pingpong/isppptemper.h \
    script/isp_pingpong/isppptop.h \
    script/isp_pingpong/ispppwhite_balance_aexp.h \
    script/isp_pingpong/isppingpongfrag1.h \
    script/isp_pingpong/isppingpongfrag2.h \
    script/isp_pingpong/isppingpongfrag3.h \
    script/isp_pingpong/ispppdecompander.h \
    script/isp_pingpong/ispppds_config.h \
    script/isp_pingpong/ispppfr_config.h \
    script/isp_pingpong/ispppmisc.h \
    script/isp_pingpong/ispppmetering.h \
    script/ispcommonstep.h

SOURCES += \
    src/common/main.cpp \
    src/common/mainwindow.cpp \
    script/isp_common/ispcommon.cpp \
    script/isp_common/ispcminputport.cpp \
    script/isp_common/ispcmglobal.cpp \
    script/isp_pingpong/ispppca_correction.cpp \
    script/isp_pingpong/ispppccm.cpp \
    script/isp_pingpong/ispppcnr.cpp \
    script/isp_pingpong/ispppdemosaic_rgbir.cpp \
    script/isp_pingpong/ispppframe_stitch.cpp \
    script/isp_pingpong/ispppinput_formatter.cpp \
    script/isp_pingpong/ispppmesh_shading.cpp \
    script/isp_pingpong/ispppmetering_af.cpp \
    script/isp_pingpong/ispppmetering_awb.cpp \
    script/isp_pingpong/ispppmetering_ihist.cpp \
    script/isp_pingpong/ispppradial_shading.cpp \
    script/isp_pingpong/ispppraw_frontend.cpp \
    script/isp_pingpong/ispppsensor_offset.cpp \
    script/isp_pingpong/ispppsinter.cpp \
    script/isp_pingpong/isppptemper.cpp \
    script/isp_pingpong/isppptop.cpp \
    script/isp_pingpong/ispppwhite_balance_aexp.cpp \
    script/isp_pingpong/isppingpongfrag1.cpp \
    script/isp_pingpong/isppingpongfrag2.cpp \
    script/isp_pingpong/isppingpongfrag3.cpp \
    script/isp_pingpong/ispppdecompander.cpp \
    script/isp_pingpong/ispppds_config.cpp \
    script/isp_pingpong/ispppfr_config.cpp \
    script/isp_pingpong/ispppmisc.cpp \
    script/isp_pingpong/ispppmetering.cpp \
    script/ispcommonstep.cpp

INCLUDEPATH += \
    include/common \
LIBS += -lpthread

#LIBS += -lws2_32 -lkernel32 -luser32 -lgdi32 -lm -lz

RESOURCES += \
    res/surfaceRef.qrc
#QMAKE_CXXFLAGS += -D__STDC_CONSTANT_MACROS
#QMAKE_CXXFLAGS += -DWITH_DOM -DWITH_OPENSSL -DWITH_GZIP  -g -fpermissive

OTHER_FILES +=

