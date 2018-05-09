#ifndef ENDDIALOG_H
#define ENDDIALOG_H

#include "QDialog"

namespace Ui {
class EndDialog;
}

class EndDialog : public QDialog
{
    Q_OBJECT
private slots:
    void setPseudo(QString);

public:
    explicit EndDialog(QWidget *parent = 0);
    ~EndDialog();

    void displayWin();
    void displayLost();

    inline QString getPseudo() const;

private:
    Ui::EndDialog *ui;
    QString pseudo_;
};

/**
 * @brief EndDialog::getPseudo
 * @return Username typed by the user
 */
QString EndDialog::getPseudo() const {
    return pseudo_;
}


#endif // ENDDIALOG_H
