#include <sstream>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    position = 0;
    message_text = "";
    position_text = "";
    draw_thread();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nextButton_clicked()
{
    position++;
    set_curr_text( position );
    draw_thread();
}

void MainWindow::on_prevButton_clicked()
{
    position--;
    set_curr_text( position );
    draw_thread();
}

bool MainWindow::set_curr_text( size_t position )
{
    Message* m = thread->post_at( position );
    if ( m == nullptr )
    {
        message_text = "";
        position_text = "You have reached an end of this community's thread.";
        return false;
    }
    else
    {
        stringstream ss;
        ss << endl
           << "User " << m->user_id << ": "
           << m->message << endl
           << "On " << m->date << endl
           << "At " << m->time << endl;

        message_text = ss.str().c_str();

        ss.clear();
        ss << "You are at message "
           << position + 1 <<  " of "
           << (*this).thread->thread_size() - 1
           << " total messages.";

        position_text = ss.str().c_str();
        return true;
    }
}

void MainWindow::draw_thread()
{
    // set the position text.
    ui->PositionLabel->clear();
    ui->PositionLabel->setText( position_text );

    // set the thread text.
    ui->mainthread->clear();
    ui->mainthread->setText( message_text );
}

void MainWindow::on_action_Exit_triggered()
{
    //  the window by calling close slot
    close();
}

