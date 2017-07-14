//Marc Cané Salamià
//u1939666
//Pràctica 1
#include "Pokedex.h"
#include <iostream>
using namespace std;

const string separador="----------------------------------------";

Pokedex::Pokedex()
{
    npokemons=0;
}

void Pokedex::afegirPokemon(Pokemon &p){
    if(a_pokemons.size()<=(unsigned)p.Get_codi())
        a_pokemons.resize(p.Get_codi()+1);
    if(a_pokemons[p.Get_codi()].Get_codi()!=0)
        npokemons++;
    a_pokemons[p.Get_codi()]=p;
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
    for(int i=0;i<(signed)a_pokemons.size();i++){
        if(a_pokemons[i].Get_codi()!=0){
            a_pokemons[i].mostrar();
            comptador++;
            mitjana+=a_pokemons[i].Get_Pes();
        }
    }
    cout<<separador<<endl;
    mitjana/=comptador;
    cout<<"mitjana pes: "<<mitjana<<endl<<separador<<endl;
    Mostrar_Filtre(mitjana);
    cout<<separador<<endl;
    Mostrar_Filtre(mitjana,1);
}

void Pokedex::Mostrar_Filtre(float par, int filtre){ //par=mitjana pes
    for(int i=0;i<(signed)a_pokemons.size();i++)
        if(a_pokemons[i].Get_codi()!=0)
            switch(filtre){
            case 0:
                if(a_pokemons[i].Get_Pes()<=par)a_pokemons[i].mostrar();
                break;
            case 1:
                if(a_pokemons[i].Get_Pes()>par)a_pokemons[i].mostrar();
                break;
            }
}
