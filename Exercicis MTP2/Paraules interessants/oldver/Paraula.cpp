#include <iostream>
#include "Paraula.h"

Paraula::Paraula()
{
    vegades=1;
}

string Paraula::GetParaula() const{
    return par;
}

void Paraula::Mostrar() const{
    std::cout<<par<<" "<<vegades<<std::endl;
}

void Paraula::Modificar(string a){
    par=a;
    Arreglar();//No cal el this?
}

void Paraula::incrementar_comptador(){
    vegades++;
}

bool Paraula::esdinteres(string mots_interes_entrada[], int num_mots_interes_entrada){
    for(int i=0;i<num_mots_interes_entrada;i++){
        std::cout<<i<<" "<<mots_interes_entrada[i]<<std::endl;
        if(par.find(mots_interes_entrada[i],0)!=-1)
            return true;
    }
    return false;
}

void Paraula::Arreglar(){ //passar a minuscules
    for(int i=0;i<par.length();i++){
        if(par[i]<='Z' and par[i]>='A')
            par[i]-='A'-'a'; //aqui m'he flipat un pel
    }
}
