#ifndef MINESWEEPERBUTTON_H
#define MINESWEEPERBUTTON_H

#include "QPushButton"
#include "Util/Coordinates.h"

//This class was inspired by stephenliang on github.com

class MineSweeperButton : public QPushButton
{
    Q_OBJECT
public:
    MineSweeperButton(Coordinates);

signals:
    void rightButtonClicked();

private :
    Coordinates coordinates_ ;

    void mousePressEvent(QMouseEvent *);
};

#endif // MINESWEEPERBUTTON_H
