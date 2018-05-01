#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Model/Game.h"

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

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QAction *action_Aide;
    Game *game_;

    void connexion();
};

#endif // MAINWINDOW_H
