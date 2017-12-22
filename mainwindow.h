#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "signup.h"
#include "showme.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void showTime();//show time

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    signUp *sign_up;
    showme *show_me;
};

#endif // MAINWINDOW_H
