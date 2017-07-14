#include "Fraccio.h"
#include <iostream>

using namespace std;

Fraccio::Fraccio(){
    //ctor
}

void Fraccio::LlegirFraccio(int dameunum){
    string a[]={"INTRODUEIX NUMERADOR (>0):",
    "INTRODUEIX DENOMINADOR (>0):"};
    cout<<"INTRODUEIX EL SIGNE DE LA FRACCIO "<<dameunum<<" [+-]:"<<endl;
    cin>>signe;
    cout<<a[0]<<endl;
    cin>>numerador;
    cout<<a[1]<<endl;
    cin>>denominador;
}

void Fraccio::SimplificarFraccio(){
    int divisible=2;
    if(numerador==0){
        denominador=1;
    }
    else{
        while(numerador>=divisible or denominador>=divisible){
            if(esdivisible(numerador,divisible) and esdivisible(denominador,divisible)){
                numerador/=divisible;
                denominador/=divisible;
            }
            else{
                divisible++;
            }
        }
    }
}

void Fraccio::OperarFraccio(char operacio, Fraccio f1, Fraccio f2){
    switch(operacio){
        case '+':
            numerador=f1.numerador*f2.denominador+f2.numerador*f1.denominador;
            denominador=f1.denominador*f2.denominador;
            break;

        case '-':
            numerador=f1.numerador*f2.denominador-f2.numerador*f1.denominador;
            denominador=f1.denominador*f2.denominador;
            break;

        case '*':
            numerador=f1.numerador*f2.numerador;
            denominador=f1.denominador*f2.denominador;
            break;

        case '/':
            numerador=f1.numerador*f2.denominador;
            denominador=f1.denominador*f2.numerador;
            if(denominador<0){
                numerador=-numerador;
                denominador=-denominador;
            }
            break;
    }
}

void Fraccio::PosarSigne(){
    if(signe=='-')numerador=-numerador;
}

void Fraccio::Mostrar() const{
    cout<<"EL RESULTAT DE L'OPERACIO ES:"<<endl;
    cout<<numerador<<"/"<<denominador<<endl;
}

bool Fraccio::esdivisible(int a, int b){
    return (a%b==0);
}
