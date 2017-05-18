#include "mp4player.h"
#include <QtWidgets>
#include <qvideowidget.h>
#include <qvideosurfaceformat.h>

MP4Player::MP4Player(QWidget *parent)
    : QWidget(parent)
    , mediaPlayer(0, QMediaPlayer::VideoSurface)
    , playButton(0)
    , positionSlider(0)
{
    QVideoWidget *videoWidget = new QVideoWidget;

    QAbstractButton *searchButton = new QPushButton(tr("Open..."));
    connect(searchButton, SIGNAL(clicked()), this, SLOT(openFile()));

    playButton = new QPushButton;
    playButton->setEnabled(false);
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    connect(playButton, SIGNAL(clicked()),
            this, SLOT(play()));

    positionSlider = new QSlider(Qt::Horizontal);
    positionSlider->setRange(0, 0);

    connect(positionSlider, SIGNAL(sliderMoved(int)),
            this, SLOT(setPosition(int)));

    lineEdit = new QLineEdit;
    m_lab_show = new QLabel;

    QBoxLayout *controlLayout = new QHBoxLayout;
    controlLayout->setMargin(0);
    controlLayout->addWidget(playButton);
    controlLayout->addWidget(positionSlider);

    QBoxLayout *searchLayout = new QHBoxLayout;
    searchLayout->addWidget(lineEdit);
    searchLayout->addWidget(searchButton);

    QBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_lab_show);
    layout->addLayout(controlLayout);
    layout->addLayout(searchLayout);

    setLayout(layout);

    mediaPlayer.setVideoOutput(videoWidget);
    connect(&mediaPlayer, SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SLOT(mediaStateChanged(QMediaPlayer::State)));
    connect(&mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    connect(&mediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(durationChanged(qint64)));

    mThread = new VideoThread;
    connect(mThread,SIGNAL(sig_sentOneFrame(QImage)),this,SLOT(slotGetOneFrame(QImage)));

}

MP4Player::~MP4Player()
{
}

void MP4Player::slotGetOneFrame(QImage img)
{
    mImage = img;
    repaint();
}

void MP4Player::paintEvent(QPaintEvent *event)
{
    QPixmap pixmap = QPixmap::fromImage(mImage.scaled(m_lab_show->size(), Qt::KeepAspectRatio) );
    m_lab_show->setPixmap(pixmap);

}


void MP4Player::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"),QDir::homePath());

    if (!fileName.isEmpty()) {
        lineEdit->setText(fileName);

        mThread->startPlay(fileName);
        mThread->play();

        playButton->setEnabled(true);
    }
}

void MP4Player::play()
{
    switch(mediaPlayer.state()) {
    case QMediaPlayer::PlayingState:
     // mediaPlayer.pause();
        break;
    default:
    //  mediaPlayer.play();
        break;
    }
}

void MP4Player::mediaStateChanged(QMediaPlayer::State state)
{
    switch(state) {
    case QMediaPlayer::PlayingState:
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        break;
    default:
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        break;
    }
}

void MP4Player::positionChanged(qint64 position)
{
    positionSlider->setValue(position);
}

void MP4Player::durationChanged(qint64 duration)
{
    positionSlider->setRange(0, duration);
}

void MP4Player::setPosition(int position)
{
    mediaPlayer.setPosition(position);
}

