#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include "telephone.h"
#include <fstream>

class Person:public Telephone,public Date{

    public:

        Person();//Default Constructor
        Person(const Person &P);//Конструктор копирования
        ~Person();

        Person(string,string,string,string,Date,string);//constructor

        //Setters and Getters for each member
        void setperson(string, string, string, string, Date, string);
        void setid(string);
        void setfirstn(string);
        void setsecondn(string);
        void setlastn(string);
        void setbirthday(Date);

        string getid();
        string getfirstn();
        string getsecondn();
        string getlastn();
        Date getbirthday();

        //Functions for asking information and show it in the screen
        void capture();
        virtual void showinfo();//ПОЛИМОРФИЗМ

        void writeonfile();//метод чтения файла
        void readfromfile();//метод записи в файл

        int calculateage(Date);//для расчёта возраста

    private:

        string id,firstn,secondn,lastn;
        Date birthday;

        friend class Credit;
        friend class Vector;

};

#endif // PERSON_H
