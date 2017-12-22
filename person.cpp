#include "person.h"

//default Constructor
Person::Person(){
    Date();
    Telephone();
    id = "09876543210987";
    firstn = "Artyom";
    secondn = "Andreevich";
    lastn = "Solomatin";
}

//Constructor for Person
Person::Person(string A, string B, string C, string D,
               Date E, string F):
    Telephone(F)
{
    setid(A);
    setfirstn(B);
    setsecondn(C);
    setlastn(D);
    setbirthday(E);

}
//контруктор копирования
Person::Person(const Person &P)
{
    id = P.id;
    firstn = P.firstn;
    secondn = P.secondn;
    lastn = P.lastn;
    birthday = P.birthday;
}

Person::~Person(){}

//SETTERS
//En esta funcion se establecen valores para TODOS los miembros de la clase
void Person::setperson(string A, string B, string C,
                        string D, Date E,string F)
{
    setid(A);
    setfirstn(B);
    setsecondn(C);
    setlastn(D);
    setbirthday(E);
    settnumber(F);
}

//Establecemos los valores para cada miembro de la clase
void Person::setid(string _ID)
{
    id = _ID;
    int s = _ID.size();

    if(s == 0 || s > 20)
        id = "17000000000000";
    else{
        for(int i=0; i<s ; i++){
            if((_ID[i] >= 'A' && _ID[i] <= 'Z')||
                    (_ID[i] >= 'a' && _ID[i] <= 'z')){
                id = "17000000000000";break;
            }
        }
    }
}

void Person::setfirstn(string _FirstN)
{
    int s = _FirstN.size();
    if(s == 0)
        firstn = "AnonymousN";
    else{
        for(int i=0 ; i<s ; i++){
            if(isalpha(_FirstN[i]) == 0){
                firstn = "AnonymousN";break;
            }
            else firstn = _FirstN;
        }
    }
}

void Person::setsecondn(string _SecondN)
{
    int s = _SecondN.size();
    if(s == 0)
        secondn = "AnonymousN";
    else{
        for(int i=0 ; i<s ; i++){
            if(isalpha(_SecondN[i]) == 0){
                secondn = "AnonymousN";break;
            }
            else secondn = _SecondN;
        }
    }
}

void Person::setlastn(string _LastN)
{
    int s = _LastN.size();
    if(s == 0)
        lastn = "AnonymousN";
    else{
        for(int i=0 ; i<s ; i++){
            if(isalpha(_LastN[i]) == 0){
                lastn = "AnonymousN";break;
            }
            else lastn = _LastN;
        }
    }
}

void Person::setbirthday(Date _Birthday)
{
    birthday = _Birthday;
}

//GETTERS
string Person::getid()
{
    return id;
}

string Person::getfirstn()
{
    return firstn;
}

string Person::getsecondn()
{
    return secondn;
}

string Person::getlastn()
{
    return lastn;
}

Date Person::getbirthday()
{
    return birthday;
}

//Functions to ask for the information
void Person::capture()
{
    string id,pn,sn,pa,hom;
    Date D;

    cout << "Getting data for a person" << endl;
    cout <<"ID: ";
    cin.ignore();
    cin >> id;
    cout <<"First Name: ";
    cin >> pn;
    cout << "Second Name: ";
    cin >> sn;
    cout << "Last Name: ";
    cin >> pa;
    cout << "Date of birth: ";
    cin >> D;
    cout << "For telephone numbers use the format: (xxx) xxx-xxxx ext.xxx --\n";
    cout << "Home telephone number: \n";
    cin >> hom;
    setperson(id,pn,sn,pa,D,hom);

}

//Function to show data in the console
void Person::showinfo()
{
    cout << "\nA)Personal Information:" << endl;
    cout << "ID: "<< id << endl;
    cout << "First name: "<< firstn << endl;
    cout << "Second name: "<< secondn << endl;
    cout << "Last name: " << lastn << endl;
    cout << "First name: " << firstn << endl;
    cout << "Date of birth: " << birthday << endl;
    cout << "B) Credit Information:" << endl;
    cout << "Date: " << month << "/" << day
        << "/" << year << endl;
}

int Person::calculateage(Date Actual)//функция для расчета возраста
{
    int age;
    if(Actual.getmonth() > birthday.getmonth()){
        age = Actual.getyear() - birthday.getyear();
    }
    else
        if(Actual.getmonth() < birthday.getmonth()){
            age = Actual.getyear() - birthday.getyear() - 1;
        }
        else
            if(Actual.getday() < birthday.getday()){
                age = Actual.getyear() - birthday.getyear() - 1;
            }
            else{
                age = Actual.getyear() - birthday.getyear();
            }

    return age;
}

void Person::writeonfile()
{
    Person A;

    ofstream fout;
    fout.open("/Users/a1/labawork4/out_person.txt",ios::out);

    if(!fout.fail()){

        fout << "A) Personal Information:" << endl;
        fout << "ID: " << A.id << endl;
        fout << "First Name: " << A.firstn << endl;
        fout << "Second name: " << A.secondn << endl;
        fout << "Last name: " << A.lastn << endl;
        fout << "Phone: " << A.tnumber << endl;
        fout << "B) Credit Information:" << endl;
        fout << "Date: "<< A.month <<"/"<< A.day <<"/"<< A.year <<endl;

    }else{
        cout<<"Error opening file!"<<endl;
    }
    fout.close();
}

void Person::readfromfile()
{
    Person A;

    ifstream fin;
    fin.open("/Users/a1/labawork4/in_person.txt",ios::in);//ios::in abrir el archivo en modo lectura

    if(!fin.fail()){
        fin >> A.id >> A.firstn >> A.secondn >> A.lastn >> A.tnumber
                >> A.month >> A.day >> A.year;

        int s = A.id.size();
        if(s == 0) cout <<"Empty file!"<< endl;
    }
    else{
        cout << "File could not be opened!" << endl;
    }

    fin.close();
}
