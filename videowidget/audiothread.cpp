#include "audiothread.h"

AudioThread::AudioThread()
{

}

AudioThread::~AudioThread()
{

}

void AudioThread::startPlay(QString filename)
{
    mfilename = filename;
    start();
}

void AudioThread::run()
{
    qDebug() << endl <<  "run..." << endl;
}
