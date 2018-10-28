#include "widget.h"
#include "ui_widget.h"
#include "btn.h"
#include "wid.h"
#include "btnone.h"
#include "widone.h"
#include "showform.h"


#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //socket server initiate
    server = new MyServer(this);
    server->StartServer();

    QPalette palette;
    palette.setColor(QPalette::Background, QColor(66,106,179));
    ui->top_widget->setAutoFillBackground(true);
    ui->top_widget->setPalette(palette);

    btn_zero = new btn();
    btn_zero->setGeometry(0,0,80,95);
    btn_zero->setAutoRaise(true);
    btn_zero->setIcon(QIcon("/home/nano/Desktop/setting.png"));
    btn_zero->setIconSize(QSize(40,40));
    //btn_zero->setStyleSheet("font:bold; font-size:18px");
    btn_zero->setText(tr("管理"));
    btn_zero->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn_zero->setParent(ui->btn_widget);
    btn_zero->show();
    connect(btn_zero,SIGNAL(Btn_Enter()),this,SLOT(Btn_enter()));
    connect(btn_zero,SIGNAL(Btn_Left()),this,SLOT(Btn_left()));

    QPalette palette1;
    palette1.setColor(QPalette::Background, QColor(209,199,183));
    ui->menu_widget->setAutoFillBackground(true);
    ui->menu_widget->setPalette(palette1);

    ui->menu_btn->setGeometry(0,0,80,20);
    ui->menu_btn->setAutoRaise(true);
    ui->menu_btn->setText(tr("初配置"));

    ui->menu_btn->setParent(ui->menu_widget);
    ui->menu_btn->show();


    connect(ui->menu_widget,SIGNAL(Wid_Enter()),this,SLOT(Wid_enter()));
    connect(ui->menu_widget,SIGNAL(Wid_Left()),this,SLOT(Wid_left()));

    ui->menu_widget->setVisible(false);

    btn_one = new btnone();
    btn_one->setGeometry(0,95,80,95);
    btn_one->setAutoRaise(true);
    btn_one->setIcon(QIcon("/home/nano/Desktop/set.png"));
    btn_one->setIconSize(QSize(50,50));
    btn_one->setText(tr("基站"));
    btn_one->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn_one->setParent(ui->btn_widget);
    btn_one->show();
    connect(btn_one,SIGNAL(Btn_one_Enter()),this,SLOT(Btn_one_enter()));
    connect(btn_one,SIGNAL(Btn_one_Left()),this,SLOT(Btn_one_left()));

    QPalette palette2;
    palette2.setColor(QPalette::Background, QColor(209,199,183));
    ui->menu_one_widget->setAutoFillBackground(true);
    ui->menu_one_widget->setPalette(palette2);
    connect(ui->menu_one_widget,SIGNAL(Wid_one_Enter()),this,SLOT(Wid_one_enter()));
    connect(ui->menu_one_widget,SIGNAL(Wid_one_Left()),this,SLOT(Wid_one_left()));

    ui->menu_one_btn->setGeometry(0,0,80,20);
    ui->menu_one_btn->setAutoRaise(true);
    ui->menu_one_btn->setText((tr("deploy")));
    ui->menu_one_btn->setParent(ui->menu_one_widget);
    ui->menu_one_btn->show();

    ui->menu_one_widget->setVisible(false);


    ui->textEdit->setText("hello world \nhello world");
    ui->textEdit->append("hello");

    connect(server, &MyServer::emit_text1, this, &Widget::display_text, Qt::QueuedConnection);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Btn_enter()
{
    ui->menu_widget->setVisible(true);
    ui->menu_one_widget->setVisible(false);
    qDebug()<<("into btn");
}

void Widget::Btn_left()
{
    //qDebug()<<("out btn");
}

void Widget::Wid_enter()
{
    //qDebug()<<("into wid");
}

void Widget::Wid_left()
{
    ui->menu_widget->setVisible(false);
    qDebug()<<("out wid");
}

void Widget::Btn_one_enter()
{

    ui->menu_one_widget->setVisible(true);
    ui->menu_widget->setVisible(false);
    //qDebug()<<("enter btn_one");
}

void Widget::Btn_one_left()
{
    qDebug()<<("out btn_one");
}

void Widget::Wid_one_enter()
{

    qDebug()<<("enter wid_one");
}

void Widget::Wid_one_left()
{
    ui->menu_one_widget->setVisible(false);
    //qDebug()<<("out wid_one");
}



void Widget::on_menu_btn_clicked()
{
    ui->menu_widget->setVisible(false);
    ui->tabWidget->addTab(new showform(),"show");
}

void Widget::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

void Widget::on_menu_one_btn_clicked()
{
    ui->menu_one_widget->setVisible(false);
    ui->tabWidget->addTab(new QWidget(),"deploy");
}
void Widget::display_text(QString ch)
{
        //qDebug() <<"测试一下LLLLL" <<ch ;
        ui->textEdit->append(QString(ch));
}
