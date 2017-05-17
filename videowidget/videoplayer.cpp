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

    UCHAR **ppHandle = NULL;
    UINT32 reg = SEMP4Read_Create(ppHandle);

    qDebug() << reg << endl;

/*
    //return:
    //	>=0 OK
    //	 <0 FAIL
    //		-1: pFilename==NULL
    //		-2: open file fails
    //		-3: there isn't audio and video track
    UCHAR *pHandle;
    char *pFilename;
    FILE_INFO *pFileInfo;
    INT32 ret = SEMP4Read_OpenMp4File(pHandle, pFilename, pFileInfo);

    //Parameter:
    //  nBeginPos_sec,
    //		if it is >0 then one frame is getted to start the specified position in second.
    //		if it is <=0 then one frame is getted one by one.
    //UCHAR *pHandle;
    INT32 nBeginPos_sec = 0;
    ret = SEMP4Read_SetBeginPos(pHandle, nBeginPos_sec);

    //Parameter:
    //	pBuf=RTSP_STREAM_HEAD + raw_av_data
    //
    //return:
    //	>=0 OK
    //	< 0 FAIL
    //		-1: nBufMaxSize<384KBytes
    //		-2: please first call SEMP4Read_OpenMp4File
    //		-3: read one frame fails
   // UCHAR *pHandle;
    UCHAR *pBuf;
    UINT32 nBufMaxSize;
    ret =  SEMP4Read_ReadOneFrame(pHandle, pBuf, nBufMaxSize);

*/

}

