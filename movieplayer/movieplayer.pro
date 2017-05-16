#-------------------------------------------------
#
# Project created by QtCreator 2017-05-16T08:45:27
#
#-------------------------------------------------

QT       += core gui multimedia winextras multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = movieplayer
TEMPLATE = app


SOURCES += main.cpp\
        movieplayer.cpp \
    showmovie.cpp \
    thread.cpp

LIBS += -LF:\Movie\Qt_MP4\lib\lib -lSE_AudioCodec -lSE_MP4 -lSE_VideoCodec

win32{

}

#头文件包含路�
INCLUDEPATH += ../Qt_MP4/lib/includ

HEADERS  += movieplayer.h \
    showmovie.h \
    thread.h

FORMS    += movieplayer.ui
