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

    inline Coordinates getCoordinates() const;

signals:
    void rightButtonClicked();

private :
    Coordinates coordinates_ ;

    void mousePressEvent(QMouseEvent *);
};

Coordinates MineSweeperButton::getCoordinates() const{
    return this->coordinates_ ;
}

#endif // MINESWEEPERBUTTON_H

