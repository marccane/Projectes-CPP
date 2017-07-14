#include <iostream>
#include "estructuraDinamica.h"
using namespace std;

//////// Problema 3
/*
 * Exemples d'execucio
 *
 * entrada:
   3 4 -3 -4 0
 * sortida:
   -4 -3 3 4
 *
 * entrada:
   9 7 5 -1 0
 * sortida
   -1 9 7 5
 */

int main()
{
	estructuraDinamica e;
	int n;

	cin >> n;

	while ( n!=0 ) {
		if (n > 0)
			e.AfegirFinal(n);
		else
			e.AfegirInici(n);
		cin >> n;
	}
	e.Llistar();

	return 0;
}

