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

void printTex(FILE_INFO FileInfo)
{
    QFile file("fileinfo.txt");

    if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate))
    {
        qDebug() << "Open failed." << endl;
        return;
    }
    QTextStream txtOutput(&file);
    txtOutput << "FileInfo" << endl << endl;
    txtOutput << "eVideoAVCodecID = " << FileInfo.eVideoAVCodecID << endl;
    txtOutput << "nVideoWidth = " << FileInfo.nVideoWidth << endl;
    txtOutput << "nVideoHeight = " << FileInfo.nVideoHeight << endl << endl;

    txtOutput << "eAudioAVCodecID = " << FileInfo.eAudioAVCodecID << endl;
    txtOutput << "nAudioSamplerate = " << FileInfo.nAudioSamplerate << endl;
    txtOutput << "nAudioDatabit = " << FileInfo.nAudioDatabit << endl;
    txtOutput << "nAudioChannels = " << FileInfo.nAudioChannels << endl << endl;

    txtOutput << "nDurationInSecond = " << FileInfo.nDurationInSecond << endl;
    txtOutput << "nFileSizeInByte = " << FileInfo.nFileSizeInByte << endl;
    txtOutput << "reserve = " << FileInfo.reserve << endl;

    file.close();

}

QImage VideoPlayer::play()
{
    UCHAR *pHandle = NULL;
    UINT32 reg = SEMP4Read_Create(&pHandle);
    if (reg < 0)
    {
        qDebug() << "SEMP4Read_Create failed" << endl;
        //return;
    }

    char *pFilename;
    pFilename = m_filename.toLocal8Bit().data();
    FILE_INFO FileInfo;
    INT32 ret = SEMP4Read_OpenMp4File(pHandle, pFilename, &FileInfo);
    printTex(FileInfo);
    if (ret < 0)
    {
        qDebug() << "SEMP4Read_OpenMp4File failed" << endl;
        //return;
    }

    ret = SEMP4Read_SetBeginPos(pHandle, 0);
    if (ret < 0)
    {
        qDebug() << "SEMP4Read_SetBeginPos failed" << endl;
       // return;
    }

    UCHAR *ppHandle = NULL;
    UINT32 ok = SEVideo_Create(1, &ppHandle);
    if (ok = 0)
    {
        qDebug() << "SEVideo_Create failed" << endl;
    }

    UINT32 nBufMaxSize = 384 * 1024; //393216
    UCHAR pBuf[nBufMaxSize];
    QImage image;

    for (int i=0; i<1; i++)
    {
    INT32 size =  SEMP4Read_ReadOneFrame(pHandle, pBuf, nBufMaxSize);
    qDebug() << endl << "size " << size << endl;

    UCHAR *pdata = pBuf + sizeof(RTSP_STREAM_HEAD);
    RTSP_STREAM_HEAD *phead = (RTSP_STREAM_HEAD*)pBuf;

    UCHAR *inRawData = pdata;
    unsigned long inLen = phead->nStreamDataLen;
    UCHAR outYUV420[nBufMaxSize];
    unsigned long in_outLen;
    INT32 videoWidth;
    INT32 videoHeight;
    ok = SEVideo_Decode2YUV(ppHandle, inRawData, inLen, outYUV420, &in_outLen, &videoWidth, &videoHeight);
    qDebug() << "2yuv ok : " << ok << endl;
    qDebug() << "in_outLen : " << in_outLen << endl;
    qDebug() << "videoWidth : " << videoWidth << endl;
    qDebug() << "videoHeight : " << videoHeight << endl;

   // UCHAR *inYUV420Planar;
    //unsigned long inLen;
    UCHAR outRGB24[nBufMaxSize];
    unsigned long in_outLen_24;
   // INT32 videoWidth;
  //  INT32 videoHeight;
    ok = SEVideo_YUV420toRGB24(outYUV420, in_outLen, outRGB24, &in_outLen_24, videoWidth, videoHeight);
    qDebug() << "RGB24 ok :" << ok << endl;
    qDebug() << in_outLen_24 << endl;

    QImage tmpImg(outRGB24, videoWidth, videoHeight, QImage::Format_RGB888);
    image = tmpImg.copy();
    }
    return image;

}
