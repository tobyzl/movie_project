#ifndef SHOWMOVIE_H
#define SHOWMOVIE_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>

QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QSlider)
QT_FORWARD_DECLARE_CLASS(QAbstractButton)

class ShowMovieWidget : public QWidget
{
    Q_OBJECT
public:
    ShowMovieWidget(QWidget *parent = 0);

public slots:
    void createWidgets();
    void togglePlayback();
    void updateState(QMediaPlayer::State state);
    void updatePosition(qint64 position);
    void updateDuration(qint64 duration);
    void seekForward();
    void seekBackward();
    void setPosition(int position);

public:
    QVideoWidget *playMovieWidget;
    QMediaPlayer *player;

private:
    QSlider *positionSlider;
    QLabel *positionLabel;
    QAbstractButton *playButton;
};

#endif // SHOWMOVIE_H
