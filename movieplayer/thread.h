#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QDebug>
#include <QUrl>
#include <QMediaPlayer>
#include <QVideoWidget>
#include "showmovie.h"
#include <QFileInfo>

class MyThread : public QThread {
    Q_OBJECT
public:
    MyThread(QObject *parent=0);
    ~MyThread();

protected:
    void run();
signals:
    void updateSignal(int num);
public slots:
        void urlSlot(QString str);

private:
    int number;
    //QUrl url;
};

#endif // THREAD_H
