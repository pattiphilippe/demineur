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
    ui->lblEndText->setText("Congratulation ! You have won ! \n "
                            "Type your name below to regiter your score");
    ui->pseudoEdit->setEnabled(true);
}

void EndDialog::displayLost()
{
    ui->lblEndText->setText("Game over, you lost. \n Try again !");
}
