#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox> //for asking: are you sure?
#include <QDateTime> //for time
#include <QTimer>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) ://this is the constructor of my project
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //showTime();//for showing time, but the time will not run
    QTimer *timer = new QTimer(this);//for running time
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime())); //signal and slot method
    timer->start();//https://www.youtube.com/watch?v=wmFX8FyCOP0

    //show Date
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTime_text = dateTime.toString("dddd, d MMMM yyyy");//http://doc.qt.io/qt-4.8/qdatetime.html#currentDateTime
    ui->date_time->setText(dateTime_text);

    //add text to the Status Bar
    ui->statusBar->addPermanentWidget(ui->digital_clock);
    ui->statusBar->addPermanentWidget(ui->date_time);

    //image https://www.youtube.com/watch?v=SyzxerD2Yps&t=2s
    QPixmap img("/Users/a1/labawork4/icon.png");//for resource file https://www.youtube.com/watch?v=CTbpS0PN-JQ
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked() //EXIT
{
    QMessageBox::StandardButton reply = QMessageBox::question(
                this,"EXIT","Are you sure?",QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) QApplication::quit();
    else ui->statusBar->showMessage("Please, choose and option.",5000);//Show a message in status bar for 5 seconds
}

void MainWindow::showTime()
{
    QTime time = QTime::currentTime();//current time or date
    QString time_text = time.toString("hh:mm:ss");//format for the time

    if ((time.second()%2)==0)
    {
        time_text[2] = ' ';
        time_text[5] = ' ';
    }

    ui->digital_clock->setText(time_text);
}

void MainWindow::on_pushButton_clicked()//to Application form
{
    hide();
    sign_up = new signUp(this);
    sign_up->show();

}

void MainWindow::on_pushButton_4_clicked()//to showme
{
    hide();
    show_me = new showme(this);
    show_me->show();
}
