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

void VideoThread::decode(UCHAR *pBuf)
{
    UCHAR *ppHandle = NULL;
    UINT32 ok = SEVideo_Create(1, &ppHandle);
    if (ok = 0)
    {
        qDebug() << "SEVideo_Create failed" << endl;
    }


    UCHAR *inRawData = pBuf;
    unsigned long inLen = NBUFMAXSIZE;
    UCHAR outYUV420[inLen];
    unsigned long in_outLen;
    INT32 videoWidth;
    INT32 videoHeight;
    ok = SEVideo_Decode2YUV(ppHandle, inRawData, inLen, outYUV420, &in_outLen, &videoWidth, &videoHeight);
    qDebug() << "2yuv ok : " << ok << endl;
    qDebug() << "in_outLen : " << in_outLen << endl;
    qDebug() << "videoWidth : " << videoWidth << endl;
    qDebug() << "videoHeight : " << videoHeight << endl;

    UCHAR outRGB24[inLen];
    unsigned long in_outLen_24;
    ok = SEVideo_YUV420toRGB24(outYUV420, inLen, outRGB24, &in_outLen_24, videoWidth, videoHeight);
    qDebug() << "RGB24 ok :" << ok << endl;
    qDebug() << in_outLen_24 << endl;

    QImage image(outRGB24, videoWidth,videoHeight,QImage::Format_RGB888);
    emit sig_sentOneFrame(image);  //发送信号
}

void VideoThread::play()
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

        UINT32 nBufMaxSize = NBUFMAXSIZE; //393216
        UCHAR pBuf[nBufMaxSize];
        INT32 size =  SEMP4Read_ReadOneFrame(pHandle, pBuf, nBufMaxSize);
        qDebug() << endl << "size " << size << endl;


        decode(pBuf);

/*
    for(int i=0;;i++)
    {
        if (feof(fp_yuv)) break;

        int readedsize = fread(yuvBuffer,1,yuvSize,fp_yuv);


        //把这个RGB数据 用QImage加载
        QImage tmpImg((uchar *)rgbBuffer,width,height,QImage::Format_RGB32);
        QImage image = tmpImg.copy(); //把图像复制一份 传递给界面显示
        emit sig_GetOneFrame(image);  //发送信号

    }*/
}
