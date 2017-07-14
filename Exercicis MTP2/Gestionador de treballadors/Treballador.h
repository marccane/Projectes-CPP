#ifndef TREBALLADOR_H
#define TREBALLADOR_H

#include <string>
#include "Data.h"

using namespace std;

class Treballador {
// Descripci�: guarda la informaci� d�un treballador d�una empresa (nom, data d�alta,
// lloc que ocupa, sou i data de naixement.)
// Invariant: les dates d�alta i naixament s�n v�lides i el sou >=0
public:
static const string ULTIM_NOM;
// CONSTRUCTORS
Treballador();
// Pre:--; Post: treballador inicialitzat (sou 0, nom i lloc treball " " i dates 1/1/1600)
// CONSULTORS
void mostrar() const;
//Pre: --; Post: mostra la informaci� del treballador actual
bool esMesAntic(Treballador t) const;
//Pre: --; Post; cert si t �s m�s antic que el treballador actual, fals altrament
// MODIFICADORS
bool llegir();
//Pre: --; Post: retorna cert si el treballador cont� inf. v�lida, fals si ha llegit marcaFi
void llegirSou();
private:
Data a_dCont;
Data a_dNaix;
string a_nom;
string a_llocTreball;
double a_sou;
};
#endif // TREBALLADOR_H

