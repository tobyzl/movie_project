#ifndef VIDEOETHREAD_H
#define VIDEOETHREAD_H

#define WIN32DLL
#define NBUFMAXSIZE 393216

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
    void decode(UCHAR *pBuf, unsigned long len);

signals:
    void sig_sentOneFrame(QImage); //每获取到一帧图像 就发送此信号
    void positionChanged(qint64);
    void durationChanged(qint64);

private:
    QString m_filename;
    QImage image;

};

#endif // VIDEOETHREAD_H
