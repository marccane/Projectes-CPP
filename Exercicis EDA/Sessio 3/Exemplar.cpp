//Marc Cané Salamià
//u1939666
//Sessió 3
#include "Exemplar.h"

Exemplar::Exemplar()
{
    //ctor
}

void Exemplar::mostrar()const{
    cout<<a_alias<<endl<<a_nomPokemon<<endl<<a_poder<<endl;
}

void Exemplar::Setter(string alias, string nompok, float poder){
    a_alias=alias;
    a_nomPokemon=nompok;
    a_poder=poder;
}

string Exemplar::Get_nom()const{
    return a_nomPokemon;
}

float Exemplar::Get_poder()const{
    return a_poder;
}

bool operator<(Exemplar e, Exemplar e1){
    return e.a_alias<e1.a_alias;
}
