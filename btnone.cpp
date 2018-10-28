#include "btnone.h"

btnone::btnone(QWidget *parent) : QToolButton(parent)
{

}

void btnone::enterEvent(QEvent *)
{
    emit Btn_one_Enter();
}

void btnone::leaveEvent(QEvent *)
{
    emit Btn_one_Left();
}
