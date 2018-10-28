#ifndef WID_H
#define WID_H

#include <QWidget>

class wid : public QWidget
{
    Q_OBJECT
public:
    explicit wid(QWidget *parent = nullptr);

    void leaveEvent(QEvent *);

signals:

    void Wid_Left();

public slots:
};

#endif // WID_H
