#include "minefieldobserver.h"

MineFieldObserver::MineFieldObserver(Game *sdo):
    sdo_{sdo}
{
    sdo_->registerObserver(this);
}

void MineFieldObserver::refresh()
{
    for (int line = 0; line < sdo_->getBoard().getNbLines(); line++){
        for (int column=0; column < sdo_->getBoard().getNbColumns(); column++){
            //TODO Ajouter les widgets pour afficher chaque case une à une (Utiliser this(gridboard) pour tout positionner)
        }
    }
}

MineFieldObserver::~MineFieldObserver()
{
    sdo_->unregisterObserver(this);
}

void MineFieldObserver::closeEvent(QCloseEvent *e)
{

}
