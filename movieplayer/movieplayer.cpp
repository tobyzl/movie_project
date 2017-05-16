#include "movieplayer.h"
#include "ui_movieplayer.h"

movieplayer::movieplayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::movieplayer)
{
    ui->setupUi(this);
}

movieplayer::~movieplayer()
{
    delete ui;
}
