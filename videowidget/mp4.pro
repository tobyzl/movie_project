TEMPLATE = app
TARGET = mp4player

QT += multimedia multimediawidgets core widgets

INCLUDEPATH += ../Qt_MP4/lib/includ

LIBS += -L../Qt_MP4/lib/lib/ -lSE_MP4 -lSE_AudioCodec -lSE_VideoCodec

HEADERS = \
    mp4player.h \
    videothread.h

SOURCES = \
    main.cpp \
    mp4player.cpp \
    videothread.cpp

