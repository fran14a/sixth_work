#include "credit.h"

#include <sstream>

//Constructor
Credit::Credit()
{
    int n = 0;
    Person Appl;
    double Val = 0;
    Date da;
    setcredit(n,Appl,Val,da);
}

Credit::~Credit(){}

Credit::Credit(int A, Person B, double C, Date D, Date E)
{
    setnumber(A);
    setapplicant(B);
    setvalue(C);
    setauthorizationdate(D);
    setdeliverydate(E);
    setpaymentdates();
}

Credit::Credit(const Credit &C)//конструктор копирования
{
    id = C.id;
    firstn = C.firstn;
    secondn = C.secondn;
    lastn = C.lastn;
    tnumber = C.tnumber;
    day = C.day;
    month = C.month;
    year = C.year;
    value = C.value;
    number = C.number;
    autorizationdate = C.autorizationdate;
    deliverydate = C.deliverydate;
    for(int i=0;i<6;i++)
        paymentdates[i] = C.paymentdates[i];
}

//SETTERS
void Credit::setcredit(int n, Person Appl, double Val, Date da)
{
    setnumber(n);
    setapplicant(Appl);
    setvalue(Val);
    setauthorizationdate(da);
    setdeliverydate(da);
    setpaymentdates();
}

void Credit::setnumber(int n)
{
    if(n>0)
        number = n;
    else {
        number = 1;
    }
}

void Credit::setapplicant(Person Appl)
{
    applicant = Appl;
}

void Credit::setvalue(double V)
{
    if(V > 0)
        value = V;
    else{
        value = 0;
    }
}

void Credit::setauthorizationdate(Date D)
{
    autorizationdate = D;
}

void Credit::setdeliverydate(Date D)
{
    deliverydate = (D += 7);
}

void Credit::setpaymentdates()
{
    Date WorkingDate = deliverydate;
    for (int i = 0; i < 6; i++)
    {
        WorkingDate += 30;
        paymentdates[i] = WorkingDate;
    }
}

//GETTERS
Date Credit::getautorizationdate()
{
    return autorizationdate;
}

Date Credit::getdeliverydate()
{
    return deliverydate;
}

double Credit::getvalue()
{
    return value;
}

int Credit::getnumber()
{
    return number;
}

//Capture information
void Credit::capture()
{
    int nro = 0;
    Person appl;
    double vlr = 0;
    Date D;

    cout<<"\nInformation for credit\n";
    cout<<"Number: ";
    cin >> nro;
    cout <<"Applicant: ";
        appl.capture();
    while(vlr < 0){
        cout<<"Value: ";
        cin >> vlr;
        if(vlr < 0){
            cout<<"Invalid value"<<endl;
        }
    }
    cout<<"Authorization date (dd/mm/aaaa)";
    cin >> D;
    while(D.getday() > 20){
        cout<<"Date of authorization must be at the first 20 days of the month"<<endl;
        cout<<"Try again: ";
        cin >> D;
    }
    setcredit(nro,appl,vlr,D);
}

void Credit::showinfo()//ПОЛИМОРФИЗМ
{
    Person::showinfo();
    cout << "Credit Amount: " << value << endl;
    cout << "Credit number: " << number << endl;
    cout << "Authorization date: " << autorizationdate << endl;
    cout << "Delivery date: " << deliverydate << endl;
    cout << "Payment Dates:\n";
    for (int i=0 ; i<6 ; i++)
        cout << "\tDebt " << i+1 << ": " << paymentdates[i] << endl;
    cout << "   - END -" << endl;
}

void Credit::writeonfile()
{
    Credit A;

    ofstream fout;
    fout.open("/Users/a1/labawork4/out_credit.txt",ios::out);

    if(!fout.fail()){

        fout << "A) Personal Information:" << endl;
        fout << "ID: " << A.id << endl;
        fout << "First Name: " << A.firstn << endl;
        fout << "Second name: " << A.secondn << endl;
        fout << "Last name: " << A.lastn << endl;
        fout << "Phone: " << A.tnumber << endl;
        fout << "B) Credit Information:" << endl;
        fout << "Date: " << A.month << "/" << A.day
             << "/" << A.year << endl;
        fout << "Credit Amount: " << A.value << endl;
        fout << "Credit number: " << A.number << endl;
        fout << "Authorization date: " << A.autorizationdate << endl;
        fout << "Delivery date: " << A.deliverydate << endl;
        fout << "Payment Dates:\n";
        for (int i=0 ; i<6 ; i++)
            fout << "\tDebt " << i+1 << ": " << A.paymentdates[i] << endl;
        fout << "   - END -" << endl;

    }else{
        cout<<"Error opening file!"<<endl;
    }
    fout.close();
}

void Credit::readfromfile()
{
    Credit A;

    ifstream fin;
    fin.open("/Users/a1/labawork4/in_credit.txt",ios::in);//ios::in abrir el archivo en modo lectura

    if(!fin.fail()){
        fin >> A.id >> A.firstn >> A.secondn >> A.lastn >> A.tnumber
                >> A.month >> A.day >> A.year >> A.value;

        int s = A.id.size();
        if(s == 0) cout <<"Empty file!"<< endl;
    }
    else{
        cout << "File could not be opened!" << endl;
    }

    fin.close();
}

string Credit::tostringc()
{
    stringstream s;

    s << "A) Personal Information:" << endl;
    s << "ID: " << id << endl;
    s << "First Name: " << firstn << endl;
    s << "Second name: " << secondn << endl;
    s << "Last name: " << lastn << endl;
    s << "Phone: " << tnumber << endl;
    s << "B) Credit Information:" << endl;
    s << "Date: " << month << "/" << day << "/" << year << endl;
    s << "Credit Amount: " << value << endl;
    s << "Credit number: " << number << endl;
    s << "Authorization date: " << autorizationdate << endl;
    s << "Delivery date: " << deliverydate << endl;
    s << "Payment Dates:\n";
    for (int i=0 ; i<6 ; i++)
        s << "\tDebt " << i+1 << ": " << paymentdates[i] << endl;
    s << "   - END -" << endl;

    return s.str();
}
