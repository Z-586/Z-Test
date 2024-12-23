#include "aestools.h"
#include <QDebug>
#include "qstring.h"
#include <QFile>


AesTools::AesTools()
{
    m_lpAes=NULL;
    InitializePrivateKey(16,(unsigned char*)"\x79\x76\x68\x6B\x77\x66\x6E\x68\x72\x65\x73\x63\x6C\x6B\x70\x6E");
}

AesTools::~AesTools()
{
    if (m_lpAes!=NULL)
    {
        delete m_lpAes;
    }
}
//------------------------------------------------------------------------------------------------------------
// 编写人员：wfnhddd
// 函数名称：InitializeAes
// 函数描述：初始化AES 密钥，密钥用于加密解密
//
// 调用参数：详细说明参考 MSDN 中的相关描述或相关的开发文档
//
// 返回数值：无
//
// 最近修改：2009 年 08 月 07 日
//------------------------------------------------------------------------------------------------------------


VOID AesTools::InitializePrivateKey(DWORD KeySize,UCHAR *KeyBytes)
{
    if (m_lpAes)
    {
        delete m_lpAes;
        m_lpAes=NULL;
    }
    m_lpAes=new Aes(KeySize,KeyBytes);

}

//------------------------------------------------------------------------------------------------------------
// 编写人员：wfnhddd
//
// 函数名称：OnAesEncrypt
//
// 函数描述：用AES加密算法加密数据
//
// 调用参数：详细说明参考 MSDN 中的相关描述或相关的开发文档
//
// 返回数值：加密后的数据大小 ，错误返回值 0
//
// 最近修改：2009 年 08 月 07 日
//------------------------------------------------------------------------------------------------------------

DWORD AesTools::OnAesEncrypt(LPVOID InBuffer,DWORD InLength,LPVOID OutBuffer)
{
    //DWORD占4个字节
    DWORD OutLength=0;
    if (m_lpAes==NULL||OutBuffer==NULL)
    {
        return 0;
    }

    //InBuffer是一个char类型的数组，lpCurInBuff指针指向的是InBuffer char数组的第一个元素的地址
    UCHAR *lpCurInBuff=(UCHAR *)InBuffer;
    //加密后的数据往OutBuffer中写入时，从第16个字节开始写。前面空出16个字节，用于存放密文大小和额外加密的字节个数，只用到8个字节，但为了保证字节总数是16的倍数，故预留了16个字节
    UCHAR *lpCurOutBuff=(UCHAR *)OutBuffer;

    long blocknum=InLength/16;
    long leftnum =InLength%16;
    if( leftnum >0 )
    {
        QString Str = "input data len Error,not 16 的倍数!";
        qDebug()<< Str;
    }
    for(long i=0;i<blocknum;i++)
    {
        //加密时，传入的数组必须时16个字节的
        m_lpAes->Cipher(lpCurInBuff,lpCurOutBuff);
        //每次加密16个字节，循环直至所有字节均被加密
        lpCurInBuff+=16;
        lpCurOutBuff+=16;
        OutLength+=16;
    }


    return OutLength;

}


//------------------------------------------------------------------------------------------------------------
// 编写人员：wfnhddd
//
// 函数名称：OnAesUncrypt
//
// 函数描述：用AES加密算法解密数据
//
// 调用参数：详细说明参考 MSDN 中的相关描述或相关的开发文档
//
// 返回数值：解密后的数据大小 ，错误返回值 0
//
// 最近修改：2009 年 08 月 07 日
//------------------------------------------------------------------------------------------------------------
DWORD AesTools::OnAesUncrypt(LPVOID InBuffer,DWORD InLength,LPVOID OutBuffer)
{
    //传入的InLength大小是加密时返回的OutLength+16，即outBuffer的大小
    DWORD OutLength=0;
    if (m_lpAes==NULL||OutBuffer==NULL)
    {
        return 0;
    }
    //密文是从第16个字节开始的，故解密时，前16个字节忽略，直接从第16个字节开始解密
    UCHAR *lpCurInBuff =(UCHAR *)InBuffer;
    UCHAR *lpCurOutBuff=(UCHAR *)OutBuffer;
    long blocknum=InLength/16;
    long leftnum=InLength%16;
    if(leftnum)
    {               //传入的密文大小必须是16的整数倍个字节
                return 0;
    }

    //每次解密16个字节，循环全部解出
    for(long i=0;i<blocknum;i++)
    {
        m_lpAes->InvCipher(lpCurInBuff,lpCurOutBuff);
        lpCurInBuff+=16;
        lpCurOutBuff+=16;
        OutLength+=16;
    }

    return (OutLength);

}


//打开文件，将文件中的内容返回一个QbyteArray的数组
void AesTools::OpenFile(QString fileName)
{
    QFile file(fileName);
    file.open(( QIODevice::ReadOnly));
    ReadDateByte = file.readAll();
    file.close();
    qDebug()<<" ReadDateByte size is:"<< ReadDateByte.size();
}

