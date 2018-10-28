#include "wid.h"

wid::wid(QWidget *parent) : QWidget(parent)
{

}

void wid::enterEvent(QEvent *)
{
    emit Wid_Enter();
}

void wid::leaveEvent(QEvent *)
{
    emit Wid_Left();
}
