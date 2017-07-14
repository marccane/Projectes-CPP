#include "CuaEstatica.h"
#include <iostream>

using namespace std;


template <class element>
CuaEstatica<element>::CuaEstatica(int mida) {
// pre: mida>=0 (error: bad_alloc)
// post: s’ha inicialitzat una cua que pot guardar fins a mida elements
	maxDades = mida;
	nDades = 0;
	inici = 0;
	reserva(); // bad alloc
}


template <class element>
CuaEstatica<element>::CuaEstatica(const CuaEstatica &o) {
// pre: cert (error: bad_alloc)
// post: es fa un duplicat de l’objecte o
	copia(o); // bad alloc
}


template <class element>
CuaEstatica<element>::~CuaEstatica() {
// pre: cert
// post: s’ha alliberat tota la memòria de la classe
	allibera();
}


template <class element>
CuaEstatica<element> & CuaEstatica<element>::operator =(const CuaEstatica &o) {
// pre: cert (error: bad alloc)
// post: es fa un duplicat de l’objecte o i es retorna
	if (this != &o) {
		allibera();
		copia(o); // bad alloc
	}
	return *this;
}


template <class element>
void CuaEstatica<element>::Encua(const element &e) {
// pre: cert (error: cua plena)
// post: s’ha posat l’element e al final de la cua
	if (esPlena())
		throw("La cua es plena");
	else {
		dades[(inici+nDades)%maxDades] = e;
		nDades++;
	}
}


template <class element>
void CuaEstatica<element>::Desencua() {
// pre: cert (error: cua buida)
// post: s’ha tret el primer element de la cua
	if (esBuida())
		throw("La cua es buida");
	else {
		inici = (inici+1)%maxDades;
		nDades--;
	}
}


template <class element>
element CuaEstatica<element>::Primer() const {
// pre: cert (error: cua buida)
// post: es retorna una còpia del primer element de la cua
	element res;
	if (esBuida())
		throw("La cua es buida");
	else {
		res = dades[inici];
	}
	return(res);
}


template <class element>
bool CuaEstatica<element>::esBuida() const {
// pre: cert
// post: retorna cert si la cua no té elements
	return(nDades == 0);
}


template <class element>
bool CuaEstatica<element>::esPlena() const {
// pre: cert
// post: retorna cert si no es poden posar més elements a la cua
	return(nDades == maxDades);
}


template <class element>
void CuaEstatica<element>::reserva() {
// pre: maxDades inicialitzat (error: bad_alloc)
// post: s’ha reservat espai per a la taula
	dades = new element[maxDades]; // bad_alloc
}


template <class element>
void CuaEstatica<element>::copia(const CuaEstatica &o) {
// pre: cert (error: bad_alloc)
// post: es fa un duplicat dels atributs (estàtics i dinàmics)
	maxDades = o.maxDades;
	nDades = o.nDades;
	inici = o.inici;
	reserva(); // bad alloc
	for (int i=o.inici; i<(o.inici+o.nDades); i++)
		dades[i%maxDades] = o.dades[i%o.maxDades];
}


template <class element>
void CuaEstatica<element>::allibera() {
// pre: cert
// post: s’allibera l’espai usat en la taula.
	delete [] dades;
	dades = NULL; // per assegurar que no s’hi accedeix
}

template class CuaEstatica<int>;
