/********************************************************************************
** Form generated from reading UI file 'enddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDDIALOG_H
#define UI_ENDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_EndDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *pseudoEdit;
    QLabel *lblEndText;

    void setupUi(QDialog *EndDialog)
    {
        if (EndDialog->objectName().isEmpty())
            EndDialog->setObjectName(QStringLiteral("EndDialog"));
        EndDialog->resize(266, 216);
        gridLayout = new QGridLayout(EndDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(EndDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        pseudoEdit = new QLineEdit(EndDialog);
        pseudoEdit->setObjectName(QStringLiteral("pseudoEdit"));
        pseudoEdit->setEnabled(false);

        gridLayout->addWidget(pseudoEdit, 1, 1, 1, 1);

        lblEndText = new QLabel(EndDialog);
        lblEndText->setObjectName(QStringLiteral("lblEndText"));
        lblEndText->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblEndText, 0, 0, 1, 3);


        retranslateUi(EndDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EndDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EndDialog, SLOT(reject()));
        QObject::connect(pseudoEdit, SIGNAL(textChanged(QString)), EndDialog, SLOT(setPseudo(QString)));

        QMetaObject::connectSlotsByName(EndDialog);
    } // setupUi

    void retranslateUi(QDialog *EndDialog)
    {
        EndDialog->setWindowTitle(QApplication::translate("EndDialog", "Dialog", nullptr));
        lblEndText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EndDialog: public Ui_EndDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDDIALOG_H
