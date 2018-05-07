#ifndef LCDTIMER_H
#define LCDTIMER_H

#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include "Libraries/observer/subject.h"
#include "Model/Game.h"

class LcdTimer : public QLCDNumber
{
    Q_OBJECT
public:
    explicit LcdTimer(Game * sdo, QWidget *parent = nullptr);
private:
    QTimer timer_;
    QString time_;
    Game * sdo_;

private slots:
    void showTime();


};

#endif // LCDTIMER_H
