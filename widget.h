#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "myserver.h"

class btn;
class btnone;


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget( QWidget *parent = 0);
    btn *btn_zero;
    btnone *btn_one;

    MyServer * server;


    ~Widget();

private slots:
    void Btn_enter();
    void Btn_left( );
    void Wid_enter();
    void Wid_left();
    void Btn_one_enter();
    void Btn_one_left();
    void Wid_one_enter();
    void Wid_one_left();

    void on_menu_btn_clicked();

    void on_tabWidget_tabCloseRequested(int index);

    void on_menu_one_btn_clicked();

    void display_text(QString ch);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
