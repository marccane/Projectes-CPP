#include <iostream>
#include "Fraccio.h"

using namespace std;

int main(){
    char operacio;
    Fraccio fraccio1,fraccio2,temporal;
    fraccio1.LlegirFraccio(1);
    cout<<"INTRODUEIX OPERACIO [+-*/]:"<<endl;
    cin>>operacio;
    fraccio2.LlegirFraccio(2);
    fraccio1.PosarSigne();
    fraccio2.PosarSigne();
    temporal.OperarFraccio(operacio,fraccio1,fraccio2);
    temporal.SimplificarFraccio();
    temporal.Mostrar();
    return 0;
}
