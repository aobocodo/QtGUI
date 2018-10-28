#ifndef WIDONE_H
#define WIDONE_H

#include <QWidget>
#include <QMouseEvent>
#include <QEvent>

class widone : public QWidget
{
    Q_OBJECT
public:
    explicit widone(QWidget *parent = nullptr);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

signals:
    void Wid_one_Enter();
    void Wid_one_Left();

public slots:
};

#endif // WIDONE_H
