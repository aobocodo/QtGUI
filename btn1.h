#ifndef BTN1_H
#define BTN1_H

#include <QObject>
#include <QToolButton>
#include <QEvent>

class btn1 : public QToolButton
{
public:
   explicit btn1(QWidget *parent = 0);

signals:
    void Btn1_Enter();
    void Btn1_Left();

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
};

#endif // BTN1_H
