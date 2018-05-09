#ifndef CONFIGURATIONDIALOG_H
#define CONFIGURATIONDIALOG_H

#include <QDialog>

namespace Ui {
class ConfigurationDialog;
}

class ConfigurationDialog : public QDialog
{
    Q_OBJECT
private slots:
    void setNbLignes(int);
    void setNbColonnes(int);
    void setNbBombes(int);
    void setPctBombes(int);
    void nbBombsMode(bool);
    void pctBombsMode(bool);

public:
    explicit ConfigurationDialog(QWidget *parent = 0);
    ~ConfigurationDialog();
    inline int nbLignes() const;
    inline int nbColonnes() const;
    inline unsigned nbBombes() const;

private:
    Ui::ConfigurationDialog *ui;
    bool withNbBombs;
    int nbLignes_;
    int nbColonnes_;
    unsigned nbBombes_;
};

/**
 * @brief ConfigurationDialog::nbLignes
 * @return number of lines selected
 */
int ConfigurationDialog::nbLignes() const {
    return nbLignes_;
}

/**
 * @brief ConfigurationDialog::nbColonnes
 * @return number of columns selected
 */
int ConfigurationDialog::nbColonnes() const {
    return nbColonnes_;
}

/**
 * @brief ConfigurationDialog::nbBombes
 * @return number of bombs selected
 */
unsigned ConfigurationDialog::nbBombes() const {
    return nbBombes_;
}

#endif // CONFIGURATIONDIALOG_H
