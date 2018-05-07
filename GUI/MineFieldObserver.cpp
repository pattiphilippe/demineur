#include "MineFieldObserver.h"
#include "QPushButton"
#include "MineSweeperButton.h"
#include "Model/Case.h"


MineFieldObserver::MineFieldObserver(Game * sdo):
    sdo_{sdo},
    gridLayout_{this}
{
    sdo_->registerObserver(this);
    init(sdo);

}

void MineFieldObserver::init(const nvs::Subject *sdo)
{
    if(sdo == sdo_){
        for (int line = 0; line < sdo_->getBoard().getNbLines(); line++){
            for (int column=0; column < sdo_->getBoard().getNbColumns(); column++){
                MineSweeperButton* button = new MineSweeperButton(Coordinates(line,column));
                button->setIcon (QIcon(QString(":/ressources/img/Minesweeper_dft.png")));
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
        //Delete space between cases
        gridLayout_.setHorizontalSpacing(0);
        gridLayout_.setVerticalSpacing(1);
    }
}

void MineFieldObserver::update(const nvs::Subject *sdo)
{
    if(sdo == sdo_){
        for (int line = 0; line < sdo_->getBoard().getNbLines(); line++){
            for (int column=0; column < sdo_->getBoard().getNbColumns(); column++){
                MineSweeperButton* button = dynamic_cast<MineSweeperButton*>(gridLayout_.itemAtPosition(line,column)->widget());
                const CasePublic * c {sdo_->getBoard().getCase(button->getCoordinates())};
                QString arg;
                switch(c->getState()){
                case marked:
                    arg = QString("flag");
                    break;
                case revealed:
                    if(c->isBomb()){
                        arg = QString("mine");
                    } else {
                        arg = QString::fromStdString(to_string(c->getNbNearBombs()));
                    }
                    break;
                default:
                    arg = QString("dft");
                    break;
                }
                QString imgName = QString(":/ressources/img/Minesweeper_%1.png").arg(arg);
                button->setIcon(QIcon(imgName));
            }
        }
    }
    if(sdo_->getGameState() == WON || sdo_->getGameState() == LOST){
        desactivateField();
        emit gameOver();
    }
}


void MineFieldObserver::desactivateField()
{
    for (int line = 0; line < sdo_->getBoard().getNbLines(); line++){
        for (int column=0; column < sdo_->getBoard().getNbColumns(); column++){
            MineSweeperButton* button = dynamic_cast<MineSweeperButton*>(gridLayout_.itemAtPosition(line,column)->widget());
            button->disconnect(button, SIGNAL(rightButtonClicked()),
                               this, SLOT(rightClicked()));
            button->disconnect(button, SIGNAL(rightButtonClicked()),
                               this, SLOT(rightClicked()));
        }
    }

}

MineFieldObserver::~MineFieldObserver()
{
    sdo_->unregisterObserver(this);
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
