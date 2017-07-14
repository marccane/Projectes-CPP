//Marc Cané Salamià
//u1939666
//Sessió 2
#ifndef JOC_H
#define JOC_H
#include <iostream>
#include <list>
#include "Usuari.h"
#include "Pokedex.h"
using namespace std;

class Joc
{
    public:
        Joc();

    protected:

    private:
        string a_nom;
        Pokedex a_pokedex;
        list <Usuari> a_usuaris;

        friend ostream& operator<<(ostream &o, Joc j);
        friend istream& operator>>(istream &o, Joc &j);

};

#endif // JOC_H
