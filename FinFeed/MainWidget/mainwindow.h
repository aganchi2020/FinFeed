
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sstream>
#include "../Communication_Toolset/thread.h"
#include "../Information_Channels/subcommunity.h"
#include "../Information_Channels/community.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void draw_thread();

    void draw_communities();

private slots:
    void on_action_Exit_triggered();

    void on_action_Fish_triggered();

    void on_action_Equipment_triggered();

    void on_action_Peripherals_triggered();

    void on_actionCommunities_triggered();

    void on_action_Friends_triggered();

    void on_showcases_triggered();

    void on_action_Help_triggered();

    void on_enterButton_clicked();

    void on_prevButton_clicked();

    void on_prevButton_2_clicked();

    void on_nextButton_clicked();

    void on_nextButton_2_clicked();

private:
    Ui::MainWindow *ui;

    Community* Showcases;
    Community* Fish;
    Community* Equipment;
    Community* Peripherals;

    vector<SubCommunity*> listComms;
    SubCommunity* currentComm;
    size_t listIndex;

    size_t threadPos;
    Thread* currThread;
};

#endif // MAINWINDOW_H
