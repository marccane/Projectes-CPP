//Marc Cané Salamià
//u1939666
//Sessió 3
#ifndef USUARI_H
#define USUARI_H
#include <iostream>
#include <set>
#include "Exemplar.h"
using namespace std;
class Usuari
{
    public:
        Usuari();
        //Pre - Post: cert si el nom d'usuari és la marca de fi
        bool EsFi()const;
        //Pre - Post: El nom de l'usuari
        string Get_Nom();
        //Pre - Post: Cert si lusuari té el pokemon passat
        bool TePokemonX(string pok);
        //Pre - Post: Llista de lusuari neta
        void Netejar_List();
        //Pre - Post: Exemplar amb maxim de poder de lusuari
        Exemplar Mostrar_PoderMaxim(float &maxim)const;

    private:
        string a_alias, a_adreca;
        set<Exemplar> a_pokemons;

        friend ostream& operator<<(ostream &o, Usuari u);
        friend istream& operator>>(istream &o, Usuari &u);
};

#endif // USUARI_H
