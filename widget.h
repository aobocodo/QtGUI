#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "myserver.h"

class btn;


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget( QWidget *parent = 0);
    btn *btn_zero;

    MyServer * server;


    ~Widget();

private slots:
    void Btn_enter();


    void Wid_left();


    void on_menu_btn_clicked();



    void display_text(QString ch);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
