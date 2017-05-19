#ifndef MP4PLAYER_H
#define MP4PLAYER_H

#include <QtGui/QMovie>
#include <QtWidgets/QWidget>
#include <qmediaplayer.h>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QLineEdit>
#include "videothread.h"
#include "audiothread.h"

class MP4Player : public QWidget
{
    Q_OBJECT
public:
    MP4Player(QWidget *parent = 0);
    ~MP4Player();

public slots:
    void openFile();
    void paintEvent(QPaintEvent *event);

private slots:
    void mediaStateChanged();
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void setPosition(int position);

    void slotGetOneFrame(QImage img);

signals:
    void play();
    void pause();

private:
    QPushButton *playButton;
    QSlider *positionSlider;
    QLineEdit *lineEdit;
    QLabel *m_lab_show;
    VideoThread *videoThread;
    AudioThread *audioThread;
    QImage mImage; //记录当前的图像
    bool isplay;
    QString mfilename;

};

#endif
