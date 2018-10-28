#include "mythread.h"

MyThread::MyThread(qintptr id, QObject *parent) :
    QThread(parent)
{
        this->socketDescriptor = id;
}
void MyThread::run()
{
    //thread starts here!
    qDebug() << socketDescriptor <<"starting thread ";
    socket = new QTcpSocket();
    if (!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }
    bool i = connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    qDebug() << "是否触发！！！" << i;
    qDebug() << socketDescriptor <<"Client Connected";

    exec();

}
void MyThread::readyRead()
{
    QByteArray Data0;
    char * chr;
    Data0 = socket->readAll();
    qDebug() << socketDescriptor <<"Data in: " << Data0;
    chr = Data0.data();
    emit emit_text(QString(chr)); //转换成char*发送
    socket->write(Data0);
}
void MyThread::disconnected()
{
    qDebug() << socketDescriptor <<" Disconnected: ";
    socket->deleteLater();
    exit(0);
}

