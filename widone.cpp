#include "widone.h"

widone::widone(QWidget *parent) : QWidget(parent)
{

}

void widone::enterEvent(QEvent *)
{
    emit Wid_one_Enter();
}

void widone::leaveEvent(QEvent *)
{
    emit Wid_one_Left();
}
