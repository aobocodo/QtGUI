#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
}
void MyServer::StartServer()
{
    if (!this->listen(QHostAddress::LocalHost, 12345))
    {
        qDebug() << " Could not start server";
    }
    else
    {
        qDebug() << "listening.....";
    }

}
void MyServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor <<"connecting....";
    //发送信号，以供显示
    //emit emit_descriptor(socketDescriptor);
    //增加socket列表，可以选择向谁发送
    thread = new MyThread(socketDescriptor,this);
    //connect(thread, &MyThread::emit_text, this, &Myserver::transfer);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(thread, &MyThread::emit_text, this, &MyServer::transfer);
    thread->start();

}
void MyServer::transfer(QString ch)
{
    emit emit_text1(ch);
    qDebug() <<"10.26"<< ch ;
}
