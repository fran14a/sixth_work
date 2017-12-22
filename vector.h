#ifndef VECTOR_H
#define VECTOR_H

#include "credit.h"

//формирование массива
class Vector{

    public:

        Vector(int);//Constructor
        ~Vector();//Destructor
        Vector(const Vector &V);//конструктор копирования

        void addcredit(Credit *);
        string tostringv();//чтбы пробразовать вектор в тип string

        void printvector();//запись в файл
        void readvector();//чтение из файла

    private:

        Credit **vec;
        int amount;//количество элементов
        int size;//размер

};

#endif // VECTOR_H
