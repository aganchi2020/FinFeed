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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *showcases;
    QAction *action_Fish;
    QAction *action_Equipment;
    QAction *action_Peripherals;
    QAction *actionCommunities;
    QAction *action_Friends;
    QAction *action_Exit;
    QAction *action_Help;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QLabel *label_9;
    QWidget *page;
    QLabel *label_8;
    QLabel *PositionLabel_2;
    QPushButton *prevButton_2;
    QPushButton *nextButton_2;
    QLabel *messageLabel_2;
    QPushButton *enterButton;
    QWidget *page_2;
    QWidget *page_3;
    QWidget *page_4;
    QWidget *page_5;
    QLabel *label_13;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton_3;
    QWidget *page_6;
    QLabel *label_7;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *page_7;
    QLabel *label_14;
    QPushButton *pushButton_7;
    QWidget *page_8;
    QPushButton *nextButton;
    QPushButton *prevButton;
    QLabel *messageLabel;
    QLabel *SubCommunityLabel;
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
        showcases = new QAction(MainWindow);
        showcases->setObjectName("showcases");
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
        action_Help = new QAction(MainWindow);
        action_Help->setObjectName("action_Help");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 0, 880, 740));
        stackedWidget->setFrameShape(QFrame::Box);
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        label_9 = new QLabel(page_1);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 20, 840, 25));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Historic")});
        font.setPointSize(20);
        label_9->setFont(font);
        label_9->setFrameShape(QFrame::Box);
        label_9->setScaledContents(false);
        label_9->setWordWrap(false);
        stackedWidget->addWidget(page_1);
        page = new QWidget();
        page->setObjectName("page");
        label_8 = new QLabel(page);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 20, 840, 25));
        label_8->setFont(font);
        label_8->setFrameShape(QFrame::Box);
        label_8->setScaledContents(false);
        label_8->setWordWrap(false);
        PositionLabel_2 = new QLabel(page);
        PositionLabel_2->setObjectName("PositionLabel_2");
        PositionLabel_2->setGeometry(QRect(200, 55, 660, 18));
        PositionLabel_2->setFrameShape(QFrame::Panel);
        prevButton_2 = new QPushButton(page);
        prevButton_2->setObjectName("prevButton_2");
        prevButton_2->setGeometry(QRect(110, 55, 80, 18));
        nextButton_2 = new QPushButton(page);
        nextButton_2->setObjectName("nextButton_2");
        nextButton_2->setGeometry(QRect(20, 55, 80, 18));
        messageLabel_2 = new QLabel(page);
        messageLabel_2->setObjectName("messageLabel_2");
        messageLabel_2->setGeometry(QRect(20, 80, 840, 600));
        messageLabel_2->setFrameShape(QFrame::Box);
        enterButton = new QPushButton(page);
        enterButton->setObjectName("enterButton");
        enterButton->setGeometry(QRect(400, 690, 80, 40));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        label_13 = new QLabel(page_5);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 20, 840, 25));
        label_13->setFont(font);
        label_13->setFrameShape(QFrame::Box);
        label_13->setScaledContents(false);
        label_13->setWordWrap(false);
        pushButton = new QPushButton(page_5);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 370, 171, 71));
        pushButton_2 = new QPushButton(page_5);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(530, 370, 171, 71));
        label = new QLabel(page_5);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 60, 841, 281));
        pushButton_3 = new QPushButton(page_5);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(60, 370, 181, 71));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        label_7 = new QLabel(page_6);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 20, 840, 25));
        label_7->setFont(font);
        label_7->setFrameShape(QFrame::Box);
        label_7->setScaledContents(false);
        label_7->setWordWrap(false);
        label_2 = new QLabel(page_6);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 60, 821, 341));
        pushButton_4 = new QPushButton(page_6);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(40, 400, 171, 71));
        pushButton_5 = new QPushButton(page_6);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(230, 400, 181, 71));
        pushButton_6 = new QPushButton(page_6);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(430, 400, 201, 71));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        label_14 = new QLabel(page_7);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 20, 840, 25));
        label_14->setFont(font);
        label_14->setFrameShape(QFrame::Box);
        label_14->setScaledContents(false);
        label_14->setWordWrap(false);
        pushButton_7 = new QPushButton(page_7);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(20, 70, 181, 81));
        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        nextButton = new QPushButton(page_8);
        nextButton->setObjectName("nextButton");
        nextButton->setGeometry(QRect(110, 55, 80, 18));
        prevButton = new QPushButton(page_8);
        prevButton->setObjectName("prevButton");
        prevButton->setGeometry(QRect(20, 55, 80, 18));
        messageLabel = new QLabel(page_8);
        messageLabel->setObjectName("messageLabel");
        messageLabel->setGeometry(QRect(20, 80, 840, 600));
        QFont font1;
        font1.setPointSize(36);
        messageLabel->setFont(font1);
        messageLabel->setFrameShape(QFrame::Box);
        messageLabel->setAlignment(Qt::AlignCenter);
        messageLabel->setWordWrap(true);
        SubCommunityLabel = new QLabel(page_8);
        SubCommunityLabel->setObjectName("SubCommunityLabel");
        SubCommunityLabel->setGeometry(QRect(20, 20, 840, 25));
        SubCommunityLabel->setFont(font);
        SubCommunityLabel->setFrameShape(QFrame::Box);
        SubCommunityLabel->setScaledContents(false);
        SubCommunityLabel->setWordWrap(false);
        PositionLabel = new QLabel(page_8);
        PositionLabel->setObjectName("PositionLabel");
        PositionLabel->setGeometry(QRect(200, 55, 660, 18));
        PositionLabel->setFrameShape(QFrame::Panel);
        stackedWidget->addWidget(page_8);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 26));
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
        menuTabs->addAction(showcases);
        menuTabs->addAction(action_Fish);
        menuTabs->addAction(action_Equipment);
        menuTabs->addAction(action_Peripherals);
        menuTabs->addSeparator();
        menuTabs->addAction(action_Exit);
        menuProfile->addAction(actionCommunities);
        menuProfile->addAction(action_Friends);
        menuHelp->addAction(action_Help);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        showcases->setText(QCoreApplication::translate("MainWindow", "&Showcases", nullptr));
        action_Fish->setText(QCoreApplication::translate("MainWindow", "&Fish", nullptr));
        action_Equipment->setText(QCoreApplication::translate("MainWindow", "&Equipment", nullptr));
        action_Peripherals->setText(QCoreApplication::translate("MainWindow", "&Peripherals", nullptr));
        actionCommunities->setText(QCoreApplication::translate("MainWindow", "&Communities", nullptr));
        action_Friends->setText(QCoreApplication::translate("MainWindow", "&Friends", nullptr));
        action_Exit->setText(QCoreApplication::translate("MainWindow", "&Exit", nullptr));
        action_Help->setText(QCoreApplication::translate("MainWindow", "&Help", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        label_8->setText(QString());
        PositionLabel_2->setText(QString());
        prevButton_2->setText(QCoreApplication::translate("MainWindow", "Prev", nullptr));
        nextButton_2->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        messageLabel_2->setText(QString());
        enterButton->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Communities", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "AddCommunity", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "DeleteCommunity", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CommunityList", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "FindCommunity", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Friends", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "FriendsList", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "FindFriend", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "AddFriend", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "DeleteFriend", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "ContactModerator", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        prevButton->setText(QCoreApplication::translate("MainWindow", "Prev", nullptr));
        messageLabel->setText(QString());
        SubCommunityLabel->setText(QString());
        PositionLabel->setText(QString());
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
