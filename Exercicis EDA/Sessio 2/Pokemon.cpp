//Marc Cané Salamià
//u1939666
//Sessió 2
#include "Pokemon.h"
#include <iostream>
using namespace std;

Pokemon::Pokemon()
{
    a_codi=a_pes=a_mida=0;
    a_nom=a_tipus="buit";
}

void Pokemon::Set_atributs(int codi,string nom, string tipus, float pes, float mida){
    a_codi=codi;
    a_nom=nom;
    a_tipus=tipus;
    a_pes=pes;
    a_mida=mida;
}

void Pokemon::mostrar(){
    static const string pad=", ";
    cout<<a_codi<<pad<<a_nom<<pad<<a_tipus<<pad<<a_pes<<pad<<a_mida<<endl;
}

int Pokemon::Get_codi()const{
    return a_codi;
}

float Pokemon::Get_Pes()const{
    return a_pes;
}
