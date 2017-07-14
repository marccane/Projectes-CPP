//Marc Cané Salamià
//u1939666
//Sessió 2
#ifndef USUARI_H
#define USUARI_H
#include <iostream>
#include <list>
using namespace std;
class Usuari
{
    public:
        Usuari();
        bool EsFi()const;
        string Get_Nom();
        bool TePokemonX(string pok);

    private:
        string a_alias, a_adreca;
        list <string> a_pokemons;

        friend ostream& operator<<(ostream &o, Usuari u);
        friend istream& operator>>(istream &o, Usuari &u);
};

#endif // USUARI_H
