#include "GUI/mainwindow.h"
#include "Gui/ui_mainwindow.h"
#include "Gui/configurationdialog.h"
#include "GUI/MineFieldObserver.h"
#include "GUI/enddialog.h"
#include "Scores/Score.h"
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>


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
    mineFieldObserver_{nullptr},
    timer{nullptr}
{
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

/**
 * @brief MainWindow::connexion
 * Connect all the menu content to actions
 */
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

/**
 * @brief MainWindow::creerPartie
 * Launch configuration window where you can select all the parameter of the game.
 * It also launch the minefieldObserver wich display the game.
 */
void MainWindow::creerPartie(){
    new QLabel("");
    ConfigurationDialog cd{this};
    auto retour = cd.exec();
    if (retour == QDialog::Rejected) return;
    game_ = new Game(cd.nbLignes(), cd.nbColonnes(), cd.nbBombes());
    ui->actionNouveau->setEnabled(false);
    ui->actionFermer->setEnabled(true);
    timer = new LcdTimer(game_);
    ui->centralWidget->layout()->addWidget(timer);
    observerMineField(true);
    connect(mineFieldObserver_, SIGNAL(gameOver()),
                this, SLOT(endGame()));
}

/**
 * @brief MainWindow::endGame
 * Launch endDialog window wich tells the user if he won or lost. Get the username and register a score if he won.
 */
void MainWindow::endGame(){
    EndDialog ed{this};
    string pseudo ;

    switch (game_->getGameState()) {

    case WON:
        ed.displayWin();
        break;
    case LOST:
        ed.displayLost();
        break;
    default:
        break;
    }
    auto retour = ed.exec();
    if(retour == QDialog::Rejected) return ;
    if(ed.getPseudo() !="" && game_->getGameState() == WON){
        pseudo = ed.getPseudo().toStdString();
        const BoardPublic & b = game_->getBoard();
        showScores(saveScore(Score(game_->getScore().count(), pseudo), b.getNbLines(), b.getNbColumns(), b.getNbBombs())
               ,b.getNbLines(), b.getNbColumns(), b.getNbBombs());
    }
}

/**
 * @brief MainWindow::fermerPartie
 * Provide safe close and destruction for the components of mainWindow.
 */
void MainWindow::fermerPartie(){
    delete timer;
    timer = nullptr;
    delete mineFieldObserver_;
    mineFieldObserver_ = nullptr;
    delete game_;
    game_ = nullptr;
    ui->actionNouveau->setEnabled(true);
    ui->actionFermer->setEnabled(false);
}
void MainWindow::showScores(vector<Score> scores, int nbLines, int nbCols, unsigned nbBombs){
    int i{4};
    QMessageBox::information(this, tr("Scores"),
                    scoresMsg.arg(nbLines).arg(nbCols).arg(nbBombs)
                             .arg(QString::fromStdString(scores.at(i).getPlayer()))
                             .arg(scores.at(--i).getTime())
                             .arg(QString::fromStdString(scores.at(i).getPlayer()))
                             .arg(scores.at(--i).getTime())
                             .arg(QString::fromStdString(scores.at(i).getPlayer()))
                             .arg(scores.at(--i).getTime())
                             .arg(QString::fromStdString(scores.at(i).getPlayer()))
                             .arg(scores.at(--i).getTime())
                             .arg(QString::fromStdString(scores.at(i).getPlayer()))
                             .arg(scores.at(i).getTime())
                             );
}

/**
 * @brief MainWindow::scores
 * Display a new window with scores.
 */
void MainWindow::scores(){
    ConfigurationDialog cd{this};
    auto retour = cd.exec();
    if(retour == QDialog::Rejected) return;
    showScores(getScores(cd.nbLignes(), cd.nbColonnes(), cd.nbBombes()), cd.nbLignes(), cd.nbColonnes(), cd.nbBombes());
}

/**
 * @brief MainWindow::aide
 * Show help dialog.
 */
void MainWindow::aide(){

    QMessageBox::information(this, tr("Aide"),
         tr("Ce jeu du d??mineur vous permet de:"
            "<ul>"
            "<li>r??v??ler une case : si c'est une bombe, vous avez perdu. "
            "Si elle est voisine d'une bombe, vous saurez le nombre de bombes ?? cot??."
            "Sinon, cela d??voilera de la m??me fa??on toutes les cases voisines.</li>"
            "<li>marquer une case : ceci n'a aucun effet secondaire.</li>"
            "</ul>"
            "En r??v??lant toutes les cases non pi??g??es par des bombes, vous gagnez la partie. "
            "Gagnez le plus vite possible la partie pour ??tre parmi les meilleurs! <br/>"
            "<b>Bon amusement !</b>"));
}

/**
 * @brief MainWindow::observerMineField
 * launch the observerMinefield.
 * @param enabled True if you want to activate the observerMinefield.
 */
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
