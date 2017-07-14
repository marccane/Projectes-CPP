#include <iostream>
#include "ArbreBinari.h"
using namespace std;

void preordre_binari(const ArbreBinari *a);
void inordre_binari(const ArbreBinari *a);
void postordre_binari(const ArbreBinari *a);

int main()
{
    ArbreBinari * a;
	char entrada[100];

	cin.getline(entrada, 100);
	a = new ArbreBinari(entrada);
    cout << "Inordre: ";
    inordre_binari(a);
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

void inordre_binari(const ArbreBinari *a)
{
    if(!a->arbre_nul()){
		inordre_binari(a->fill_esquerre());
		cout<<a->contingut()<<" ";
        inordre_binari(a->fill_dret());
    }
}

void postordre_binari(const ArbreBinari *a)
{
    if(!a->arbre_nul()){
		postordre_binari(a->fill_esquerre());
        postordre_binari(a->fill_dret());
        cout<<a->contingut()<<" ";
    }
}
