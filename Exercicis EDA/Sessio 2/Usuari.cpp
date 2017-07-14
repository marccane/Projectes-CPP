//Marc Cané Salamià
//u1939666
//Sessió 2
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

bool Usuari::TePokemonX(string pok){
    bool res=false;
    for (list<string>::iterator it = a_pokemons.begin(); it != a_pokemons.end(); it++){
        if(*it==pok)res=true;
    }
    return res;
}

ostream& operator<<(ostream &o, Usuari u){
    o<<u.a_alias<<" ["<<u.a_adreca<<"]"<<endl;
    for (list<string>::iterator it = u.a_pokemons.begin(); it != u.a_pokemons.end(); it++)
        o << "   " <<*it << endl;
    return o;
}

istream& operator>>(istream &o, Usuari &u){
    string temp;
    o>>u.a_alias;
    if(u.a_alias!="*"){
        o>>u.a_adreca;
        o.ignore();
        getline(o,temp);
        while(temp!="*"){
            u.a_pokemons.push_back(temp);
            o.ignore();
            getline(o,temp);
        }
    }
    return o;
}
