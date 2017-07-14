#include <iostream>
#include "Baralla.h"
#include "Joc.h"

using namespace std;

void llegirValors(int &llavor, int &passos){
    //Pre: --
    //Post:
    cout<<"ENTRA LA LLAVOR:"<<endl;
    cin>>llavor;
    cout<<"ENTRA ELS PASSOS:"<<endl;
    cin>>passos;
}

int main(){
    int llavor, passos;
    llegirValors(llavor, passos);
    Baralla baralla(llavor, passos);
    Joc joc(baralla);
    joc.Jugar();
    return 0;
}
