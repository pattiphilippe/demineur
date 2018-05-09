#include "enddialog.h"
#include "ui_enddialog.h"

EndDialog::EndDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndDialog),
    pseudo_{}
{
    ui->setupUi(this);
}

EndDialog::~EndDialog()
{
    delete ui;
    ui = nullptr;
}

void EndDialog::setPseudo(QString newPseudo)
{
    pseudo_ = newPseudo ;
}

/**
 * @brief EndDialog::displayWin
 * Display win message in label and activate the lineEdit in the GUI
 */
void EndDialog::displayWin()
{
    ui->lblEndText->setText("Bravo ! Vous avez gagné ! \n "
                            "Entrez votre nom ci dessous pour enregistrer votre score.");
    ui->pseudoEdit->setEnabled(true);
}

/**
 * @brief EndDialog::displayLost
 * Display lost message in label
 */
void EndDialog::displayLost()
{
    ui->lblEndText->setText("Une mine ! Vous avez perdu :/ \n Réessayez !");
}
