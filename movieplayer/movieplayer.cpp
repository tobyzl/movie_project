#include "movieplayer.h"
#include "ui_movieplayer.h"
#include <QHBoxLayout>
#include <QFileDialog>
#include <QDebug>

movieplayer::movieplayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::movieplayer)
{
    ui->setupUi(this);

    pushButton = new QPushButton(tr("browse..."));
    connect(pushButton, SIGNAL(clicked()), this, SLOT(browseFile()));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(pushButton);
    setLayout(layout);

    /*
    myThread = new MyThread;
        myThread->start();


        videoWidget = new ShowMovieWidget;
        QVideoWidget *playMovie = videoWidget->playMovieWidget;
        videoWidget->player->setVideoOutput(playMovie);
        videoWidget->player->setMedia(QUrl::fromLocalFile("F:/Qt_MP4/data/test.mp4"));
        videoWidget->resize(822, 500);
        videoWidget->show();
        videoWidget->player->play();




        connect(this, SIGNAL(urlSignal(QString)), myThread, SLOT(urlSlot(QString)));
        manager = new QNetworkAccessManager(this);
        pushButton = new QPushButton("movie");
        connect(pushButton, SIGNAL(clicked()), this, SLOT(loadAndPlayMovie()));
        statusBar()->addPermanentWidget(pushButton);
        */
}

movieplayer::~movieplayer()
{
    delete ui;
}

void movieplayer::browseFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"),QDir::homePath());

    qDebug() << "browseFile" << endl;
    if (!fileName.isEmpty()) {
        lineEdit->setText(fileName);
    }
}



void movieplayer::loadAndPlayMovie() {
   /* QString urlStr = ui->lineEdit->text();

    url = ui->lineEdit->text();
    QFileInfo info(url.path());
    QString fileName(info.fileName());

    QFile *loacalFile = new QFile(fileName);
    if (!loacalFile->open(QIODevice::ReadOnly)) {
        delete loacalFile;
        loacalFile = NULL;
        emit urlSignal(urlStr);
    } else {
        playMovie();
    }*/
}


void movieplayer::playMovie() {
    /*
    videoWidget = new ShowMovieWidget;

    QVideoWidget *playMovie = videoWidget->playMovieWidget;
    videoWidget->player->setVideoOutput(playMovie);

    url = ui->lineEdit->text();
    QFileInfo info(url.path());
    QString fileName(info.fileName());

    videoWidget->player->setMedia(QUrl::fromLocalFile(fileName));
    videoWidget->setWindowTitle(fileName);
    videoWidget->resize(822, 500);
    videoWidget->show();
    videoWidget->player->play();
    */
}







