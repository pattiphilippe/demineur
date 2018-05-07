#include "configurationdialog.h"
#include "ui_configurationdialog.h"

#include <iostream>
using namespace std;

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
    double nbCases (nbLignes_ * nbColonnes_);
    setPctBombes(static_cast<unsigned>(nbBombes_ / nbCases * 100));
}
void ConfigurationDialog::setNbColonnes(int nbColonnes){
    nbColonnes_ = nbColonnes;
    double nbCases (nbLignes_ * nbColonnes_);
    setPctBombes(static_cast<unsigned>(nbBombes_ / nbCases * 100));
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
