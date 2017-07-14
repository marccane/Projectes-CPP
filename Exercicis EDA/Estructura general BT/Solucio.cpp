#include "Solucio.h"
#include <iostream>
using namespace std;

Solucio::Solucio(){}

void Solucio::mostrar() const{}

bool Solucio::acceptable(const Candidat &iCan) const
{
// pre: cert
// pos: retorna cert si el Candidat es pot afegir a la solució
	return
}
void Solucio::anotar(const Candidat &iCan)
{
// pre: iCan és acceptable
// pos: afegeix iCan a la Solucio
    niv++;

}
void Solucio::desanotar(const Candidat &iCan)
{
// pre: iCan és el darrer Candidat anotat
// pos: es treu iCan de la Solucio (darrer Candidat anotat)

    niv--;
}
bool Solucio::completa() const
{
// pre: cert
// pos: retorna cert si la solució ja és completa

    return 
}
