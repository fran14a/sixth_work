#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "vector.h"

namespace Ui {
class signUp;
}

class signUp : public QDialog
{
    Q_OBJECT

public:
    explicit signUp(QWidget *parent = 0);
    ~signUp();

    //фунция чтобы передать вектор в другой класс
    Vector *value();

private slots:
    void on_pushButton_Ex_clicked();

    void on_pushButton_Ba_clicked();

    void on_pushButton_OK_clicked();

private:
    Ui::signUp *ui;

};

#endif // SIGNUP_H
