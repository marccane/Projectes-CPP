//Marc Can� Salami�
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
        cout<<("No hi ha m�s candidats");
    return iCan;
}
bool Candidat::esFi() const
{
    return iCan>numvertex;
}

void Candidat::seguent()
{
    if (esFi())
        cout<<("No hi ha m�s candidats");
    iCan++;
}

bool Candidat::esValid()const{
    return iCan!=invalid;
}
