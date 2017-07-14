#include <iostream>
#include "ArbreBinariDinamic.h"
//#include "ArbreBinariDinamic.cpp"
using namespace std;

void Mostrar1(ArbreBinariDinamic <char>*a) {
// pre: cert (error: arbre buit)
// post: retorna el fill dret de l’arrel (no una còpia!)
    if(a!=NULL){
        cout<<a->Contingut()<<endl;
        //Mostrar1(a->);
        //Mostrar1(a->FillEsquerra());
    }
}

int main()
{
    ArbreBinariDinamic <char>a;
    a.CrearArbreBaratu();
    Mostrar1(&a);
    return 0;
}
