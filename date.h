#ifndef DATE_H
#define DATE_H

#include <iostream>

//using std::ostream;
//using std::istream;

using namespace std;

class Date{

        //перегрузка операторов
        friend ostream &operator <<(ostream &, const Date &);
        friend istream &operator >>(istream &, Date &);

    public:

        Date();//default
        ~Date();

        //контруктор. Определяем начальные данные для даты
        Date(int,int,int);

        Date(const Date &D);//конструктор копирования

        void setdate(int,int,int);//sets a date

        //Getters functions to get a date
        int getmonth();
        int getday();
        int getyear();

        //Operators overloading (increment and decrease)
        Date &operator ++(); //operador de preincremento
        Date operator ++(int); //operador de postincremento
        Date &operator --(); //operador de predecremento
        Date operator --(int); //operador de postdecremento

        const Date &operator +=(int); //adding days, modifies the objet
        const Date &operator -=(int); //substracting days, modifies the objet

        //Funciones de utilidad que actuan sobre objetos de tipo date - funcion de utilidad La función de utilidad es una función en la que se mide la "satisfacción" o "utilidad" que obtiene un consumidor
        bool leapyear(int) const;//високосный год?
        bool endmonth(int) const;//конец месяца?

    private:

        int month,day,year;

        //array de valores constantes para saber cuantos dias tiene el mes de la fecha
        static const int days[]; //arreglo de dias por mes

        //Funciones que suman o restan un dia a objetos de tipo fecha
        void helpincrement(); //funcion de utilidad
        void helpdecrement();

    friend class Credit;
    friend class Person;
    friend class Vector;
};

#endif // DATE_H
