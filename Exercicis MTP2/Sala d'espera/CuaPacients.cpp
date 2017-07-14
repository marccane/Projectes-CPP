#include "CuaPacients.h"
#include "Pacient.h"
#include <iostream>
using namespace std;

CuaPacients::CuaPacients(){
// Pre: --; Post: cua buida
// COST: O(1)
 a_primer=a_darrer= NULL;
 atesos=0;
 tempstotal=0;
}
CuaPacients::CuaPacients(const CuaPacients& o){
// Pre: --; Post: aquesta cua és còpia de la cua o
// COST: O(n)
 a_primer=a_darrer= NULL;
 copia(o); // crida a mètode privat
}
CuaPacients::~CuaPacients(){
// Pre: --; Post: memòria alliberada
// COST: O(n)
 allibera(); // crida a mètode privat
}

// CONSULTORS
bool CuaPacients::buida() const{
// Pre: -- ; Post: retorna cert si la cua és buida; fals en c.c.
// COST: O(1)
 return a_primer==NULL;
}
Pacient CuaPacients::primer() const{
// Pre: cua no buida; Post: retorna còpia del primer de la cua
// COST: O(1)
 return a_primer->valor;
}

// MODIFICADORS
void CuaPacients::encua(Pacient s){
// Pre: --; Post: ha afegit s al final de la cua
// COST: O(1)
 Node* nou= new Node;
 nou->valor= s; nou->seg= NULL;
 if (buida()) // this->buida()
 a_primer=a_darrer= nou;
 else {
 a_darrer->seg= nou; a_darrer= nou;
 }
}

void CuaPacients::desencua(){
// Pre: cua no buida; Post: ha eliminat el primer de la cua
// COST: O(1)
 Node* aux= a_primer;
 if (a_primer==a_darrer) // només hi ha un element
 a_primer=a_darrer= NULL;
 else a_primer= a_primer->seg;
 delete aux;
 atesos++;
}
// MÈTODES PRIVATS
void CuaPacients::copia(const CuaPacients& o){
// Pre: cua buida; Post: aquesta cua és còpia de o
// COST: O(n)
 Node* i= o.a_primer;
 while(i!=NULL){ // recorrem cua o
 encua(i->valor); // this->encua(i->valor)
 i=i->seg;
 }
}
void CuaPacients::allibera(){
// Pre: --; Post: cua buida
// COST: O(n)
 while (a_primer!=NULL){ //!buida()
 Node* aux= a_primer;
 a_primer= a_primer->seg;
 delete aux;
 }
 a_darrer= NULL;
}
// OPERADOR ASSIGNACIÓ
CuaPacients& CuaPacients::operator=(const CuaPacients& o){
// Pre: -- ; Post: aquesta cua és còpia de o
// COST: O(n)
 if (this != &o){//! no acabo d'entendre aixo, l'operador != no està redefinit, com ho fa C per compararlos? Té en compte que els punters als nodes NO han d'apuntar al mateix lloc?
 allibera();
 copia(o);
 }
 return *this;
}

void CuaPacients::MostrarCua(){
    const string barres="-------------------------";
    cout<<"LLISTAT DELS PACIENTS"<<endl;
    cout<<barres<<endl;
    if(!buida()){
        for(Node* i=a_primer;i!=a_darrer;i=i->seg){
            i->valor.Mostrar();
            cout<<barres<<endl;
        }
        a_darrer->valor.Mostrar();
        cout<<barres<<endl;
    }
}

int CuaPacients::EnEspera(){
    int comptador=0;
    for(Node* i=a_primer;i!=a_darrer;i=i->seg)
        comptador++;
    if(a_primer!=a_darrer)comptador++;
    return comptador;
}

void CuaPacients::SumaTemps(int temps){
    tempstotal+=temps;
}

void CuaPacients::ResumPacients(){
    cout<<"NOMBRE DE PACIENTS ATESOS:"<<endl<<atesos<<endl;
    if(atesos!=0){
        cout.setf(ios::fixed);
        cout.precision(1);
        cout<<"TEMPS MIG D'ESPERA:"<<endl<<tempstotal/float(atesos)<<endl;
    }
}

/*
Codi residual:
for(Node* i=a_primer;i!=a_darrer;i=i->seg){
        cout<<"CODI: "<<i->valor.GetCodi()<<endl;
        cout<<"NOM: "<<i->valor.GetNom()<<endl;
        cout<<"HORA ENTRADA: ";
        i->valor.MostrarHoraArribada();
        cout<<"-------------------------"<<endl;
        i->valor.Mostrar();
    }
*/
