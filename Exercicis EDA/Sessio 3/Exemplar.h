//Marc Cané Salamià
//u1939666
//Sessió 3
#ifndef EXEMPLAR_H
#define EXEMPLAR_H
#include <iostream>
using namespace std;

class Exemplar
{
    public:
        Exemplar();
        //Pre - Post: L'exemplar ha sigut modificat amb les dades donades
        void Setter(string alias, string nompok, float poder);
        //Pre - Post: Es mostra l'exemplar
        void mostrar()const;
        //Pre - Post: cert quan l'alias del primer és més petit que el del segon
        friend bool operator<(Exemplar,Exemplar);
        //Pre - Post: El nom de lexemplar
        string Get_nom()const;
        //Pre - Post: El poder de l'exemplar
        float Get_poder()const;

    private:
        string a_alias, a_nomPokemon;
        float a_poder;
};

#endif // EXEMPLAR_H
