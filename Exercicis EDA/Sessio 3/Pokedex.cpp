//Marc Cané Salamià
//u1939666
//Sessió 3
#include "Pokedex.h"
#include <iostream>
using namespace std;

const string separador="----------------------------------------";

Pokedex::Pokedex()
{
    npokemons=0;
}

void Pokedex::afegirPokemon(Pokemon &p){
    a_pokemons.insert(pair<string,Pokemon>(p.Get_Nom(),p));
}

void Pokedex::Llegir_Pokemons(){
    Pokemon t;
    int codi;
    float pes, mida;
    string nom, tipus;
    cin>>codi;
    while(codi!=0){
        cin.ignore(20,'\n');
        getline(cin,nom);
        getline(cin,tipus);
        cin>>pes>>mida;
        t.Set_atributs(codi,nom,tipus,pes,mida);
        afegirPokemon(t);
        cin>>codi;
    }
}

void Pokedex::Mostrar_Pokemons(){
    int comptador=0;
    float mitjana=0;
    cout<<separador<<endl<<endl;
    for(map<string,Pokemon>::iterator it=a_pokemons.begin();it!=a_pokemons.end();it++){
            it->second.mostrar();
            comptador++;
            mitjana+=it->second.Get_Pes();
    }
    cout<<separador<<endl;
    mitjana/=comptador;
    cout<<"mitjana pes: "<<mitjana<<endl<<separador<<endl;
    Mostrar_Filtre(mitjana);
    cout<<separador<<endl;
    Mostrar_Filtre(mitjana,1);
}

void Pokedex::Mostrar_Filtre(float par, int filtre){ //par=mitjana pes
    for(map<string,Pokemon>::iterator it=a_pokemons.begin();it!=a_pokemons.end();it++)
        switch(filtre){
        case 0:
            if(it->second.Get_Pes()<=par)it->second.mostrar();
            break;
        case 1:
            if(it->second.Get_Pes()>par)it->second.mostrar();
            break;
        }
}
