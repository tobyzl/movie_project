#ifndef VIDEOETHREAD_H
#define VIDEOETHREAD_H

#define WIN32DLL
#define NBUFMAXSIZE 384 * 1024

#include "mp4.h"
#include "SE_VideoCodec.h"
#include <QtWidgets/QWidget>
#include <QThread>
#include <QImage>
#include <QFile>
#include <QDebug>

class VideoThread : public QThread
{
    Q_OBJECT

public:
    explicit VideoThread();
    ~VideoThread();

    void startPlay(QString infile);
    void play();
    void decode(UCHAR *pBuf);

signals:
    void sig_sentOneFrame(QImage); //每获取到一帧图像 就发送此信号

private:
    QString m_filename;

};

#endif // VIDEOETHREAD_H
