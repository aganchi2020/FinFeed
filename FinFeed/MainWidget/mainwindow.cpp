#include <sstream>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Showcases = new Community("Showcases");
    Showcases->build_comm(50);
    Fish = new Community("Fish");
    Fish->build_comm(51);
    Equipment = new Community("Equipment");
    Equipment->build_comm(52);
    Peripherals = new Community("Peripherals");
    Peripherals->build_comm(53);
    ui->stackedWidget->setCurrentIndex(0);
    listIndex = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Showcases;
    delete Fish;
    delete Equipment;
    delete Peripherals;
}

void MainWindow::on_action_Exit_triggered()
{
    //  the window by calling close slot
    close();
}

void MainWindow::on_action_Fish_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label_8->setText("Fish");
    listComms = Fish->get_subs();
    QString listNames;
    for(SubCommunity* sc : listComms){
        std::string tempString = sc->get_name();

        for(char c : tempString){
            listNames += c;
        }

        listNames += "\n";
    }

    ui->messageLabel_2->setText(listNames);
    listIndex = 0;

    draw_communities();
}


void MainWindow::on_action_Equipment_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label_8->setText("Equipment");
    listComms = Equipment->get_subs();
    QString listNames;
    for(SubCommunity* sc : listComms){
        std::string tempString = sc->get_name();

        for(char c : tempString){
            listNames += c;
        }

        listNames += "\n";
    }

    ui->messageLabel_2->setText(listNames);
    listIndex = 0;

    draw_communities();
}


void MainWindow::on_action_Peripherals_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label_8->setText("Peripherals");
    listComms = Peripherals->get_subs();
    QString listNames;
    for(SubCommunity* sc : listComms){
        std::string tempString = sc->get_name();

        for(char c : tempString){
            listNames += c;
        }

        listNames += "\n";
    }

    ui->messageLabel_2->setText(listNames);
    listIndex = 0;

    draw_communities();
}


void MainWindow::on_showcases_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label_8->setText("Showcases");
    listComms = Fish->get_subs();
    QString listNames;
    for(SubCommunity* sc : listComms){
        std::string tempString = sc->get_name();

        for(char c : tempString){
            listNames += c;
        }

        listNames += "\n";
    }

    ui->messageLabel_2->setText(listNames);
    listIndex = 0;

    draw_communities();
}

void MainWindow::on_action_Help_triggered()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_actionCommunities_triggered()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_action_Friends_triggered()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_enterButton_clicked()
{
    currThread = listComms.at(listIndex)->get_posts();
    threadPos = 0;
    if (currThread->thread_size() <= 0) return;
    ui->stackedWidget->setCurrentIndex(8);
    draw_thread();
}

void MainWindow::draw_thread()
{
    Message* m = currThread->post_at( threadPos );
    stringstream ss;
    ss << "On: " << m->date << endl
       << "User: " << m->user_id << endl
       << "Posted: " << m->message << endl;
    ui->messageLabel->setText( ss.str().c_str() );
    // set the name of subcommunity/thread.
    ui->SubCommunityLabel->setText( currThread->threadName.c_str() );
    // set the name of the position.
    stringstream ss_2;
    ss_2 << "At message " << threadPos + 1
         << " of " << currThread->thread_size()
         << " Messages.";
    ui->PositionLabel->setText( ss_2.str().c_str() );
}

void MainWindow::draw_communities()
{
    QString temp;
    std::string tempString = listComms.at(listIndex)->get_name();

    for(char c : tempString){
        temp += c;
    }
    ui->PositionLabel_2->setText(temp);
}

void MainWindow::on_prevButton_clicked()
{
    size_t max = currThread->thread_size() - 1;
    if ( threadPos <= 0 ) threadPos = max;
    else threadPos--;
    draw_thread();
}

void MainWindow::on_nextButton_clicked()
{
    size_t max = currThread->thread_size() - 1;
    if ( threadPos >= max ) threadPos = 0;
    else threadPos++;
    draw_thread();
}


void MainWindow::on_prevButton_2_clicked()
{
    // to iterate to the prev subcommunity.
    if(listIndex <= 0) listIndex = listComms.size() - 1;
    else listIndex--;
    draw_communities();
}

void MainWindow::on_nextButton_2_clicked()
{
    // iterate to next subcommunity
    if(listIndex >= listComms.size() - 1) listIndex = 0;
    else listIndex++;
    draw_communities();
}

