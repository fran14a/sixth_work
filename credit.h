#ifndef CREDIT_H
#define CREDIT_H

#include "date.h"
#include "person.h"
#include <fstream>
#include <cassert>

class Credit:public Person{

    public:

        Credit();
        virtual ~Credit();
        Credit(const Credit &C);//конструктор копирования

        Credit(int, Person, double, Date, Date);

        //setters
        void setcredit(int,Person,double,Date);
        void setnumber(int);
        void setapplicant(Person);
        void setvalue(double);
        void setauthorizationdate(Date);
        void setdeliverydate(Date);
        void setpaymentdates();

        //getters
        Date getautorizationdate();
        Date getdeliverydate();
        int getnumber();
        double getvalue();

        //Functions to ask for information and show it to console
        void capture();
        void showinfo();//ПОЛИМОРФИЗМ

        void writeonfile();//метод чтения файла
        void readfromfile();//метод записи в файл

        //фунция чтобы преобразовать данные в тип string (тестирование)
        string tostringc();

    private:

        int number;//номер кредита
        Person applicant;//заявитель
        double value;//размер кредита (в долларах)
        Date autorizationdate;//дата разрешения кредита
        Date deliverydate;//дата вручения кредита
        Date paymentdates[6];//даты для оплаты крудита

    friend class Vector;
};

#endif // CREDIT_H
