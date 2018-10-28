#ifndef BTN_ONE_H
#define BTN_ONE_H

#include <QObject>
#include <QToolButton>
#include <QEvent>

class btnone : public QToolButton
{
    Q_OBJECT
public:
    explicit btnone(QWidget *parent = 0);

signals:
    void Btn_one_Enter();
    void Btn_one_Left();

public slots:

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
};

#endif // BTN_ONE_H
