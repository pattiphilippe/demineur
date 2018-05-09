#include "MineSweeperButton.h"
#include <QMouseEvent>



//The idea of this class was inspired by stephenliang on github.com

/**
 * @brief MineSweeperButton::MineSweeperButton
 * Create a new button for the minefield of minesweeper
 * @param coord Coordinates of the button in the minesweeper field.
 */
MineSweeperButton::MineSweeperButton(Coordinates coord) :
    coordinates_{coord}
{

}

/**
 * @brief MineSweeperButton::mousePressEvent
 * Emit a special signal when the right or the left button of the mouse is clicked.
 * @param mouseEvent
 */
void MineSweeperButton::mousePressEvent(QMouseEvent * mouseEvent)
{
    if(mouseEvent->button() == Qt::RightButton)
    {
        emit rightButtonClicked();
    }else{
        emit leftButtonClicked();
    }


}
