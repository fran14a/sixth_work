#include "array.h"
#include <sstream>

template <class T>
Array<T>::Array(int n)//Constructor
{
    amount = 0;
    size = n;
    vec = new T*[size];
}

template <class T>
Array<T>::~Array()//Destructor
{
    for(int i=0 ; i < amount ; i++){
        delete vec[i];//delete elements of the vector one by one
    }
    delete []vec;//delete the whole vector
}

template <class T>
Array<T>::Array(const Array &V)//конструктор копирования
{
    amount = V.amount;
    size = V.amount;
    vec = V.vec;
}

template <class T>
void Array<T>::addcredit(T *cre)//Method to add a class Credit
{
    if(amount < size){
        vec[amount++] = cre;
    }else{
        cout<<"No field";
    }
}

template <class T>
string Array<T>::tostringv()//Method to create a string vector
{
    stringstream s;

    for(int i=0 ; i < amount ; i++){
        s << vec[i]->tostringc() << endl;
    }
    return s.str();
}
