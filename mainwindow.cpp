#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configurationdialog.h"

#include <QMessageBox>


#include <iostream>
        using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game_{nullptr}
{
    ui->setupUi(this);
    action_Scores = ui->menuBar->addAction(tr("&Scores"));
    action_Scores->setShortcut(QKeySequence{tr("Ctrl+S")});
    action_Aide = ui->menuBar->addAction(tr("&Aide"));
    action_Aide->setShortcut(QKeySequence{tr("Ctrl+A")});
    connexion();
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
}

void MainWindow::connexion(){
    connect(ui->action_Quitter, &QAction::triggered,
            &QCoreApplication::quit);
    connect(ui->actionNouveau, &QAction::triggered,
            this, &MainWindow::creerPartie);
    connect(ui->actionFermer, &QAction::triggered,
            this, &MainWindow::fermerPartie);
    connect(action_Aide, &QAction::triggered,
            this, &MainWindow::aide);
}

void MainWindow::creerPartie(){
    ConfigurationDialog cd{this};
    auto retour = cd.exec();
    if (retour == QDialog::Rejected) return;
    try{
        game_ = new Game(cd.nbLignes(), cd.nbColonnes(), cd.nbBombes());
    } catch (const exception & e){
        cout << e.what() << endl;
    }
    ui->actionNouveau->setEnabled(false);
    ui->actionFermer->setEnabled(true);
}
void MainWindow::fermerPartie(){
    delete game_;
    game_ = nullptr;
    ui->actionNouveau->setEnabled(true);
    ui->actionFermer->setEnabled(false);
}
void MainWindow::aide(){

    QMessageBox::information(this, tr("Aide"),
         tr("Ce jeu du pendu vous permet de choisir:"
            "<ul>"
            "<li>le nombre de lettres erronées permises;</li>"
            "<li>le fichier dans lequel le mot à trouver est puisé</li>"
            "</ul>"
            "Notez que si vous choisissez un nombre de vies initiallement "
            "différent de 6, la vue potence n'est pas disponible.<br/>"
            "Veillez à ce que le fichier ne contienne pas"
                " de ligne vide sauf pour le terminer.<br/><br/>"
            "<b>Bon amusement !</b><br /><br />"
            "<b>Ceci est une aide pour le Pendu, pas pour le Démineur.<br />"
            "Bon courage!</b>"));
}
