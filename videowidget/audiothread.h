#ifndef AUDIOTHREAD_H
#define AUDIOTHREAD_H

#include <QThread>
#include <QImage>
#include <QDebug>
#include <QFile>

class AudioThread : public QThread
{
    Q_OBJECT
public:
    explicit AudioThread();
    ~AudioThread();

    void startPlay(QString filename);

signals:
    void sig_GetOneFrame(QImage); //每获取到一帧图像 就发送此信号

private:
    void run();
    QString mfilename;

};

#endif // AUDIOTHREAD_H
