//Marc Cané Salamià
//u1939666
//Practica Algoritmica
#include "Candidat.h"
#include <iostream>
using namespace std;

const int mida=4;

Candidat::Candidat(int vert, int i)
{
    iCan = i;
    numvertex=vert;
}

int Candidat::actual() const
{
    if (esFi())
        cout<<("No hi ha més candidats");
    return iCan;
}
bool Candidat::esFi() const
{
    return iCan>numvertex;
}

void Candidat::seguent()
{
    if (esFi())
        cout<<("No hi ha més candidats");
    iCan++;
}

bool Candidat::esValid()const{
    return iCan!=invalid;
}
