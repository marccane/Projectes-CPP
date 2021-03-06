#include "ArbreBinariDinamic.h"

#include <iostream>

using namespace std;


template <class element>
ArbreBinariDinamic<element>::Nus::Nus() { // segurament no es fa servir mai…
// pre: -
// post: s’inicialitza el node
	fe = fd = NULL;
	// element: valor per defecte
}


template <class element>
ArbreBinariDinamic<element>::Nus::Nus(Nus *a, Nus *b, const element &c) {
	// pre: cert
	// post: posa a com a fill esquerra, b com a fill dret i c com a contingut
	fe = a;
	fd = b;
	cont = c;
}


template <class element>
ArbreBinariDinamic<element>::Nus::~Nus() {
	// pre: cert
	// post: elimina recursivament la memòria dels nodes de l’arbre
	if (fe != NULL)
		delete fe;
	if (fd != NULL)
		delete fd;
}


template <class element>
ArbreBinariDinamic<element>::ArbreBinariDinamic() {
	// pre: -
	// post: crea un arbre buit
	arrel = NULL;
}


template <class element>
ArbreBinariDinamic<element>::ArbreBinariDinamic(ArbreBinariDinamic *a,
	ArbreBinariDinamic *b, const element &c) {
	// pre: a<>NULL ^ b<>NULL (error: bad_alloc)
	// post: crea un arbre amb els parametres donats
	//       i treu el contingut dels arbres donats
	arrel = new Nus(a->arrel, b->arrel, c); // bad alloc
	a->arrel = NULL;
	b->arrel = NULL;
}


template <class element>
ArbreBinariDinamic<element>::~ArbreBinariDinamic() {
	// pre: cert
	// post: elimina la memòria que té reservada l’arbre
	if (arrel != NULL)
		delete arrel;
}


template <class element>
bool ArbreBinariDinamic<element>::esBuit() const {
	// pre: cert
	// post: cert si l’arbre és buit
	return (arrel == NULL);
}


template <class element>
element ArbreBinariDinamic<element>::Contingut() const {
	// pre: cert (error: arbre buit)
	// post: retorna una còpia de l’element que hi ha a l’arrel
	element res;

	if (esBuit())
		throw("L’arbre es buit");
	else
		res = arrel->cont;
	return res;
}


template <class element>
ArbreBinari<element> * ArbreBinariDinamic<element>::FillEsquerre() const {
	// pre: cert (error: arbre buit)
	// post: retorna el fill esquerre de l’arrel (no una còpia!)
	ArbreBinariDinamic * res = new ArbreBinariDinamic;
	if (esBuit())
		throw("L’arbre es buit");
	else
		res->arrel = arrel->fe;
	return res;
}


template <class element>
ArbreBinari<element> * ArbreBinariDinamic<element>::FillDret() const {
	// pre: cert (error: arbre buit)
	// post: retorna el fill dret de l’arrel (no una còpia!)
	ArbreBinariDinamic * res = new ArbreBinariDinamic;
	if (esBuit())
		throw("L’arbre es buit");
	else
		res->arrel = arrel->fd;
	return res;
}

template <class element>
void ArbreBinariDinamic<element>::mostrar(ArbreBinari<element>* a) const {
	if (!a->esBuit()) {
        bool parentesis=!a->FillDret()->esBuit() or !a->FillDret()->esBuit();
		cout << a->Contingut();
		if(parentesis)cout<<"(";
		mostrar(a->FillEsquerre());
		mostrar(a->FillDret());
        if(parentesis)cout<<")";
	}
}
/*
template <class element>
void ArbreBinariDinamic<element>::CrearArbreBaratu(ArbreBinari<element>* a){
    Nus * nou=new Nus;
//    a->Contingut()='A';
    a->FillEsquerre()=nou;
    //a->FillEsquerre()->Contingut()='B';
    nou=new Nus;
    a->FillDret()=nou;
   // a->FillDret()->Contingut()='C';
    nou=new Nus;
    a->FillEsquerre()->FillEsquerre()=nou;
    //a->FillEsquerre()->FillEsquerre()->Contingut()='D';
    nou=new Nus;
    a->FillDret()->FillEsquerre()=nou;
  //  a->FillDret()->FillEsquerre()->Contingut()='E';
}
*/
