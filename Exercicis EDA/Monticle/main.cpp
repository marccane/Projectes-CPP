#include <iostream>
#include "Monticle.h"

using namespace std;

int main()
{

	int a[] = {6,42,12,55,94,18,44,67};
	Monticle <int>mont(a, 8);
	cout << "preordre: ";
	mont.mostrarPreordre(1);
	cout << endl;
	//system("pause");
	return 0;
}