//将一个QbyteArray数组写入到指定文件中去。
//使用二进制数组进行文件的读写能够有效避免各种由于编码格式和类型转换造成的问题
void AesTools::WriteFile(QString fileName, QByteArray data)
{
    QFile file(fileName);
    file.open(( QIODevice::ReadWrite|QIODevice::Truncate));
    file.write(data);
    file.close();
    return ;
}

// 解密文件 返回值0 解密失败   返回值>0,返回解密后的文件大小
DWORD AesTools::FileDecryptor(QString inFileName,QString outFileName)
{
     OpenFile(inFileName);
    char miwen[1024*256]={0};
    char jiemi[1024]={0};
    //将temp字节数组中的所有数据复制给miwen char类型数组
    memcpy(miwen,ReadDateByte.data(),ReadDateByte.size());
//    DWORD byteSize = 0;
//    //miwen的大小存放在miwen的前四个字节中，将miwen大小赋值给byteSize
//    memcpy(&byteSize,miwen,4);

    UCHAR key[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    UCHAR *p = key;
    InitializePrivateKey(16, p); //进行初始化
    DWORD ret = OnAesUncrypt((LPVOID)miwen, ReadDateByte.size(),(LPVOID)jiemi); //进行解密
    if(ret == 0)
    {
        qDebug()<<QString::fromUtf8("文件解密失败！.");
        return 0;
    }
    else
    {
        qDebug()<<"解密后的文件大小：."<<ret;
        //解密结果写入文件中
        QByteArray mingwenData;
        mingwenData.setRawData(jiemi,ret);

        WriteFile(outFileName,mingwenData);
        return ret;
    }
}



// 解密文件,输出解密后的文件大小和内容， 返回值0 解密失败   返回值>0,返回解密后的文件大小
DWORD AesTools::FileDecryptorToDate(QString inFileName,DWORD *Length, uchar *DatOut )
{
     OpenFile(inFileName);
    char miwen[1024*256]={0};
//    char jiemi[1024*256]={0};
    //将temp字节数组中的所有数据复制给miwen char类型数组
    memcpy(miwen,ReadDateByte.data(),ReadDateByte.size());
//    DWORD byteSize = 0;
//    //miwen的大小存放在miwen的前四个字节中，将miwen大小赋值给byteSize
//    memcpy(&byteSize,miwen,4);

    UCHAR key[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    UCHAR *p = key;
    InitializePrivateKey(16, p); //进行初始化
    DWORD ret = OnAesUncrypt((LPVOID)miwen, ReadDateByte.size(),(LPVOID)DatOut); //进行解密
    if(ret == 0)
    {
        qDebug()<<"文件解密失败！.";
        return 0;
    }
    else
    {
        qDebug()<<"解密后的文件大小：."<<ret;
        //解密结果写入文件中
        *Length = ret;

        return ret;
    }
}

//加密文件
DWORD AesTools::FileEncryptor(QString inFileName,QString outFileName)
{
    OpenFile(inFileName);

    uint32_t NewFileSize =0;

    char mingwen[1024*256] ;
    //将temp字节数组中的所有数据复制给mingwen数组
    if( (ReadDateByte.size() %16) !=0 )
    {
        QString Str = "bin 文件大小，不是16的整数倍，自动填充为16的整数倍，不会影响程序功能!";
        qDebug()<<Str;

        Str= QString("自动填充前的文件大小为：%1").arg(ReadDateByte.size() );
        qDebug()<< Str;

        int FillLen = 16-(ReadDateByte.size() %16);
        NewFileSize = ReadDateByte.size()+ FillLen;

        memcpy(mingwen,ReadDateByte.data(), NewFileSize);

        Str = QString("自动填充后的文件大小为：%1 ").arg(NewFileSize);
        qDebug()<< Str;
    }
    else
    {
        NewFileSize = ReadDateByte.size();
        memcpy(mingwen,ReadDateByte.data(),NewFileSize);

        QString Str = QString("文件大小为:%1 ").arg(NewFileSize );
        qDebug()<< Str;
    }

    char miwen[1024*256]={0};
    UCHAR key[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    UCHAR *p = key;
    InitializePrivateKey(16, p); //进行初始化

    DWORD ret = OnAesEncrypt((LPVOID)mingwen, NewFileSize, (LPVOID)miwen); //进行加密
    if( ret ==0 )
    {
        qDebug()<<"文件加密失败！.";
        return 0;
    }
    else
    {
        qDebug()<<"miwen size:"<< ret;
        QByteArray miwenData;
        miwenData.setRawData(miwen,ret);
        WriteFile(outFileName,miwenData);

        return ret;
    }
}



