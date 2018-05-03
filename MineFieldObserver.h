#ifndef MINEFIELDOBSERVER_H
#define MINEFIELDOBSERVER_H

#include <QFrame>
#include <QGridLayout>
#include <Libraries/observer/observer.h>
#include <Model/Game.h>
#include <QSignalMapper>


class MineFieldObserver: public QFrame, public nvs::Observer{

    Q_OBJECT
private slots:
    void rightClicked();
    void leftClicked();

public:

    MineFieldObserver(Game * sdo);

    virtual void update(const nvs::Subject *);
    ~MineFieldObserver();
    void closeEvent(QCloseEvent *event);

private:
    Game * sdo_;
    QGridLayout gridLayout_;

    void init(const nvs::Subject *);



};

#endif // MINEFIELDOBSERVER_H
