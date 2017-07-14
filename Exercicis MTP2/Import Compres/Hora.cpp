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
    hores=70;
    while(!this->Esvalida()){
        cout<<"HORA:"<<endl;
        cin>>hores>>minuts;
    }
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

void Hora::Mostrar(){
    if(hores<10)cout<<"0"<<hores<<":";
    else cout<<hores<<":";
    if(minuts<10)cout<<"0"<<minuts;
    else cout<<minuts;
}


