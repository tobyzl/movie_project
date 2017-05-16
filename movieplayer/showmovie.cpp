#include "showmovie.h"
#include <QtWidgets>
#include <QtWinExtras>

ShowMovieWidget::ShowMovieWidget(QWidget *parent) : QWidget(parent),
    player(0), playButton(0), positionSlider(0), positionLabel(0), playMovieWidget(0)
{
    playMovieWidget = new QVideoWidget;
    player = new QMediaPlayer;

   createWidgets();
   connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(updateState(QMediaPlayer::State)));
   connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(updatePosition(qint64)));
   connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(updateDuration(qint64)));
}


void ShowMovieWidget::createWidgets()
{
    playButton = new QToolButton(this);
    playButton->setToolTip(tr("Play"));
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    connect(playButton, SIGNAL(clicked()), this, SLOT(togglePlayback()));

    positionSlider = new QSlider(Qt::Horizontal, this);
    positionSlider->setToolTip(tr("Seek"));
    connect(positionSlider, SIGNAL(valueChanged(int)), this, SLOT(setPosition(int)));

    positionLabel = new QLabel(tr("00:00"), this);
    positionLabel->setMinimumWidth(positionLabel->sizeHint().width());

    qint64 totalposition = player->duration();
    QTime totalduration(0, totalposition / 60000, qRound((totalposition % 60000) / 1000.0));
    positionLabel->setText(totalduration.toString(tr("mm:ss")));

    QBoxLayout *controlLayout = new QHBoxLayout;
    controlLayout->setMargin(0);
    controlLayout->addWidget(playButton);
    controlLayout->addWidget(positionLabel);
    controlLayout->addWidget(positionSlider);

    QBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(playMovieWidget);
    mainLayout->addLayout(controlLayout);
}

void ShowMovieWidget::togglePlayback() {
   if (player->state() == QMediaPlayer::PlayingState) {
        player->pause();
    } else {
        player->play();
    }
}

void ShowMovieWidget::updateState(QMediaPlayer::State state)
{
    if (state == QMediaPlayer::PlayingState) {
        playButton->setToolTip(tr("Pause"));
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    } else {
        playButton->setToolTip(tr("Play"));
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}

void ShowMovieWidget::seekForward()
{
    positionSlider->triggerAction(QSlider::SliderPageStepAdd);
}

void ShowMovieWidget::seekBackward()
{
    positionSlider->triggerAction(QSlider::SliderPageStepSub);
}

void ShowMovieWidget::updatePosition(qint64 position)
{
    positionSlider->setValue(position);

    QTime duration(0, position / 60000, qRound((position % 60000) / 1000.0));
    positionLabel->setText(duration.toString(tr("mm:ss")));
}

void ShowMovieWidget::updateDuration(qint64 duration)
{
    positionSlider->setRange(0, duration);
    positionSlider->setEnabled(duration > 0);
    positionSlider->setPageStep(duration / 10);
}

void ShowMovieWidget::setPosition(int position) {
    // avoid seeking when the slider value change is triggered from updatePosition()
    if (qAbs(player->position() - position) > 99) {
        player->setPosition(position);
    }
}
