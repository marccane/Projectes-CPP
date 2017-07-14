#include <iostream>
#include <fstream>

using namespace std;

struct {
    int dia, mes, any, gent, pluja;
}maxambpluja, maxsensepluja, comprovant;

int main()
{
    string nom;
    int n, minimvisitants, dada=0;
    cin>>minimvisitants;
    cin>>nom;

    fstream fitxer( nom, fstream::in);
    do{
        fitxer >> n;
        comprovant.dia=n;
        fitxer >> n;
        comprovant.mes=n;
        fitxer >> n;
        comprovant.any=n;
        fitxer >> n;
        comprovant.gent=n;
        fitxer >> n;
        comprovant.pluja=n;



    }
    while(n!=-1);
    return 0;
}
