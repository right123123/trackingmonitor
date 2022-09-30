#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QSemaphore>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>
#include <QTime>
#include <QApplication>
#include <QImage>
#include <windows.h>


class mythread : public QThread
{
    Q_OBJECT
public:
    mythread();
    ~mythread();

//    void Delay(int msec);

    void set_Rec_Buffer_ptr(uchar *x_Rec_Buffer);
    void set_freeBytes_ptr(QSemaphore *x_freeBytes);
    void set_usedBytes_ptr(QSemaphore *x_usedBytes);

    QSemaphore *m_freeBytes;
    QSemaphore *m_usedBytes;
    uchar *m_Rec_Buffer;

    quint16 Writer_Ptr;
    quint16 Reader_Ptr;
    quint16 Pre_reader_Ptr;

    volatile bool Run_stopped;
    volatile bool Run;
    volatile bool Tcp_send;
    volatile bool ctr_send;

    uchar *data = new uchar[18];
    QString ctrcmd;
    QString m_ip;
    quint16 m_port;
    QString m_PortName;


public slots:
    void gettcpdata(uchar *pdata);

signals:
    void sendmsgtomain(uchar num,quint16 x, quint16 y ,quint16 dis,quint8 dis1);
    void sendshowbuff(uchar* showbuff,int len);
    void sendimg(QImage img , int w,int h);
};

#endif // MYTHREAD_H
