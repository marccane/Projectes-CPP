#include <iostream>
using namespace std;

#include "ArbreBinari.h"

void preordre_binari(const ArbreBinari * a);


/////// Problema 1
/*
 * Exemples d'execucio
 *
 * entrada:
 A(B C)
 * sortida:
 Preordre: A B C
 *
 * entrada:
 A(B(C D) E)
 * sortida
 Preordre: A B C D E
 */

int main()
{
    ArbreBinari * a;
	char entrada[100];

	cin.getline(entrada, 100);
	a = new ArbreBinari(entrada);
    cout << "Preordre: ";
    preordre_binari(a);
    cout << endl;
	return(0);
}


void preordre_binari(const ArbreBinari *a)
{
    if(!a->arbre_nul()){
        cout<<a->contingut()<<" ";
        preordre_binari(a->fill_esquerre());
        preordre_binari(a->fill_dret());
    }
}

