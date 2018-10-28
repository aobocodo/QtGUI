#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(qintptr id, QObject *parent = 0);
    void run();
signals:
    void error(QTcpSocket::SocketError socketerror);
    void emit_text(QString);
public slots:
    void	readyRead ();
    void disconnected();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;

};

#endif // MYTHREAD_H
