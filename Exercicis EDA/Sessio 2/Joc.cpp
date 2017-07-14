//Marc Cané Salamià
//u1939666
//Sessió 2
#include "Joc.h"
#include <iostream>
#include "Usuari.h"
using namespace std;

Joc::Joc()
{

}

string LlegirString(){
    string s;
    cin>>s;
    return s;
}

ostream& operator<<(ostream &o, Joc j){//!COUT
    o<<"----------------------------------------"<<endl;
    o<<j.a_nom<<endl<<"============"<<endl<<"Pokedex"<<endl;
    j.a_pokedex.Mostrar_Pokemons();
    o<<endl<<"Usuaris"<<endl<<"-------"<<endl;
    for (list<Usuari>::iterator it = j.a_usuaris.begin(); it != j.a_usuaris.end(); it++)
        o << *it << endl;

    string temp, users[100];
    int userseltenen;
    temp=LlegirString();
    while(temp!="*"){
        userseltenen=0;
        for (list<Usuari>::iterator it = j.a_usuaris.begin(); it != j.a_usuaris.end(); it++)
            if(it->TePokemonX(temp))
                users[userseltenen++]=it->Get_Nom();

        if(userseltenen==0)o<<"Cap usuari te el pokemon "<<temp<<endl;
        else {
                o<<"els usuaris ";
                for(int i=0;i<userseltenen;i++)
                    o<<"["<<users[i]<<"] ";
                o<<"tenen el pokemon "<<temp<<endl;
        }
        temp=LlegirString();
    }
    return o;
}

bool Comparar(Usuari a, Usuari b){
    return a.Get_Nom()<b.Get_Nom();
}

istream& operator>>(istream &i, Joc &j){//!!CIN
    Usuari temp;
    string temp2;
    i>>j.a_nom;
    j.a_pokedex.Llegir_Pokemons();

    i>>temp;
    while(!temp.EsFi()){
        j.a_usuaris.push_back(temp);
        i>>temp;
    }
    j.a_usuaris.sort(Comparar);
    return i;
}
