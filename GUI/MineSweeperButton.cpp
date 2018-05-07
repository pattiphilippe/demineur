#include "MineSweeperButton.h"
#include <QMouseEvent>



//This class was inspired by stephenliang on github.com

MineSweeperButton::MineSweeperButton(Coordinates coord) :
    coordinates_{coord}
{

}

void MineSweeperButton::mousePressEvent(QMouseEvent * mouseEvent)
{
    if(mouseEvent->button() == Qt::RightButton)
    {
        emit rightButtonClicked();
    }
    QPushButton::mousePressEvent(mouseEvent);
}
