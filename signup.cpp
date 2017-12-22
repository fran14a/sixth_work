#include "signup.h"
#include "ui_signup.h"
#include "mainwindow.h"
#include "person.h"
#include "credit.h"

#include <QMessageBox>
#include <QString>
#include <QMessageBox>
#include <QRegExpValidator>

#define ONLYletters_RX "^[A-zйцукенгшщзхъфывапролджэёячсмитьбю]{15}$"
#define ONLYnumbers_RX "^[0-9-+)( ]{14}$"
#define ONLYnumbers_RX_2 "^[0-9]{2}$"
#define ONLYnumbers_RX_4 "^[0-9]{4}$"
#define ONLYnumbers_RX_6 "^[0-9]{6}$"
#define ONLYnumbers_RX_t "^[0-9-+)( ]{20}$"

Vector *MyVector = new Vector(100);//100 значение по умолчанию

signUp::signUp(QWidget *parent) ://constructor
    QDialog(parent),
    ui(new Ui::signUp)
{
    ui->setupUi(this);

    //image https://www.youtube.com/watch?v=SyzxerD2Yps&t=2s
    QPixmap img("/Users/a1/labawork4/icon.png");//for resource file https://www.youtube.com/watch?v=CTbpS0PN-JQ
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio));

    //validation for name,lasname,secondname
    QRegExp rxLetters(ONLYletters_RX);
    QRegExpValidator *Vletters = new QRegExpValidator(rxLetters,this);
    ui->lineEdit_FN->setValidator(Vletters);
    ui->lineEdit_SN->setValidator(Vletters);
    ui->lineEdit_LN->setValidator(Vletters);

    //validation for numbers
    QRegExp rxNumb(ONLYnumbers_RX);
    QRegExpValidator *Vnumb = new QRegExpValidator(rxNumb,this);
    ui->lineEdit_ID->setValidator(Vnumb);

    QRegExp rxNumb_2(ONLYnumbers_RX_2);
    QRegExpValidator *Vnumb_2 = new QRegExpValidator(rxNumb_2,this);
    ui->lineEdit_Da1->setValidator(Vnumb_2);
    ui->lineEdit_Da2->setValidator(Vnumb_2);

    QRegExp rxNumb_4(ONLYnumbers_RX_4);
    QRegExpValidator *Vnumb_4 = new QRegExpValidator(rxNumb_4,this);
    ui->lineEdit_Da3->setValidator(Vnumb_4);

    QRegExp rxNumb_6(ONLYnumbers_RX_6);
    QRegExpValidator *Vnumb_6 = new QRegExpValidator(rxNumb_6,this);
    ui->lineEdit_CrA->setValidator(Vnumb_6);

    QRegExp rxNumb_t(ONLYnumbers_RX_t);
    QRegExpValidator *Vnumb_t = new QRegExpValidator(rxNumb_t,this);
    ui->lineEdit_P->setValidator(Vnumb_t);
}

signUp::~signUp()
{
    delete ui;
}

void signUp::on_pushButton_Ex_clicked()//EXIT
{
    QMessageBox::StandardButton reply = QMessageBox::question(
                this,"EXIT","Are you sure?",QMessageBox::Yes |
                QMessageBox::No);
    if (reply == QMessageBox::Yes) QApplication::quit();
}

void signUp::on_pushButton_Ba_clicked()//BACK
{
    MainWindow *main_window = new MainWindow();
    main_window->show();
    close();
}

void signUp::on_pushButton_OK_clicked()//Check if info is correct and insert data in the array
{
    QString ID,FN,SN,LN,Ph,Da1,Da2,Da3,CrA;
    Credit *MyCredit = new Credit();

    ID = ui->lineEdit_ID->text();
    FN = ui->lineEdit_FN->text();
    SN = ui->lineEdit_SN->text();
    LN = ui->lineEdit_LN->text();
    Ph = ui->lineEdit_P->text();
    Da1 = ui->lineEdit_Da1->text();//month
    Da2 = ui->lineEdit_Da2->text();//day
    Da3 = ui->lineEdit_Da3->text();//year
    CrA = ui->lineEdit_CrA->text();

    if(ID.size()>0 && FN.size()>0 && SN.size()>0 &&
            LN.size()>0 && Ph.size()>0 && Da1.size()>0
            && Da2.size()>0 && Da3.size()>0 && CrA.size()>0)
    {
        MyCredit->setid(ID.toStdString());
        MyCredit->setfirstn(FN.toStdString());
        MyCredit->setsecondn(SN.toStdString());
        MyCredit->setlastn(LN.toStdString());
        MyCredit->settnumber(Ph.toStdString());
        MyCredit->setdate(Da1.toInt(),Da2.toInt(),Da3.toInt());
        MyCredit->setvalue(CrA.toLong());

        MyVector->addcredit(MyCredit);

        QMessageBox::information(this,"OK","Data saved!");

        MainWindow *mainWindow = new MainWindow;
        mainWindow->show();
        close();
    }
    else QMessageBox::warning(this,"Warning1","Invalid data entered!");
}

Vector *signUp::value()
{
    return MyVector;
}
