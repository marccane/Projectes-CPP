#include <iostream>
#include "Data.h"
#include "Hora.h"

using namespace std;

struct Establiment{
    string nom;
    double importcompra;
    Data datacompra;
    Hora horacompra;
};

int main()
{
    Establiment entrada, maxim;
    string e_interes;
    Data d_interes;
    Hora zero;
    zero.Reiniciar_hora();
    int compres=0, totalcompresapartirdelhoradinteres=0;
    double importtotalapartirdelhoradinteres=0;
    maxim.importcompra=0;

    cout<<"INTRODUEIX ESTABLIMENT D'INTERES:"<<endl;
    cout<<"INTRODUEIX DATA D'INTERES:"<<endl;
    cin>>e_interes;
    d_interes.llegir(0);
    cout<<"INTRODUEIX SEQUENCIA DE COMPRES ACABADA EN #: "<<endl;
    while(entrada.nom!="#"){
        cout<<"COMPRA: "<<endl;
        cin>>entrada.nom;
        if(entrada.nom!="#"){
            cout<<"IMPORT: "<<endl;
            cin>>entrada.importcompra;
            entrada.horacompra.Llegir();
            cout<<"DATA: "<<endl;
            entrada.datacompra.llegir(1);
            if(entrada.nom==e_interes){
                if(maxim.importcompra<entrada.importcompra)
                    maxim=entrada;
                compres++;
            }
            if(d_interes.esMesAntiga(entrada.datacompra) or d_interes.esigual and zero.Esmesantiga(entrada.horacompra)){
                totalcompresapartirdelhoradinteres++;
                importtotalapartirdelhoradinteres+=entrada.importcompra;
            }
        }
    }
    if(compres==0)cout<<"NO S'HA REALITZAT CAP COMPRA A "<<e_interes<<endl;
    else{
    cout<<"HI HA "<<compres<<" COMPRES A "<<e_interes<<", LA D'IMPORT MAXIM ES: "<<maxim.nom<<": "<<maxim.importcompra<<" EUROS EL ";
    maxim.datacompra.mostrar(); cout<<" A LES "; maxim.horacompra.Mostrar(); cout<<" "<<endl;
    }
    cout<<"A PARTIR DEL "; d_interes.mostrar();
    cout<<" A LES 00:00 S'HAN REALITZAT "<<totalcompresapartirdelhoradinteres<<" COMPRES AMB UN IMPORT TOTAL DE "<<importtotalapartirdelhoradinteres<< " EUROS"<<endl;
}
