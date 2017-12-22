#ifndef TELEPHONE_H
#define TELEPHONE_H

#include <iostream>
using namespace std;

class Telephone{

    public:

        Telephone();//Constructor
        Telephone(string);
        Telephone(const Telephone &T);
        ~Telephone();

        void settnumber(string);//setter
        string gettnumber();//getter

    private:

        string tnumber;

    friend class Credit;
    friend class Person;
    friend class Vector;
};

#endif // TELEPHONE_H
