#include "thread.h"

MyThread::MyThread(QObject *parent)
{
   number = 0;
}

MyThread::~MyThread()
{

}

void MyThread::run()
{

}

void MyThread::urlSlot(QString url)
{
    QFileInfo *fileInfo = new QFileInfo(url);
    ShowMovieWidget *videoWidget = new ShowMovieWidget;
    QVideoWidget *playMovie = videoWidget->playMovieWidget;

    videoWidget->player->setVideoOutput(playMovie);
    videoWidget->player->setMedia(QUrl(url));
    videoWidget->setWindowTitle(fileInfo->fileName());
    videoWidget->resize(822, 500);
    videoWidget->show();
    videoWidget->player->play();
}
