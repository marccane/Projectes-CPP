#include "Candidat.h"
#include <iostream>
using namespace std;

Candidat::Candidat()
{
// pre: n>0
// pos: s’ha inicialitzat el candidat
    iCan = ;
}

int Candidat::actual() const
{
// pre: cert (error: no hi ha candidat)
// post: retorna el Candidat actual
    if (esFi())
        cout<<("No hi ha més candidats");
    return iCan;
}
bool Candidat::esFi() const
{
// pre: cert
// post: retorna cert si ja no queden candidats
    return iCan>=;
}

void Candidat::seguent()
{
// pre: cert (error: no hi ha candidat)
// post: passa al següent candidat
    if (esFi())
        cout<<("No hi ha més candidats");
    iCan++;
}

void Candidat::mostrar() const{
}
