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
        cout << "no t� soluci�" << endl;
        return 3;
    }
    return 0;
}
