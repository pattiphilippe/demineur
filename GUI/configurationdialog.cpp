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
    ui = nullptr;
}

void ConfigurationDialog::setNbLignes(int nbLignes){
    nbLignes_ = nbLignes;
    setPctBombes(static_cast<unsigned>(ui->pctBombes->value()));
}
void ConfigurationDialog::setNbColonnes(int nbColonnes){
    nbColonnes_ = nbColonnes;
    setPctBombes(static_cast<unsigned>(ui->pctBombes->value()));
}
void ConfigurationDialog::setNbBombes(int nbBombes){
    nbBombes_ = static_cast<unsigned>(nbBombes);
}
void ConfigurationDialog::setPctBombes(int pctBombes){
    nbBombes_ = static_cast<unsigned>(nbLignes_ * nbColonnes_ * pctBombes / 100);
}
void ConfigurationDialog::nbBombsMode(bool nbBombsMode){
    ui->nbBombes->setEnabled(nbBombsMode);
    ui->pctBombes->setEnabled(!nbBombsMode);
}
void ConfigurationDialog::pctBombsMode(bool pctBombsMode){
    nbBombsMode(!pctBombsMode);
}
