/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionShowcases;
    QAction *action_Fish;
    QAction *action_Equipment;
    QAction *action_Peripherals;
    QAction *actionCommunities;
    QAction *action_Friends;
    QAction *action_Exit;
    QWidget *centralwidget;
    QLabel *mainthread;
    QPushButton *prevButton;
    QPushButton *nextButton;
    QLabel *PositionLabel;
    QMenuBar *menubar;
    QMenu *menuTabs;
    QMenu *menuProfile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 800);
        MainWindow->setMinimumSize(QSize(900, 800));
        MainWindow->setMaximumSize(QSize(900, 800));
        actionShowcases = new QAction(MainWindow);
        actionShowcases->setObjectName("actionShowcases");
        action_Fish = new QAction(MainWindow);
        action_Fish->setObjectName("action_Fish");
        action_Equipment = new QAction(MainWindow);
        action_Equipment->setObjectName("action_Equipment");
        action_Peripherals = new QAction(MainWindow);
        action_Peripherals->setObjectName("action_Peripherals");
        actionCommunities = new QAction(MainWindow);
        actionCommunities->setObjectName("actionCommunities");
        action_Friends = new QAction(MainWindow);
        action_Friends->setObjectName("action_Friends");
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName("action_Exit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainthread = new QLabel(centralwidget);
        mainthread->setObjectName("mainthread");
        mainthread->setGeometry(QRect(10, 35, 880, 400));
        mainthread->setMinimumSize(QSize(880, 400));
        mainthread->setMaximumSize(QSize(880, 400));
        mainthread->setSizeIncrement(QSize(0, 0));
        mainthread->setAutoFillBackground(true);
        mainthread->setFrameShape(QFrame::WinPanel);
        mainthread->setMargin(2);
        prevButton = new QPushButton(centralwidget);
        prevButton->setObjectName("prevButton");
        prevButton->setGeometry(QRect(13, 13, 80, 18));
        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName("nextButton");
        nextButton->setGeometry(QRect(97, 13, 80, 18));
        PositionLabel = new QLabel(centralwidget);
        PositionLabel->setObjectName("PositionLabel");
        PositionLabel->setGeometry(QRect(181, 13, 701, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 17));
        menuTabs = new QMenu(menubar);
        menuTabs->setObjectName("menuTabs");
        menuProfile = new QMenu(menubar);
        menuProfile->setObjectName("menuProfile");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuTabs->menuAction());
        menubar->addAction(menuProfile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuTabs->addAction(actionShowcases);
        menuTabs->addAction(action_Fish);
        menuTabs->addAction(action_Equipment);
        menuTabs->addAction(action_Peripherals);
        menuTabs->addSeparator();
        menuTabs->addAction(action_Exit);
        menuProfile->addAction(actionCommunities);
        menuProfile->addAction(action_Friends);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionShowcases->setText(QCoreApplication::translate("MainWindow", "&Showcases", nullptr));
        action_Fish->setText(QCoreApplication::translate("MainWindow", "&Fish", nullptr));
        action_Equipment->setText(QCoreApplication::translate("MainWindow", "&Equipment", nullptr));
        action_Peripherals->setText(QCoreApplication::translate("MainWindow", "&Peripherals", nullptr));
        actionCommunities->setText(QCoreApplication::translate("MainWindow", "&Communities", nullptr));
        action_Friends->setText(QCoreApplication::translate("MainWindow", "&Friends", nullptr));
        action_Exit->setText(QCoreApplication::translate("MainWindow", "&Exit", nullptr));
        mainthread->setText(QString());
        prevButton->setText(QCoreApplication::translate("MainWindow", "Prev", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        PositionLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuTabs->setTitle(QCoreApplication::translate("MainWindow", "Tabs", nullptr));
        menuProfile->setTitle(QCoreApplication::translate("MainWindow", "Profile", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
