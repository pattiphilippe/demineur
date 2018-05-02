#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Model/Game.h"
#include "minefieldobserver.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void creerPartie();
    void fermerPartie();
    void aide();
    void scores();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QAction *action_Scores;
    QAction *action_Aide;
    Game *game_;
    QString scoresMsg;
    MineFieldObserver * mineFieldObserver_;
    QLayout *mineFieldLayout;

    void connexion();
    void observerMineField(bool);
};

#endif // MAINWINDOW_H
