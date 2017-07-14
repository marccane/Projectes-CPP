#include <iostream>
#include "Hora.h"
using namespace std;

Hora::Hora()
{
    hores=61;
    minuts=61;
    //ctor
}

bool Hora::Esvalida(){
    bool valida=true;
    if(hores>23 or hores<0 or minuts>59 or minuts<0)
        valida=false;
    return valida;
}

void Hora::Llegir(){
    int temp;
    cin>>temp;
    hores=temp/100;
    minuts=temp-hores*100;
   /* hores=70;
    while(!Esvalida()){
        cin>>hores>>minuts;
    }*/
}

void Hora::Reiniciar_hora(){
    hores=0;
    minuts=0;
}

bool Hora::Esmesantiga(Hora q){
    bool mesantiga=false;
    if(hores<q.hores)
        mesantiga=true;
    else if(hores==q.hores){
        if(minuts<q.minuts)
            mesantiga=true;
    }
    return mesantiga;
}

void Hora::Mostrar() const{
    if(hores<10)cout<<"0"<<hores<<":";
    else cout<<hores<<":";
    if(minuts<10)cout<<"0"<<minuts;
    else cout<<minuts;
    cout<<endl;
}

int Hora::MinutsDiferencia(Hora b) const{
    int dif, htemp=b.hores, mtemp=b.minuts;
    if(hores>b.hores)htemp=htemp+24;
    if(minuts>b.minuts){
        mtemp+=60;
        htemp=htemp-1;
    }
    dif=(mtemp-minuts)+(htemp-hores)*60;
    return dif;
}
