#include "Candidat.h"
#include <iostream>
using namespace std;

const int mida=4;

Candidat::Candidat(Posicio p)
{
// pre: n>0
// pos: s’ha inicialitzat el candidat
    iCan = 0;
    anterior=p;
}

Posicio Candidat::actual() const
{
// pre: cert (error: no hi ha candidat)
// post: retorna el Candidat actual
    if (esFi())
        cout<<("No hi ha més candidats");
    return Posicio(anterior.x+despl[iCan].x,anterior.y+despl[iCan].y);
}
bool Candidat::esFi() const
{
// pre: cert
// post: retorna cert si ja no queden candidats
    return iCan>=mida;
}

Posicio Candidat::Get_anterior()const{
    return anterior;
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
    cout<<"("<<anterior.x<<","<<anterior.y<<")";
}
