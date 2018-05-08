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

void EndDialog::displayWin()
{
    ui->lblEndText->setText("Bravo ! Vous avez gagné ! \n "
                            "Entrez votre nom ci dessous pour enregistrer votre score.");
    ui->pseudoEdit->setEnabled(true);
}

void EndDialog::displayLost()
{
    ui->lblEndText->setText("Une mine ! Vous avez perdu :/ \n Réessayez !");
}
