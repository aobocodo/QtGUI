#include "btn.h"


btn::btn(QWidget *parent) : QToolButton(parent)
{

}



void btn::enterEvent(QEvent *)
{

    emit Btn_Enter();
}


