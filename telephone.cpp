#include "telephone.h"
#include <iomanip> // for setw(), watch line 169

Telephone::Telephone(){

    tnumber = "+7(888)234 567 890";
}

Telephone::Telephone(string A)
{
    tnumber = A;
}

Telephone::Telephone(const Telephone &T)//конструктор копирования
{
    tnumber = T.tnumber;
}

Telephone::~Telephone(){}

void Telephone::settnumber(string A)//проверка строки
{
    int s = A.size();
    int count1 = 0,count2 = 0;
    int count3 = 0,count4 = 0;

    if(s == 0 || s > 20)
        tnumber = "+7(888)234 567 890";
    else{
        for(int i=0; i<s ; i++){
            if((A[i] >= 'A' && A[i] <= 'Z')||
                    (A[i] >= 'a' && A[i] <= 'z')){
                tnumber = "+7(888)234 567 890";break;
            }
            else if(A[i+1] == '+' ) count3++;
            else if(A[i] == ' ') count1++;
            else if(A[i] == '-') count4++;
            else if(A[i] == '(' || A[i] == ')') count2++;
            else tnumber = A;
        }
        if(count3 != 0)
            tnumber = "+7(888)234 567 890";
        if(count1 > 2 || count4 > 2)
            tnumber = "+7(888)234 567 890";
        if(count2 == 1 || count2 == 3 || count2 > 4)
            tnumber = "+7(888)234 567 890";
        }
}

string Telephone::gettnumber()
{
    return tnumber;
}
