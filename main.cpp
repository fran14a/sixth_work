#include "mainwindow.h"
#include "credit.h"
#include <QApplication>
#include <iostream>

using namespace std;

bool ValidDate(Date,Date);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

bool ValidDate(Date fa,Date LimitDate)
{
    bool result = true;
    if(fa.getyear() > LimitDate.getyear()){
        cout<<"Impossible date, out of rate"<<endl;
        result = false;
    }else{
        if(fa.getyear() == LimitDate.getyear()){
            if(fa.getmonth() > LimitDate.getmonth()){
                cout<<"Impossible date, out of rate"<<endl;
                result = false;
            }
            else
                if(fa.getmonth() == LimitDate.getmonth()){
                    if(fa.getday() > LimitDate.getday()){
                        cout<<"Impossible date, out of rate"<<endl;
                        result = false;
                    }
                }
        }
    }
    return result;
}
