
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sstream>
#include "../Communication_Toolset/thread.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString message_text;
    QString position_text;
    Thread* thread;
    size_t position;

    bool set_curr_text( size_t position );

    void draw_thread();
private slots:
    void on_nextButton_clicked();

    void on_prevButton_clicked();

    void on_action_Exit_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
