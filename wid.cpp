#include "wid.h"

wid::wid(QWidget *parent) : QWidget(parent)
{

}



void wid::leaveEvent(QEvent *)
{
    emit Wid_Left();
}
