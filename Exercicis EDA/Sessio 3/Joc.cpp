//Marc Cané Salamià
//u1939666
//Sessió 3
#include "Joc.h"
#include <iostream>
#include "Usuari.h"
using namespace std;

istream& operator>>(istream &i, Joc &j){//!CIN
    Usuari temp;
    string temp2;
    i>>j.a_nom;
    j.a_pokedex.Llegir_Pokemons();

    i>>temp;
    while(!temp.EsFi()){
        j.a_usuaris.push_back(temp);
        temp.Netejar_List();
        i>>temp;
    }
    j.a_usuaris.sort(Comparar);
    return i;
}

ostream& operator<<(ostream &o, Joc j){//!COUT
    o<<"----------------------------------------"<<endl;
    o<<j.a_nom<<endl<<"============"<<endl<<"Pokedex"<<endl;
    j.a_pokedex.Mostrar_Pokemons();
    o<<endl<<"Usuaris"<<endl<<"-------"<<endl;
    for (list<Usuari>::iterator it = j.a_usuaris.begin(); it != j.a_usuaris.end(); it++)
        o << *it << endl;

    float maxim=0, temp;
    Exemplar utemp, umaxim;
    string smax;
    for (list<Usuari>::iterator it = j.a_usuaris.begin(); it != j.a_usuaris.end(); it++){
        temp=0;
        utemp=it->Mostrar_PoderMaxim(temp);
        if(temp>maxim){
            maxim=temp;
            umaxim=utemp;
            smax=it->Get_Nom();
        }
    }
    cout<<"poder maxim el te:"<<endl;
    umaxim.mostrar();
    cout<<"que es propietat de "<<smax<<endl<<endl;
    j.Mostrar_Pok_Usuaris();
    return o;
}

void Joc::Mostrar_Pok_Usuaris(){
    string temp, users[100];
    int userseltenen;
    temp=LlegirString();
    while(temp!="*"){
        userseltenen=0;
        for (list<Usuari>::iterator it = a_usuaris.begin(); it != a_usuaris.end(); it++)
            if(it->TePokemonX(temp))
                users[userseltenen++]=it->Get_Nom();
        if(userseltenen==0)cout<<"Cap usuari te el pokemon "<<temp<<endl;
        else {
            cout<<"els usuaris ";
            for(int i=0;i<userseltenen;i++)
                cout<<"["<<users[i]<<"] ";
            cout<<"tenen el pokemon "<<temp<<endl;
        }
        temp=LlegirString();
    }
}

bool Comparar(Usuari a, Usuari b){
    return a.Get_Nom()<b.Get_Nom();
}

string LlegirString(){
    string s;
    cin>>s;
    return s;
}
