#include "vector.h"
#include <sstream>

Vector::Vector(int n)//Constructor
{
    amount = 0;
    size = n;
    vec = new Credit*[size];
}

Vector::~Vector()//Destructor
{
    for(int i=0 ; i < amount ; i++){
        delete vec[i];//delete elements of the vector one by one
    }
    delete []vec;//delete the whole vector
}

Vector::Vector(const Vector &V)//конструктор копирования
{
    amount = V.amount;
    size = V.amount;
    vec = V.vec;
}

void Vector::addcredit(Credit *cre)//Method to add a class Credit
{
    if(amount < size){
        vec[amount++] = cre;
    }else{
        cout<<"No field";
    }
}

string Vector::tostringv()//Method to create a string vector
{
    stringstream s;

    for(int i=0 ; i < amount ; i++){
        s << vec[i]->tostringc() << endl;
    }
    return s.str();
}

void Vector::printvector()
{
    string A = tostringv();

    ofstream fout;
    fout.open("/Users/a1/labawork4/out_vector.txt",ios::out);

    if(!fout.fail()){

        fout << A;

    }else{
        cout<<"Error opening file!"<<endl;
    }
    fout.close();
}

void Vector::readvector()
{
    Credit *A = new Credit();

    ifstream fin;
    fin.open("/Users/a1/labawork4/in_vector.txt",ios::in);//ios::in abrir el archivo en modo lectura

    if(!fin.fail()){
        while(fin >> A->id >> A->firstn >> A->secondn >> A->lastn >> A->tnumber
                >> A->month >> A->day >> A->year >> A->value)
        {
            addcredit(A);
        }

        int s = A->id.size();
        if(s == 0) cout <<"Empty file!"<< endl;
    }
    else{
        cout << "File could not be opened!" << endl;
    }

    fin.close();
}
