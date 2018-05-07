/********************************************************************************
** Form generated from reading UI file 'configurationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATIONDIALOG_H
#define UI_CONFIGURATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigurationDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpinBox *nbLignes;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *nbColonnes;
    QGroupBox *groupBox_2;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rbNbBombes;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *nbBombes;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *rbPctBombes;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *pctBombes;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfigurationDialog)
    {
        if (ConfigurationDialog->objectName().isEmpty())
            ConfigurationDialog->setObjectName(QStringLiteral("ConfigurationDialog"));
        ConfigurationDialog->resize(420, 403);
        widget = new QWidget(ConfigurationDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 391, 361));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 20, 361, 131));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        nbLignes = new QSpinBox(widget1);
        nbLignes->setObjectName(QStringLiteral("nbLignes"));
        nbLignes->setMinimumSize(QSize(60, 25));
        nbLignes->setMinimum(5);
        nbLignes->setValue(10);

        horizontalLayout->addWidget(nbLignes);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        nbColonnes = new QSpinBox(widget1);
        nbColonnes->setObjectName(QStringLiteral("nbColonnes"));
        nbColonnes->setMinimumSize(QSize(60, 25));
        nbColonnes->setMinimum(5);
        nbColonnes->setValue(10);

        horizontalLayout_2->addWidget(nbColonnes);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        widget2 = new QWidget(groupBox_2);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 30, 361, 111));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        rbNbBombes = new QRadioButton(widget2);
        rbNbBombes->setObjectName(QStringLiteral("rbNbBombes"));

        horizontalLayout_3->addWidget(rbNbBombes);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        nbBombes = new QSpinBox(widget2);
        nbBombes->setObjectName(QStringLiteral("nbBombes"));
        nbBombes->setEnabled(false);
        nbBombes->setMinimumSize(QSize(60, 25));
        nbBombes->setMinimum(2);
        nbBombes->setValue(10);

        horizontalLayout_3->addWidget(nbBombes);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        rbPctBombes = new QRadioButton(widget2);
        rbPctBombes->setObjectName(QStringLiteral("rbPctBombes"));
        rbPctBombes->setChecked(true);

        horizontalLayout_4->addWidget(rbPctBombes);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        pctBombes = new QSpinBox(widget2);
        pctBombes->setObjectName(QStringLiteral("pctBombes"));
        pctBombes->setMinimumSize(QSize(60, 25));
        pctBombes->setMinimum(5);
        pctBombes->setMaximum(95);
        pctBombes->setValue(10);

        horizontalLayout_4->addWidget(pctBombes);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(ConfigurationDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigurationDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigurationDialog, SLOT(reject()));
        QObject::connect(nbLignes, SIGNAL(valueChanged(int)), ConfigurationDialog, SLOT(setNbLignes(int)));
        QObject::connect(nbColonnes, SIGNAL(valueChanged(int)), ConfigurationDialog, SLOT(setNbColonnes(int)));
        QObject::connect(nbBombes, SIGNAL(valueChanged(int)), ConfigurationDialog, SLOT(setNbBombes(int)));
        QObject::connect(pctBombes, SIGNAL(valueChanged(int)), ConfigurationDialog, SLOT(setPctBombes(int)));
        QObject::connect(rbNbBombes, SIGNAL(toggled(bool)), ConfigurationDialog, SLOT(nbBombsMode(bool)));
        QObject::connect(rbPctBombes, SIGNAL(toggled(bool)), ConfigurationDialog, SLOT(pctBombsMode(bool)));

        QMetaObject::connectSlotsByName(ConfigurationDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigurationDialog)
    {
        ConfigurationDialog->setWindowTitle(QApplication::translate("ConfigurationDialog", "Configuration - [Preview]", nullptr));
        groupBox->setTitle(QApplication::translate("ConfigurationDialog", "Lines and Columns", nullptr));
        label->setText(QApplication::translate("ConfigurationDialog", "Nombre de lignes :", nullptr));
        label_2->setText(QApplication::translate("ConfigurationDialog", "Nombre de colonnes :", nullptr));
        groupBox_2->setTitle(QApplication::translate("ConfigurationDialog", "Bombs", nullptr));
        rbNbBombes->setText(QApplication::translate("ConfigurationDialog", "Nombre de bombes", nullptr));
        rbPctBombes->setText(QApplication::translate("ConfigurationDialog", "Pct de bombes (%) ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigurationDialog: public Ui_ConfigurationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATIONDIALOG_H
