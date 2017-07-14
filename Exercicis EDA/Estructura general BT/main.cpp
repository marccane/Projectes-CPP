#include <iostream>
#include "Solucionador.h"

using namespace std;

int main()
{
    Solucio sIni();
    Solucionador asolucionar;
    bool teSolucio = asolucionar.Solucionar(sIni);
    if (teSolucio)
        sIni.mostrar();
    else{
        cout << "no té solució" << endl;
        return 3;
    }
    return 0;
}
