#ifndef SHOWME_H
#define SHOWME_H

#include <QDialog>

namespace Ui {
class showme;
}

class showme : public QDialog
{
    Q_OBJECT

public:
    explicit showme(QWidget *parent = 0);
    ~showme();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::showme *ui;
};

#endif // SHOWME_H
