#ifndef MINEFIELDOBSERVER_H
#define MINEFIELDOBSERVER_H

#include <QLabel>
#include <QGridLayout>
#include <Libraries/observer/observer.h>
#include <Model/Game.h>


class MineFieldObserver: public QGridLayout, public nvs::Observer
{

public:
    MineFieldObserver(Game * sdo);

    virtual void refresh();
    ~MineFieldObserver();
    void closeEvent(QCloseEvent *event);

private:
    Game * sdo_;

};

#endif // MINEFIELDOBSERVER_H
