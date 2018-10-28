#ifndef SHOWFORM_H
#define SHOWFORM_H

#include <QWidget>

namespace Ui {
class showform;
}

class showform : public QWidget
{
    Q_OBJECT

public:
    explicit showform(QWidget *parent = 0);
    ~showform();

private:
    Ui::showform *ui;
};

#endif // SHOWFORM_H
