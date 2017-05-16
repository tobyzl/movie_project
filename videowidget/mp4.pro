TEMPLATE = app
TARGET = mp4player

QT += multimedia multimediawidgets core widgets

INCLUDEPATH += ../Qt_MP4/lib/includ

LIBS += -L../Qt_MP4/lib/lib/ -lSE_MP4 -lSE_AudioCodec -lSE_VideoCodec

HEADERS = \
    videoplayer.h \
    mp4player.h

SOURCES = \
    main.cpp \
    videoplayer.cpp \
    mp4player.cpp

