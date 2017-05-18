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

    //Parameter:
    //	        pBuf = RTSP_STREAM_HEAD + raw_av_data
    //
    //return:
    //	>=0 OK
    //	< 0 FAIL
    //		-1: nBufMaxSize<384KBytes
    //		-2: please first call SEMP4Read_OpenMp4File
    //		-3: read one frame fails
   // UCHAR *pHandle;
    UINT32 nBufMaxSize = 384 * 1024; //393216
    UCHAR pBuf[nBufMaxSize];
    INT32 size =  SEMP4Read_ReadOneFrame(pHandle, pBuf, nBufMaxSize);
    qDebug() << endl << "size " << size << endl;

    UCHAR *ppHandle = NULL;
    UINT32 ok = SEVideo_Create(1, &ppHandle);
    if (ok = 0)
    {
        qDebug() << "SEVideo_Create failed" << endl;
    }


    UCHAR *inRawData = pBuf;
    unsigned long inLen = nBufMaxSize;
    UCHAR outYUV420[inLen];
    unsigned long in_outLen;
    INT32 videoWidth;
    INT32 videoHeight;
    ok = SEVideo_Decode2YUV(ppHandle, inRawData, inLen, outYUV420, &in_outLen, &videoWidth, &videoHeight);
    qDebug() << "2yuv ok : " << ok << endl;
    qDebug() << "in_outLen : " << in_outLen << endl;
    qDebug() << "videoWidth : " << videoWidth << endl;
    qDebug() << "videoHeight : " << videoHeight << endl;

    /*
    UCHAR *inRawData = pBuf;
    unsigned long inLen = nBufMaxSize;
    UCHAR outRGB565[inLen];
    unsigned long in_outLen;
    INT32 videoWidth;
    INT32 videoHeight;
    ok = SEVideo_Decode2RGB565(ppHandle, inRawData, inLen, outRGB565, &in_outLen, &videoWidth, &videoHeight);

    qDebug() << "rgb565 ok : " << ok << endl;
    qDebug() << "in_outLen : " << in_outLen << endl;
    qDebug() << "videoWidth : " << videoWidth << endl;
    qDebug() << "videoHeight : " << videoHeight << endl;
    */

/*
    //UCHAR *inYUV420Planar;
    UCHAR outRGB565[inLen];
    UINT32 in_outLen_565;
    INT32 videoWidth_565 = videoWidth;
    INT32 videoHeight_565 = videoHeight;
    ok = SEVideo_YUV420toRGB565(ppHandle, outYUV420, outRGB565, &in_outLen_565,  videoWidth_565, videoHeight_565);

    qDebug() << "RGB565 ok : " << ok << endl;
    qDebug() << "in_outLen_565 : " << in_outLen_565 << endl;
    qDebug() << "videoWidth_565 : " << videoWidth_565 << endl;
    qDebug() << "videoHeight_565 : " << videoHeight_565 << endl;
*/


   // UCHAR *inYUV420Planar;
    //unsigned long inLen;
    UCHAR outRGB24[inLen];
    unsigned long in_outLen_24;
   // INT32 videoWidth;
  //  INT32 videoHeight;
    ok = SEVideo_YUV420toRGB24(outYUV420, inLen, outRGB24, &in_outLen_24, videoWidth, videoHeight);
    qDebug() << "RGB24 ok :" << ok << endl;
    qDebug() << in_outLen_24 << endl;

    QImage image(outRGB24, videoWidth,videoHeight,QImage::Format_RGB888);
    return image;

}
