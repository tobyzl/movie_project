#include "mp4player.h"
#include <QtWidgets>

MP4Player::MP4Player(QWidget *parent)
    : QWidget(parent)
    , playButton(0)
    , positionSlider(0)
    , lineEdit(0)
    , m_lab_show(0)
    , mThread(0)
    , mImage(0)
    , isplay(true)
{
    QAbstractButton *searchButton = new QPushButton(tr("Open..."));
    connect(searchButton, SIGNAL(clicked()), this, SLOT(openFile()));

    playButton = new QPushButton;
    isplay = true;
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    connect(playButton, SIGNAL(clicked()), this, SLOT(mediaStateChanged()));

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


    mThread = new VideoThread;
    connect(mThread,SIGNAL(sig_sentOneFrame(QImage)),this,SLOT(slotGetOneFrame(QImage)));

    connect(mThread, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    connect(mThread, SIGNAL(durationChanged(qint64)), this, SLOT(durationChanged(qint64)));
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

}

void MP4Player::mediaStateChanged()
{
    if (isplay)
    {
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        isplay = false;
    }
    else
    {
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        isplay = true;
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

}

