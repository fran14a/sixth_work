#include "date.h"

#include <iostream>
#include <iomanip> // for setw(), see line 169

//inicializar el miembro estatico con alcance de archivo
//una copia de la propia clase
const int Date::days[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};//el primer elemento es 0 porque C++ incia el conteo desde 0, ver la estrellita (*) en la linea 27

//Constructor
Date::Date()
{
    month = 1;
    day = 1;
    year = 1900;
}

Date::~Date(){}

Date::Date(int mm, int dd, int yy)
{
    setdate(mm,dd,yy);
}

//конструктор копирования
Date::Date(const Date &D)
{
    month = D.month;
    day = D.day;
    year = D.year;
}

//set month,day and year
void Date::setdate(int mm, int dd, int yy)
{
    month = (mm >= 1 && mm <= 12) ? mm : 1;//условный (троичный) оператор
    year = (yy >= 1900 && yy <= 2100) ? yy : 1900;

    //check if it is a leap-year
    if (month == 2 && leapyear(year))
        day = (dd >= 1 && dd <= 29) ? dd : 1;
    else
        day = (dd >= 1 && dd <= days[month]) ? dd : 1; // aqui days[month] si el mes es igual a 2 (febrero) entonces se busca el elemento numero 2 en el array, que es 28
}

//FUNCIONES OBTENER - GETTERS
int Date::getday(){
    return day;
}

int Date::getmonth(){
    return month;
}

int Date::getyear(){
    return year;
}


//FUNCIONES DE INCREMENTO
//operador de preincremento sobrecargado
Date &Date::operator ++()
{
    helpincrement();
    return *this; //devuelve una referencia para crear un lvalue
}

//operadr de posincremento sobrecargado, el parametro entero falso aqui no lleva nombre, es usado solo para diferenciar
Date Date::operator ++(int){
    Date temp = *this;
    helpincrement(); //mantiene el estado actual del objeto

    return temp;
}

//funcion que suma el numero indicado de dias a una fecha
const Date &Date::operator +=(int AdditionalDays)
{
    for(int i = 0; i < AdditionalDays; i++)
        helpincrement();
    return *this; //para la cascada - https://www.youtube.com/watch?v=83mHoMS29G8
}

//FUNCIONES DE DECREMENTO
//operador de predecremento sobrecargado
Date &Date::operator --()
{
    helpdecrement();
    return *this; //devuelve la referencia para crear un lvalue
}

//operador de posincremento sobrecargado
Date Date::operator --(int)
{
    Date temp = *this;
    helpdecrement(); //mantiene el estado actual del objeto

    return temp;
}
//funcion que resta el numero indicado de dias a una fecha
const Date &Date::operator -=(int SubstractedDays)
{
    for(int i = 0; i < SubstractedDays; i++)
        helpdecrement();
    return *this; //para la cascada
}

//if it is a leap-year then:true, if not, then:false (everigua para qué se usa 'const' aqui)
bool Date::leapyear(int checkYear) const //https://es.wikibooks.org/wiki/Algoritmo_bisiesto#M.C3.A9todo_programando_en_C.2B.2B
{
    if(checkYear % 400 == 0 || (checkYear % 100 != 0 && checkYear % 4 == 0))
        return true; //it is a leap-year
    else
        return false; //it is not a leap year
}

//if the day is the last of the month
bool Date::endmonth(int checkDay) const
{
    if(month == 2 && leapyear(year)) // si es febrero y es un anio bisiesto
        return checkDay == 29; //ultimo dia de febrero en anio bisiesto
    else
        return checkDay == days[month];
}

//FUNCION DE INCREMENTO
//funcion de utilidad para ayudar a incrementar la fecha en un dia
void Date::helpincrement()
{
    //si el dia no es fin de mes
    if( !endmonth(day) )
        ++day;
    else
        //el dia es fin de mes y mes es menor que 12
        if(month < 12){
            ++month;
            day = 1;
        }
        //ultimo dia del mes
        else{
            ++year;
            month = 1;
            year = 1;
        }
}

//FUNCION DE DECREMENTO
//funcion de utilidad para ayudar a decrementar la fecha un un dia
void Date::helpdecrement()
{
    //se resta un dia, si el dia no es el primero del mes
    if (day > 1)
        --day;
    else
        //se resta un mes si el dia es inicio del mes y mes no es enero
        if(month > 1){
            --month;
            day = days[month];
        }
        //se resta un anio si es primero de enero
        else{
            --year;
            month = 12;
            day = 31;
        }
}

//OPERADOR DE SALIDA (insercion de flujo) sobrecargado
//Shows the date in letters
ostream &operator <<(ostream &output, const Date &a)
{
    const char *monthName[13] = {"","January","February","March","April",
                                 "May","June","July","August","September",
                                 "October","November","December"};

    output << monthName [a.month] << ' ' << a.day << ", " <<a.year;
    return output; //para la cascada
}

//OPERADOR DE ENTRADA (extraction de flujo) sobrecargado
istream &operator >>(istream &input, Date &a)
{
    input >> setw(2) >> a.day; //day input
    input.ignore(1); //ignores this symbol --> /
    input >> setw(2) >> a.month; //month input
    input.ignore(1); //ignores this symbol --> /
    input >> setw(2) >> a.year; //year input
    input.ignore(1); //ignores this symbol --> /
    return input; //this allows cin>>a>>b>>c;
}




