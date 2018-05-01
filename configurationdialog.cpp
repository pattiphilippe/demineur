#include "configurationdialog.h"
#include "ui_configurationdialog.h"

ConfigurationDialog::ConfigurationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigurationDialog),
    withNbBombs{false},
    nbLignes_{10},
    nbColonnes_{10},
    nbBombes_{10}
{
    ui->setupUi(this);
}

ConfigurationDialog::~ConfigurationDialog()
{
    delete ui;
}

void ConfigurationDialog::setNbLignes(int nbLignes){
    nbLignes_ = nbLignes;
}
void ConfigurationDialog::setNbColonnes(int nbColonnes){
    nbColonnes_ = nbColonnes;
}
void ConfigurationDialog::setNbBombes(int nbBombes){
    nbBombes_ = static_cast<unsigned>(nbBombes);
}
void ConfigurationDialog::setPctBombes(int pctBombes){
    nbBombes_ = static_cast<unsigned>(nbLignes_ * nbColonnes_ / pctBombes);
}
void ConfigurationDialog::nbBombsMode(bool nbBombsMode){
    ui->nbBombes->setEnabled(nbBombsMode);
    ui->pctBombes->setEnabled(!nbBombsMode);
}
void ConfigurationDialog::pctBombsMode(bool pctBombsMode){
    nbBombsMode(!pctBombsMode);
}
