#include "minefieldobserver.h"
#include "QPushButton"


MineFieldObserver::MineFieldObserver(Game * sdo):
    sdo_{sdo},
    gridLayout_{this}
{
    sdo_->registerObserver(this);
    update(sdo);
}

void MineFieldObserver::update(const nvs::Subject *sdo)
{
    if(sdo == sdo_){
        for (int line = 0; line < sdo_->getBoard().getNbLines(); line++){
            for (int column=0; column < sdo_->getBoard().getNbColumns(); column++){
                //TODO Créer une classe MineSweeperButton qui viendrait implémenter QPushButton
                QPushButton* button = new QPushButton("");

                //Button Styling
                button->setAttribute(Qt::WA_LayoutUsesWidgetRect);
                button->setMaximumHeight(30);
                button->setMaximumWidth(30);
                button->setIcon (QIcon(QString(":/ressources/img/Minesweeper_dft.png")));
                button->setIconSize (QSize(30,30));

                gridLayout_.addWidget(button, line, column);
            }
        }
        //Delete space between cases
        gridLayout_.setSpacing(1);
    }

}

MineFieldObserver::~MineFieldObserver()
{
    sdo_->unregisterObserver(this);
}

void MineFieldObserver::closeEvent(QCloseEvent *e)
{

}
