#ifndef MOVIEPLAYER_H
#define MOVIEPLAYER_H

#define WIN32DLL

#include <QMainWindow>
#include "mp4.h"
#include "SE_VideoCodec.h"


#include <QMainWindow>
#include <QPushButton>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFile>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTextCodec>
#include <QUrl>
#include <QEvent>
#include <QFileInfo>
#include <QIODevice>
#include <QLineEdit>
#include "thread.h"
#include "showmovie.h"

namespace Ui {
class movieplayer;
}

class movieplayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit movieplayer(QWidget *parent = 0);
    ~movieplayer();

    void webView();
        void startRequest(QUrl url); // 请求链接
        QUrl returnQUrl() { return url;}
    protected:
       void playMovie();

    signals:
        void urlSignal(QString str);
    public slots:
        void loadAndPlayMovie();
        void browseFile();
    private:
        MyThread *myThread;
        QNetworkAccessManager *manager;
        QUrl url;
        QFile *file;
        QLineEdit *lineEdit;
        ShowMovieWidget *videoWidget;
        Ui::movieplayer *ui;
        QPushButton *pushButton;
};

#endif // MOVIEPLAYER_H
