/*******************************************************************************
 * Arbre Binari Caracters
 *
 * Conte totes les operacions, pero nomes cal implementar les necessaries
 * Si no es demana el contrari, millor no implementar el destructor.
 *
 * 2008
 * JSS - Actualitzats els metodes
 *******************************************************************************/
#ifndef ARBRE_BINARI_CARACTER_H
#define ARBRE_BINARI_CARACTER_H
#include <cstdlib>
using namespace std;

struct node {
    node(node*,node*,int);
	int c;
	node * fe, * fd; };

class ArbreBinari{

	node * arrel;
	node * iArbreBinari(char *, int &i);
	static inline bool esnumero(char);
	static int Llegir_numeros(char *, int &i);
public:
	ArbreBinari();
	ArbreBinari(node * a);
	ArbreBinari(ArbreBinari & a, ArbreBinari & b, int c);
	ArbreBinari(char cadena[]);

	// nomes s'ha d'implementar el destructor si el codi ho demana.
	//~ArbreBinari();

	bool arbre_nul() const;
	ArbreBinari * fill_dret() const;
	ArbreBinari * fill_esquerre() const;
	int contingut() const;
	void arrelar(ArbreBinari & a, ArbreBinari & b, int c);

	friend class ItPreordreNodeArbreBinari;
};


#endif
