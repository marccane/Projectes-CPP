//Marc Cané Salamià
//u1939666
//Pràctica 4
#include <iostream>
#include "ArbreBinari.h"
using namespace std;

int main() {
   ArbreBinari *a;
   string entrada;

   getline(cin,entrada);
   while (!cin.eof()) {
     a = new ArbreBinari(entrada);
     cout << string(60,'=') << endl;
     cout << "Arbre processat: " << a->preOrdre() << endl;
     if (a->teArrelFulles())
       cout << "Contingut arrel equival al nombre de fulles" << endl;
     else
       cout << "Contingut arrel diferent del nombre de fulles" << endl;
     a->podaFulles();
     cout << "... i l'arbre amb les fulles podades es: " << a->preOrdre() << endl;
     delete a;
     getline(cin,entrada);
   }
   return(0);
}