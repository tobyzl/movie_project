#include "videoplayer.h"

#include <QtWidgets>
#include <qvideowidget.h>
#include <qvideosurfaceformat.h>

VideoPlayer::VideoPlayer(QWidget *parent)
    : QWidget(parent)
{
}

VideoPlayer::~VideoPlayer()
{
}

void VideoPlayer::setMedia(QString filename)
{
    m_filename = filename;
}

void VideoPlayer::play()
{
    qDebug() << this->m_filename << endl;

    UCHAR *ppHandle;
    SEMP4Read_Create(ppHandle);

    UCHAR *pHandle;
    char *pFilename;
    FILE_INFO *pFileInfo;
    SEMP4Read_OpenMp4File(pHandle, pFilename, pFileInfo);

    SEVideo_Create(1, ppHandle);
}

