#include "showform.h"
#include "ui_showform.h"

showform::showform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showform)
{
    ui->setupUi(this);
}

showform::~showform()
{
    delete ui;
}
