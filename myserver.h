#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include "mythread.h"
#include <QDebug>
#include <QString>

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
    void StartServer();
    MyThread *thread;


signals:
    void emit_text1(QString);
public slots:
    void transfer(QString ch);
protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // MYSERVER_H
