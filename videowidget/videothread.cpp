#include "videothread.h"

VideoThread::VideoThread()
{

}

VideoThread::~VideoThread()
{

}

void VideoThread::startPlay(QString filename)
{
   m_filename = filename;
   start();
}

void printText(FILE_INFO FileInfo)
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

void VideoThread::decode(UCHAR *pBuf, unsigned long len)
{
    UCHAR *ppHandle = NULL;
    UINT32 ok = SEVideo_Create(1, &ppHandle);
    if (ok = 0)
    {
        qDebug() << "SEVideo_Create failed" << endl;
    }


    UCHAR *inRawData = pBuf;
    unsigned long inLen = len;
    unsigned long max_len = NBUFMAXSIZE;
    UCHAR outYUV420[max_len];
    unsigned long in_outLen;
    INT32 videoWidth;
    INT32 videoHeight;
    ok = SEVideo_Decode2YUV(ppHandle, inRawData, inLen, outYUV420, &in_outLen, &videoWidth, &videoHeight);
 /*   qDebug() << "2yuv ok : " << ok;
    qDebug() << "in_outLen : " << in_outLen;
    qDebug() << "videoWidth : " << videoWidth ;
    qDebug() << "videoHeight : " << videoHeight << endl; */


    unsigned long in_outLen_24 = 700000;
    UCHAR outRGB24[in_outLen_24];
    ok = SEVideo_YUV420toRGB24(outYUV420, in_outLen, outRGB24, &in_outLen_24, videoWidth, videoHeight);
  /*  qDebug() << "RGB24 ok :" << ok;
    qDebug() << "in_outLen_24 :" << in_outLen_24 << endl; */

    QImage tmpImg(outRGB24, videoWidth, videoHeight, QImage::Format_RGB888);
    QImage image = tmpImg.copy();
    emit sig_sentOneFrame(image);  //发送信号 */
}

void VideoThread::pause()
{
    qDebug() << "pause.." << endl;
    wait();
 //   cond.wait(&mutex); //当处于wait状态时mutex会被暂时释放，并阻塞在这个地方；当线程被cond.wakeOne()等唤醒时，mutex又会被重新锁定，并继续运行
  //  mutex.unlock();
}

void VideoThread::play()
{
     qDebug() << "paly.." << endl;
  //   cond.wakeOne();
}

void VideoThread::run()
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
        printText(FileInfo);

        emit durationChanged(FileInfo.nDurationInSecond * 1000);
        if (ret < 0)
        {
            qDebug() << "SEMP4Read_OpenMp4File failed" << endl;
            return;
        }

        ret = SEMP4Read_SetBeginPos(pHandle, 0);
        if (ret < 0)
        {
            qDebug() << "SEMP4Read_SetBeginPos failed" << endl;
            return;
        }

        UCHAR *ppHandle = NULL;
        UINT32 ok = SEVideo_Create(1, &ppHandle);
        if (ok = 0)
        {
            qDebug() << "SEVideo_Create failed" << endl;
        }

        UINT32 nBufMaxSize = NBUFMAXSIZE; //393216
        UCHAR pBuf[nBufMaxSize] = {0};
        INT32 size;
        UINT32 preTimestamp = 0;

        for (int i=0; ; i++)
        {
           // qDebug() << endl << "i = " << i+1;
            size = SEMP4Read_ReadOneFrame(pHandle, pBuf, nBufMaxSize);
          //  qDebug() << "size = " <<  size << endl;
            if (size < 0)
            {
                break;
            }

            UCHAR *pdata = pBuf + sizeof(RTSP_STREAM_HEAD);
            RTSP_STREAM_HEAD *phead = (RTSP_STREAM_HEAD*)pBuf;
    /*     // qDebug() << "nAVCodecID = " <<  phead->nAVCodecID << endl;
            qDebug() << "nParameter = " <<  (int)phead->nParameter << endl;
          //qDebug() << "reserve1 = " <<  phead->reserve1 << endl;
            qDebug() << "nStreamDataLen = " <<  phead->nStreamDataLen;
            qDebug() << "nTimestamp = " <<  phead->nTimestamp << endl;
           //decode(pdata, phead->nStreamDataLen); */

         // UCHAR *inRawData = pdata;
            unsigned long inLen = phead->nStreamDataLen;
            UCHAR outYUV420[nBufMaxSize];
            unsigned long in_outLen;
            INT32 videoWidth;
            INT32 videoHeight;
            ok = SEVideo_Decode2YUV(ppHandle, pdata, inLen, outYUV420, &in_outLen, &videoWidth, &videoHeight);
 /*         qDebug() << "2yuv ok : " << ok;
            qDebug() << "in_outLen : " << in_outLen;
            qDebug() << "videoWidth : " << videoWidth ;
            qDebug() << "videoHeight : " << videoHeight << endl;
*/

            unsigned long in_outLen_24 = 700000;
            UCHAR outRGB24[in_outLen_24];
            ok = SEVideo_YUV420toRGB24(outYUV420, in_outLen, outRGB24, &in_outLen_24, videoWidth, videoHeight);
       /*
            qDebug() << "RGB24 ok :" << ok;
            qDebug() << "in_outLen_24 :" << in_outLen_24 << endl;
            */
            Sleep(phead->nTimestamp - preTimestamp);
            preTimestamp = phead->nTimestamp;

            QImage tmpImg(outRGB24, videoWidth, videoHeight, QImage::Format_RGB888);
            image = tmpImg.copy();

            emit sig_sentOneFrame(image);  //发送信号
            emit positionChanged(phead->nTimestamp);
       }

       SEMP4_Destroy(&pHandle);
       SEVideo_Destroy(&ppHandle);
}
