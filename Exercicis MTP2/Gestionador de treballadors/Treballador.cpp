#include <iostream>
#include "Treballador.h"
using namespace std;
const string Treballador::ULTIM_NOM = "#";
//CONSTRUCTOR
Treballador::Treballador(){
//Pre: --
//Post: treballador inicialitzat (sou 0, nom i lloc treball " " i dates 1/1/1600)
    a_nom = " ";
    a_llocTreball = " ";
    a_sou = 0;
}
  // MÈTODES CONSULTORS
void Treballador::mostrar() const{
//Pre: --
//Post: mostra la informació de treballador actual
    cout<<a_nom<<" - "<<a_llocTreball<<" - "<<a_sou<<" euros Contractacio: ";
    a_dCont.mostrar();
    cout<<"Naixement: ";
    a_dNaix.mostrar();
}
bool Treballador::esMesAntic(Treballador p) const{
//Pre: --
//Post: cert si el treballador actual és més antic que p a l’empresa, fals altrament
    return a_dCont.esMesAntiga(p.a_dCont);
}

void Treballador::llegirSou(){
//Pre: --
//Post: llegeix un sou vàlid >0
    cin>>a_sou;
    while(a_sou<0){
        cout<<"ENTRA UN SOU VALID: ";
        cin>>a_sou;
    }
}

bool Treballador::llegir(){
//Pre: --;
//Post: retorna cert si el treballador conté informació vàlida, fals si ha llegit marcaFi
    cout<<"NOM: ";
    string nom;
    cin>>nom;
    if(nom!=ULTIM_NOM){
        a_nom=nom;
        cout<<"DATA DE CONTRACTACIO: ";
        a_dCont.llegir();
        cout<<"LLOC TREBALL: ";
        cin>>a_llocTreball;
        cout<<"SOU: ";
        llegirSou(); //funció privada de cl. Treballador
        cout<<"DATA DE NAIXEMENT: ";
        a_dNaix.llegir();
    }
    return nom!= ULTIM_NOM;
}
// FUNCIONS PRIVADES

