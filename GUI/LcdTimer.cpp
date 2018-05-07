#include "LcdTimer.h"
#include <QStyle>

LcdTimer::LcdTimer(Game * sdo, QWidget *parent) : QLCDNumber( parent),
    timer_{},
    time_{},
    sdo_{sdo}
{
    this->setStyleSheet(QString("background-color: black;"));
    this->setPalette(Qt::yellow);
    showTime();
    this->connect(&timer_, &QTimer::timeout, this, &LcdTimer::showTime);
    timer_.setInterval(1000);
    timer_.start();
}

void LcdTimer::showTime(){
    if(sdo_->getGameState() == LOST || sdo_->getGameState() == WON){
        timer_.stop();
    } else {
        int nbSecs = static_cast<int>(sdo_->getScore().count() + 0.5);
        time_ = QString(QTime(nbSecs / 3600, nbSecs / 60, nbSecs).toString("h:mm:ss"));
        display(time_);
    }
}
