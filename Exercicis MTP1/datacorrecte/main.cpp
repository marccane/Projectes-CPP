#include <iostream>
#define escriu cout<<
#define filinea <<endl
using namespace std;

bool esanydetraspas(int any)
{
    if (any%4 == 0)
    {
        if(any%100==0 and any%400!=0)return false;
        else return true;
    }
    else return false;
}

int main()
{
    escriu "INTRODUEIX LA DATA:" filinea;
    string entrada;
    bool escorrecte=true;
    cin>>entrada;
    int contador=0, dia, mes, any, temp[10];
    if (entrada.length()!=8)escorrecte=false;
    while(contador<entrada.length()){
        temp[contador]=entrada[contador]-'0';
        contador++;
        }
    dia=temp[1]+temp[0]*10;
    mes=temp[2]*10+temp[3];
    any=temp[4]*1000+temp[5]*100+temp[6]*10+temp[7];
    if(any<1600 or any>3399 or mes>12 or dia>31 or dia<1 or mes<1)escorrecte=false;
    else if(!esanydetraspas(any) and mes==2 and dia>28)
        escorrecte=false;

    switch(mes){
    case 1:
        if(dia > 31)escorrecte=false;
        break;
    case 2:
        if(dia > 29)escorrecte=false;
        break;
    case 3:
        if(dia > 31)escorrecte=false;
        break;
    case 4:
        if(dia > 30)escorrecte=false;
        break;
    case 5:
        if(dia > 31)escorrecte=false;
        break;
    case 6:
        if(dia > 30)escorrecte=false;
        break;
    case 7:
        if(dia > 31)escorrecte=false;
        break;
    case 8:
        if(dia > 31)escorrecte=false;
        break;
    case 9:
        if(dia > 30)escorrecte=false;
        break;
    case 10:
        if(dia > 31)escorrecte=false;
        break;
    case 11:
        if(dia > 30)escorrecte=false;
        break;
    case 12:
        if(dia > 31)escorrecte=false;
        break;
    }

    if(escorrecte)escriu "LA DATA ES CORRECTA" filinea;
    else escriu "LA DATA ES INCORRECTA" filinea;

    return 0;
}
