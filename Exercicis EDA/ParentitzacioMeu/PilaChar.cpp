#include "PilaChar.h"
#include <iostream>

using namespace std;

// Pre: --; Post: pila buida
// COST: O(1)
PilaChar::PilaChar(){
    a_cim= 0;
}

// Pre: --; Post: aquesta pila és còpia de la pila o
// COST: O(n)
PilaChar::PilaChar(const PilaChar& o){
    a_cim= 0;
    copia(o); // crida a mètode privat
}

// Pre: --; Post: memòria alliberada
// COST: O(n)
PilaChar::~PilaChar(){
    allibera(); // crida a mètode privat
}

// CONSULTORS -------------------------------------------------
// Pre: --
// Post: retorna cert si la pila és buida; fals en c.c.
// COST: O(1)
bool PilaChar::buida() const{
    return a_cim==0;
}

// Pre: pila no buida
// Post: retorna el valor del cim de la pila
// COST: O(1)
char PilaChar::cim() const{
    //if(a_cim==0)cout<<"ERROR! LA PILA ES BUIDA!, posa els checks on toquen!"<<endl;
    if(!buida())return a_cim->valor;
	else { //per anar bé aixo no s'hauria dexecutar mai
	    cout<<"CAGADA, LA PILA ES BUIDA";
		char temp=' ';
		return temp;
	}
}

// MODIFICADORS -----------------------------------------------
// Pre: --; Post: ha afegit s dalt de la pila
// COST: O(1)
// Pre: --; Post: ha afegit s a dalt de la pila
// COST: O(1)
void PilaChar::empila(char s){
    Node* nou= new Node; // necessari reservar memoria
    nou->valor= s;
    nou->seg= a_cim;
    a_cim= nou;
   // cout<<"sha empilat"<<endl;
}

// Pre: pila no buida
// Post: ha eliminat element de dalt de la pila
// COST: O(1)
void PilaChar::desempila(){
    Node* aux= a_cim;
    a_cim= a_cim->seg;
    delete aux;
   // cout<<"sha desempilat"<<endl;
}

// OPERADORS ---------------------------------------------
// Pre: -- ; Post: aquesta pila es copia de o
// COST: O(n)
PilaChar& PilaChar::operator=(const PilaChar& o){
    if (this != &o){
        allibera();
        copia(o);
    }
    return *this;
}

// METODES PRIVATS ------------------------------------------
// Pre: pila buida; Post: aquesta pila es copia de o
// COST: O(n)
void PilaChar::copia(const PilaChar& o) {
    if(!o.buida()){
        Node *p, *q, *aux;
        p = new Node; a_cim = p;
        aux = o.a_cim; p->valor = aux->valor; p->seg = 0;
        q = p;
        while (aux->seg!=0) {
            aux = aux->seg;
            p = new Node; q->seg = p;
            p->valor = aux->valor; p->seg = 0;
            q = p;
        }
    }
}

// Pre: --; Post: memòria alliberada
// COST: O(n)
void PilaChar::allibera(){
    while (!buida()) {
        Node* aux= a_cim;
        a_cim= a_cim->seg;
        delete aux;
    }
}
