#include <iostream>
#include "estructuraDinamica.h"
using namespace std;

/////// Problema 1
/*
 * Exemples d'execucio
 *
 * entrada:
   5 6 7 8 0
 * sortida:
   8 7 6 5
   8 7 6 5
 *
 * entrada:
   1 3 5 7 0
 * sortida
   7 5 3 1
   7 5 3 1
 */
int main()
{
	estructuraDinamica e;
	int n;

	cin >> n;

	while (n != 0) {
		e.AfegirInici(n);
		cin >> n;
	}
	e.Llistar();

	estructuraDinamica e2(e);
	e2.Llistar();

	return 0;
}
