#include "MineFieldObserver.h"
#include "QPushButton"
#include "MineSweeperButton.h"
#include "Model/Case.h"


MineFieldObserver::MineFieldObserver(Game * sdo):
    sdo_{sdo},
    gridLayout_{this}
{
    sdo_->registerObserver(this);
    update(sdo);

    //Delete space between cases
    gridLayout_.setHorizontalSpacing(0);
    gridLayout_.setVerticalSpacing(1);
}


void MineFieldObserver::update(const nvs::Subject *sdo)
{

    //Check case state and set image on the button
    //TODO C'est moche, à améliorer

    if(sdo == sdo_){
        for (int line = 0; line < sdo_->getBoard().getNbLines(); line++){
            for (int column=0; column < sdo_->getBoard().getNbColumns(); column++){

                MineSweeperButton* button = new MineSweeperButton(Coordinates(line,column));
                if(sdo_->getBoard().getCase(button->getCoordinates())->getState() == dft){
                    button->setIcon (QIcon(QString(":/ressources/img/Minesweeper_dft.png")));
                }else if(sdo_->getBoard().getCase(button->getCoordinates())->getState() == marked){
                    button->setIcon (QIcon(QString(":/ressources/img/Minesweeper_flag.png")));
                }else if(sdo_->getBoard().getCase(button->getCoordinates())->isBomb()){
                    button->setIcon (QIcon(QString(":/ressources/img/Minesweeper_mine.png")));
                }else if(sdo_->getBoard().getCase(button->getCoordinates())->getState()){
                    switch (sdo_->getBoard().getCase(button->getCoordinates())->getNbNearBombs()) {
                    case 0:
                        button->setIcon (QIcon(QString(":/ressources/img/Minesweeper_0.png")));
                        break;
                    case 1:
                        button->setIcon (QIcon(QString(":/ressources/img/Minesweeper_1.png")));
                        break;
                    case 2:
                        button->setIcon (QIcon(QString(":/ressources/img/Minesweeper_2.png")));
                        break;
                    case 3:
                        button->setIcon (QIcon(QString(":/ressources/img/Minesweeper_3.png")));
                        break;
                    case 4:
                        button->setIcon (QIcon(QString(":/ressources/img/Minesweeper_4.png")));
                        break;
                    case 5:
                        button->setIcon (QIcon(QString(":/ressources/img/Minesweeper_5.png")));
                        break;
                    case 6:
                        button->setIcon (QIcon(QString(":/ressources/img/Minesweeper_6.png")));
                        break;
                    case 7:
                        button->setIcon (QIcon(QString(":/ressources/img/Minesweeper_7.png")));
                        break;
                    case 8:
                        button->setIcon (QIcon(QString(":/ressources/img/Minesweeper_8.png")));
                        break;
                    default:
                        break;
                    }
                }
                //Button Styling
                button->setMaximumHeight(30);
                button->setMaximumWidth(30);

                button->setIconSize (QSize(30,30));
                gridLayout_.addWidget(button, line, column);

                connect(button, SIGNAL(clicked()),
                        this, SLOT(leftClicked()));

                connect(button, SIGNAL(rightButtonClicked()),
                        this, SLOT(rightClicked()));
            }
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

void MineFieldObserver::leftClicked()
{
    //Get the button that emited the signal
    MineSweeperButton * button = qobject_cast<MineSweeperButton*>(sender());
    sdo_->reveal(button->getCoordinates());
    update(sdo_);
}

void MineFieldObserver::rightClicked()
{
    //Get the button that emited the signal
    MineSweeperButton * button = qobject_cast<MineSweeperButton*>(sender());
    sdo_->mark(button->getCoordinates());
    update(sdo_);
}
