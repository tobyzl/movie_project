#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#define WIN32DLL

#include <QMainWindow>
#include "mp4.h"
#include "SE_VideoCodec.h"

#include <qmediaplayer.h>
#include <QtGui/QMovie>
#include <QtWidgets/QWidget>

class VideoPlayer : public QWidget
{
    Q_OBJECT
public:
    VideoPlayer(QWidget *parent = 0);
    ~VideoPlayer();

public slots:
    void setMedia(QString filename);
    void play();

private slots:


private:
    QString m_filename;

};

#endif
