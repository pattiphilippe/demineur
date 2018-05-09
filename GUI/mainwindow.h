#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Model/Game.h"
#include "Scores/Score.h"
#include "MineFieldObserver.h"
#include "LcdTimer.h"

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
    void endGame();

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
    LcdTimer * timer;

    void connexion();
    void observerMineField(bool);
    void showScores(vector<Score>, int nbLines, int nbCols, unsigned nbBombs);
};

#endif // MAINWINDOW_H
