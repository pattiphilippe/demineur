/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNouveau;
    QAction *actionFermer;
    QAction *action_Quitter;
    QWidget *centralWidget;
    QWidget *wDemineur;
    QMenuBar *menuBar;
    QMenu *menuJeu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionNouveau = new QAction(MainWindow);
        actionNouveau->setObjectName(QStringLiteral("actionNouveau"));
        actionFermer = new QAction(MainWindow);
        actionFermer->setObjectName(QStringLiteral("actionFermer"));
        actionFermer->setEnabled(false);
        action_Quitter = new QAction(MainWindow);
        action_Quitter->setObjectName(QStringLiteral("action_Quitter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        wDemineur = new QWidget(centralWidget);
        wDemineur->setObjectName(QStringLiteral("wDemineur"));
        wDemineur->setGeometry(QRect(10, 10, 381, 241));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuJeu = new QMenu(menuBar);
        menuJeu->setObjectName(QStringLiteral("menuJeu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuJeu->menuAction());
        menuJeu->addAction(actionNouveau);
        menuJeu->addAction(actionFermer);
        menuJeu->addAction(action_Quitter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "D\303\251mineur", Q_NULLPTR));
        actionNouveau->setText(QApplication::translate("MainWindow", "&Nouveau", Q_NULLPTR));
        actionNouveau->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
        actionFermer->setText(QApplication::translate("MainWindow", "&Fermer", Q_NULLPTR));
        actionFermer->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
        action_Quitter->setText(QApplication::translate("MainWindow", "&Quitter", Q_NULLPTR));
        action_Quitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        menuJeu->setTitle(QApplication::translate("MainWindow", "&Jeu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
