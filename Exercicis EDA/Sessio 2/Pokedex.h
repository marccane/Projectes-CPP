//Marc Cané Salamià
//u1939666
//Sessió 2
#ifndef POKEDEX_H
#define POKEDEX_H
#include <vector>
#include "Pokemon.h"

class Pokedex
{
    public:
        Pokedex();
        //Pre: --
        //Post: Les dades entrades dels pokemons s'han guardat
        void Llegir_Pokemons();
        //Pre: --
        //Post: Dona les dades dels pokemons entrats ordenats per codi
        void Mostrar_Pokemons();
    private:
        int npokemons;
        std::vector<Pokemon>a_pokemons;

        //funcions privades
        void afegirPokemon(Pokemon &p);
        void Mostrar_Filtre(float par, int filtre=0);
};

#endif // POKEDEX_H
