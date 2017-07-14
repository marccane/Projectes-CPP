//Marc Cané Salamià
//u1939666
//Sessió 3
#include "Usuari.h"
#include <iostream>
using namespace std;

Usuari::Usuari()
{
    //ctor
}

bool Usuari::EsFi()const{
    return a_alias=="*";
}

string Usuari::Get_Nom(){
    return a_alias;
}

void Usuari::Netejar_List(){
    a_pokemons.clear();
}

bool Usuari::TePokemonX(string pok){
   bool res=false;
    for (set<Exemplar>::iterator it = a_pokemons.begin(); it != a_pokemons.end() and !res; it++)
        if(it->Get_nom()==pok)res=true;
    return res;
}

ostream& operator<<(ostream &o, Usuari u){
    o<<u.a_alias<<" ["<<u.a_adreca<<"]"<<endl;
    for (set<Exemplar>::iterator it = u.a_pokemons.begin(); it != u.a_pokemons.end(); it++)
        it->mostrar();
    return o;
}

istream& operator>>(istream &o, Usuari &u){
    string temp, temp2;
    float temp3;
    Exemplar texem;
    o>>u.a_alias;
    if(u.a_alias!="*"){
        o>>u.a_adreca;
        o.ignore();
        getline(o,temp);
        while(temp!="*"){
            getline(o,temp2);
            o>>temp3;
            texem.Setter(temp,temp2,temp3);
            u.a_pokemons.insert(texem);
            o.ignore();
            getline(o,temp);
        }
    }
    return o;
}

Exemplar Usuari::Mostrar_PoderMaxim(float &maxim)const{
    set<Exemplar>::iterator emaxim;
    for (set<Exemplar>::iterator it = a_pokemons.begin(); it != a_pokemons.end(); it++)
        //maxim=it->Get_poder()>maxim?it->Get_poder():maxim;
        if(it->Get_poder()>=maxim){
            maxim=it->Get_poder();
            emaxim=it;
        }
    return *emaxim;
}
