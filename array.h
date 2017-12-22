#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//массив с шаблоном
template <class T>
class Array{

    public:

        Array(int);//Constructor
        ~Array();//Destructor
        Array(const Array &V);//конструктор копирования

        void addcredit(T *);
        string tostringv();//чтбы пробразовать вектор в тип string

    private:

        T **vec;
        int amount;//количество элементов
        int size;//размер

};

#endif // ARRAY_H
