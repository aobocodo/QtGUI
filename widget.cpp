#include "widget.h"
#include "ui_widget.h"
#include "btn.h"
#include "wid.h"
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


    QPalette palette1;
    palette1.setColor(QPalette::Background, QColor(209,199,183));
    ui->menu_widget->setAutoFillBackground(true);
    ui->menu_widget->setPalette(palette1);

    ui->menu_btn->setGeometry(0,0,80,20);
    ui->menu_btn->setAutoRaise(true);
    ui->menu_btn->setText(tr("初配置"));

    ui->menu_btn->setParent(ui->menu_widget);
    ui->menu_btn->show();



    connect(ui->menu_widget,SIGNAL(Wid_Left()),this,SLOT(Wid_left()));

    ui->menu_widget->setVisible(false);



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
    //qDebug()<<("into btn");
}


void Widget::Wid_left()
{
    ui->menu_widget->setVisible(false);
    //qDebug()<<("out wid");

}




void Widget::on_menu_btn_clicked()
{
    ui->menu_widget->setVisible(false);
    //ui->tabWidget->addTab(new showform(),"show");
}


void Widget::display_text(QString ch)
{
        //qDebug() <<"测试一下LLLLL" <<ch ;
        ui->textEdit->append(QString(ch));
}
