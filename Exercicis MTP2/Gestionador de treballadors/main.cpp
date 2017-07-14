#include <iostream>
#include "Treballador.h"

using namespace std;

int main()
{
    Treballador actual, mesantic;
    cout<<"INTRODUEIX ELS TREBALLADORS DE L'EMPRESA ACABANT AMB NOM DE TREBALLADOR #:"<<endl;
    while(actual.llegir()){
        if(actual.esMesAntic(mesantic))
            mesantic=actual;
    }
    cout<<"LA PERSONA EN PLANTILLA DES DE FA MES ANYS ES: "<<endl;
    mesantic.mostrar();
    return 0;
}
