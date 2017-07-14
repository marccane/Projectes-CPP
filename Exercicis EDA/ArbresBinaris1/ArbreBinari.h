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
    node(node*,node*,char);
	char c;
	node * fe, * fd; };

class ArbreBinari{

	node * arrel;

	// metode privat per poder fer el constructor
	//int iArbreBinari(char * cadena, int i);
	node * iArbreBinari(char * cadena, int &i);
public:
	ArbreBinari();
	ArbreBinari(node * a);
	ArbreBinari(ArbreBinari & a, ArbreBinari & b, char c);
	ArbreBinari(char cadena[]);

	// nomes s'ha d'implementar el destructor si el codi ho demana.
	//~ArbreBinari();

	bool arbre_nul() const;
	ArbreBinari * fill_dret() const;
	ArbreBinari * fill_esquerre() const;
	char contingut() const;
	void arrelar(ArbreBinari & a, ArbreBinari & b, char c);

	friend class ItPreordreNodeArbreBinari;
};


#endif
