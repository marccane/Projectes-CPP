#include <iostream>
#include "LlistaOrdEnters.h"

using namespace std;

int main()
{
    int entrada, a_borrar;
    LlistaOrdEnters llista;
    cout << "Entra una llista d'enters, entra 0 per acabar" << endl;
    do{
        cin>>entrada;
        if(entrada!=0 and !llista.existeix(entrada))llista.inserir(entrada);
    }while(entrada!=0);
    cout << "Estat de la llista abans d'esborrar el numero" << endl;
    llista.llistar();
    cout <<endl<< "Entra el numero a esborrar: ";
    cin>>a_borrar;
    llista.esborrar(a_borrar);
    cout <<endl<<"Estat de la llista despres d'esborrar el numero" << endl;
    llista.llistar();
    return 0;
}
