#include "GUI/mainwindow.h"
#include "GUI/ui_mainwindow.h"
#include "GUI/configurationdialog.h"
#include "Scores/Score.h"

#include <QMessageBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game_{nullptr},
    scoresMsg{tr("HALL OF FAME<br/><br/>"
                          "Lines : %1, Columns : %2, Nb bombs : %3<br/>"
                          "<ol>"
                          "<li>%4 : %5</li>"
                          "<li>%6 : %7</li>"
                          "<li>%8 : %9</li>"
                          "<li>%10 : %11</li>"
                          "<li>%12 : %13</li>"
                          "</ol>")},
    mineFieldObserver_{nullptr}

{
    //TODO Faire en sorte que le widget wDemineur ajuste sa taille avec la fenêtre (impossible de voir correctement les parties custom)
    ui->setupUi(this);
    action_Scores = ui->menuBar->addAction(tr("&Scores"));
    action_Scores->setShortcut(QKeySequence{tr("Ctrl+S")});
    action_Aide = ui->menuBar->addAction(tr("&Aide"));
    action_Aide->setShortcut(QKeySequence{tr("Ctrl+A")});
    this->setWindowIcon((QIcon(QString(":/ressources/img/Minesweeper_mine.png"))));
    this->setWindowTitle("Minesweeper");
    connexion();
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete mineFieldObserver_;
    mineFieldObserver_ = nullptr;
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
    connect(action_Scores, &QAction::triggered,
            this, &MainWindow::scores);
}

void MainWindow::creerPartie(){
    new QLabel("");
    ConfigurationDialog cd{this};
    auto retour = cd.exec();
    if (retour == QDialog::Rejected) return;
    game_ = new Game(cd.nbLignes(), cd.nbColonnes(), cd.nbBombes());
    ui->actionNouveau->setEnabled(false);
    ui->actionFermer->setEnabled(true);
    observerMineField(true);
}
void MainWindow::fermerPartie(){
    delete mineFieldObserver_;
    mineFieldObserver_ = nullptr;
    delete game_;
    game_ = nullptr;
    ui->actionNouveau->setEnabled(true);
    ui->actionFermer->setEnabled(false);
}
void MainWindow::scores(){
    ConfigurationDialog cd{this};
    auto retour = cd.exec();
    if(retour == QDialog::Rejected) return;
    vector<Score> scores = getScores(cd.nbLignes(), cd.nbColonnes(), cd.nbBombes());
    int i{0};
    QMessageBox::information(this, tr("Scores"),
                    scoresMsg.arg(cd.nbLignes()).arg(cd.nbColonnes()).arg(cd.nbBombes())
                             .arg(QString::fromStdString(scores.at(i).getPlayer()))
                             .arg(scores.at(i).getTime())
                             .arg(QString::fromStdString(scores.at(++i).getPlayer()))
                             .arg(scores.at(i).getTime())
                             .arg(QString::fromStdString(scores.at(++i).getPlayer()))
                             .arg(scores.at(i).getTime())
                             .arg(QString::fromStdString(scores.at(++i).getPlayer()))
                             .arg(scores.at(i).getTime())
                             .arg(QString::fromStdString(scores.at(++i).getPlayer()))
                             .arg(scores.at(i).getTime())
                             );
}
void MainWindow::aide(){

    QMessageBox::information(this, tr("Aide"),
         tr("Ce jeu du démineur vous permet de:"
            "<ul>"
            "<li>révéler une case : si c'est une bombe, vous avez perdu. "
            "Si elle est voisine d'une bombe, vous saurez le nombre de bombes à coté."
            "Sinon, cela dévoilera de la même façon toutes les cases voisines.</li>"
            "<li>marquer une case : ceci n'a aucun effet secondaire.</li>"
            "</ul>"
            "En révélant toutes les cases non piégées par des bombes, vous gagnez la partie. "
            "Gagnez le plus vite possible la partie pour être parmi les meilleurs! <br/>"
            "<b>Bon amusement !</b>"));
}

void MainWindow::observerMineField(bool enabled){
    if(enabled){
        try{
            if(mineFieldObserver_==nullptr){
                mineFieldObserver_ = new MineFieldObserver{game_};
                //ui->verticalLayout->addWidget(mineFieldObserver_);
                ui->centralWidget->layout()->addWidget(mineFieldObserver_);
            }
            mineFieldObserver_->show();
        } catch (const std::string & e){
            QMessageBox::critical(this, tr("MineField observer error"),
                                  QString::fromStdString(e));
        }
    } else {
        if(mineFieldObserver_ != nullptr){
            mineFieldObserver_->hide();
        }
    }
}
