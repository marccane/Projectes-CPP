#include <iostream>

using namespace std;

struct EmmagatzemarFraccio{
    int numerador, denominador;
    char signe;
}fraccio1, fraccio2, temporal;

bool esdivisible(int a, int b){
    return (a%b==0);
}

EmmagatzemarFraccio LlegirFraccio(int dameunum){
    EmmagatzemarFraccio fraccio;
    string a[]={"INTRODUEIX NUMERADOR (>0):",
    "INTRODUEIX DENOMINADOR (>0):"};
    cout<<"INTRODUEIX EL SIGNE DE LA FRACCIO "<<dameunum<<" [+-]:"<<endl;
    cin>>fraccio.signe;
    cout<<a[0]<<endl;
    cin>>fraccio.numerador;
    cout<<a[1]<<endl;
    cin>>fraccio.denominador;
    return fraccio;
}

EmmagatzemarFraccio SimplificarFraccio(EmmagatzemarFraccio fraccio){
    int divisible=2;
    if(temporal.numerador==0){
        temporal.denominador=1;
        return temporal;
    }
    while(fraccio.numerador>=divisible or fraccio.denominador>=divisible){
        if(esdivisible(fraccio.numerador,divisible) and esdivisible(fraccio.denominador,divisible)){
            fraccio.numerador/=divisible;
            fraccio.denominador/=divisible;
        }
        else{
            divisible++;
        }
    }
    return fraccio;
}

EmmagatzemarFraccio OperarFraccio(char operacio, EmmagatzemarFraccio f1, EmmagatzemarFraccio f2){
    EmmagatzemarFraccio temporal;
    switch(operacio){
        case '+':
            temporal.numerador=f1.numerador*f2.denominador+f2.numerador*f1.denominador;
            temporal.denominador=f1.denominador*f2.denominador;
            break;

        case '-':
            temporal.numerador=f1.numerador*f2.denominador-f2.numerador*f1.denominador;
            temporal.denominador=f1.denominador*f2.denominador;
            break;

        case '*':
            temporal.numerador=f1.numerador*f2.numerador;
            temporal.denominador=f1.denominador*f2.denominador;
            break;

        case '/':
            temporal.numerador=f1.numerador*f2.denominador;
            temporal.denominador=f1.denominador*f2.numerador;
            if(temporal.denominador<0){
                temporal.numerador=-temporal.numerador;
                temporal.denominador=-temporal.denominador;
            }
            break;
    }
    return temporal;
}

EmmagatzemarFraccio PosarSigne(EmmagatzemarFraccio temporal){
    if(temporal.signe=='-')temporal.numerador=-temporal.numerador;
    return temporal;
}

int main(){
    char operacio;
    fraccio1=LlegirFraccio(1);
    cout<<"INTRODUEIX OPERACIO [+-*/]:"<<endl;
    cin>>operacio;
    fraccio2=LlegirFraccio(2);
    fraccio1=PosarSigne(fraccio1);
    fraccio2=PosarSigne(fraccio2);
    temporal=OperarFraccio(operacio,fraccio1,fraccio2);
    temporal=SimplificarFraccio(temporal);
    cout<<"EL RESULTAT DE L'OPERACIO ES:"<<endl;
    cout<<temporal.numerador<<"/"<<temporal.denominador<<endl;
    return 0;
}
