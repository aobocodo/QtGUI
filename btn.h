#ifndef MYTOOLBUTTON_H
#define MYTOOLBUTTON_H

#include <QObject>
#include <QToolButton>
#include <QEvent>

class btn : public QToolButton
{
    Q_OBJECT
public:
    explicit btn(QWidget *parent=0);

signals:
    void Btn_Enter();
    void Btn_Left();

public slots:

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
};

#endif // MYTOOLBUTTON_H
