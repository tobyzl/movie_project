#ifndef MOVIEPLAYER_H
#define MOVIEPLAYER_H

#include <QMainWindow>

namespace Ui {
class movieplayer;
}

class movieplayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit movieplayer(QWidget *parent = 0);
    ~movieplayer();

private:
    Ui::movieplayer *ui;
};

#endif // MOVIEPLAYER_H
