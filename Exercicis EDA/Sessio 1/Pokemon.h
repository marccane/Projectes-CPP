//Marc Cané Salamià
//u1939666
//Pràctica 1
#ifndef POKEMON_H
#define POKEMON_H
#include <string>
using namespace std;

class Pokemon
{
    public:
        Pokemon();
        //Pre: --
        //Post: Retorna el codi del pokemon
        int Get_codi()const;
        //Pre: --
        //Post: Retorna el pes del pokemon
        float Get_Pes()const;
        //Pre: codi>0
        //Post: Els atributs del pokemon han sigut sobreescrits pels nous
        void Set_atributs(int codi,string nom, string tipus, float pes, float mida);
        //Pre: --
        //Post: Mostra tots els pokemons entrats i les seves dades, la mitjana de pes,
        //els pokemons que hi ha per sobre la mitjana de pes i a continuació els que estàn per sota
        void mostrar();
    private:
        int a_codi;
        string a_nom, a_tipus;
        float a_pes, a_mida;
};

#endif // POKEMON_H
