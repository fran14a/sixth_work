#include "showme.h"
#include "ui_showme.h"
#include "mainwindow.h"
#include "signup.h"
#include "vector.h"

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

showme::showme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showme)
{
    ui->setupUi(this);
}

showme::~showme()
{
    delete ui;
}

void showme::on_pushButton_2_clicked()//кнопка Back
{
    MainWindow *main_window = new MainWindow();
    main_window->show();
    close();
}

void showme::on_pushButton_3_clicked()//кнопка Save in file
{
    Vector *MyVector = new Vector(100);
    signUp sign_inShowme;

    MyVector = sign_inShowme.value();//чтобы получить вектор из другого класса "signUp"

    //сохранить данные в выбранном пользователем файле
    QString filter = "Text File (*.txt)";
    QString file_name = QFileDialog::getSaveFileName
            (this,"Save file","/Users/a1/labawork4/",filter);
    QFile file(file_name);

    if(!file.open(QIODevice::WriteOnly))
        QMessageBox::warning(this,"file1","Error: File not opened");//si el archivo no se abre, muestra un mensaje de error
    else
    {
        QTextStream out(&file);
        QString text_vector = QString::fromStdString(MyVector->tostringv());

        out << text_vector;

        file.flush();
        file.close();
    }
}

void showme::on_pushButton_clicked()//кнопка Open file
{
    QString filter = "Text File (*.txt)";//tambien se puede "All File (*.*);;Text File (*.txt)"
    QString file_name = QFileDialog::getOpenFileName
            (this,"Open file","/Users/a1/labawork4/",filter);
    QFile file(file_name);

    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::warning(this,"file1","File not opened");//si el archivo no se abre, muestra un mensaje de error
    else
    {
    //convetir un archivo a stream
    QTextStream in(&file);
    QString text = in.readAll();

    ui->textBrowser->setText(text);

    file.close();
    }
}

void showme::on_pushButton_4_clicked()//кнопка Show
{
    Vector *MyVector = new Vector(100);
    signUp sign_inShowme;

    MyVector = sign_inShowme.value();//чтобы получить вектор из другого класса "signUp"

    QString text_vector = QString::fromStdString(MyVector->tostringv());

    ui->textBrowser->setText(text_vector);
}
