#include <iostream>
#include <fstream>
#include "Solucio.h"
#include "Solucionador.h"

using namespace std;

int main(int argc, char** argv)
{
    if(argc!=2){
        cout<<"Numero de paràmetres erroni, entra sols el nom del fitxer del laberint"<<endl;
        return 1;
    }

    Solucio sIni(argv[1]);
    Solucionador asolucionar;
    //Posicio pos_ini={0,0};
    Posicio pos_ini(0,0);
    bool teSolucio = asolucionar.Solucionar(sIni,pos_ini);
    if (teSolucio)
        sIni.mostrar();
    else{
        cout << "El laberint no té solució" << endl;
        return 3;
    }
    return 0;
}
