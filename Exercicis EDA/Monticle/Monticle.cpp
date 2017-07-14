#include "Monticle.h"
#include <iostream>

using namespace std;

template <class element>
Monticle<element>::Monticle(int mida) { // poca utilitat sense poder afegir
										// pre: mida>=0 (error: bad alloc)
										// post: el monticle és buit i podrà guardar fins a mida valors
	maxDades = mida;
	nDades = 0;
	reservar(); // 0..maxDades+1
}
template <class element>
Monticle<element>::Monticle(const Monticle & o) {
	// pre: cert (error: bad alloc)
	// post: es fa una còpia de l’objecte o
	copiar(o);
}
template <class element>
Monticle<element>::Monticle(element * t, int mida) {
	// pre: mida>=>=0 ^ t conte mida elements
	// post: el monticle esta ple i organitzat amb els elements de la taula
	maxDades = mida;
	reservar();
	nDades = mida;
	for (int i = 1; i <= nDades; i++) dades[i] = t[i - 1];
	ferMonticle();
}
template <class element>
Monticle<element>::~Monticle() {
	// pre: cert
	// post: allibera la memòria reservada pel monticle
	alliberar();
}
template <class element>
Monticle<element> & Monticle<element>::operator =(const Monticle &o) {
	// pre: cert (error: bad alloc)
	// post: es fa una còpia de l’objecte o i el retorna
	if (this != &o) {
		alliberar();
		copiar(o);
	}
	return(*this);
}
template <class element>
void Monticle<element>::ajustar(int esq, int dre) {
	// pre: 0<=esq<=dre<=nDades ^ dades[esq+1..dre] formen un monticle parcial
	// post: dades[esq..dre] formen un monticle parcial (o complet si esq=1)
	int i = esq;
	int j = 2 * esq;
	element x = dades[esq];
	if (j<dre && dades[j + 1]<(dades[j])) j++;
	while (j <= dre && (dades[j]<x)) {
		dades[i] = dades[j];
		i = j;
		j *= 2; // j*2
		if (j<dre && dades[j + 1]<(dades[j])) j++;
	}
	dades[i] = x;
}
template <class element>
element Monticle<element>::Minim() const {
	// pre: cert (error: es buit)
	// post: retorna una còpia de l’element més petit del monticle
	if (esBuit())
		throw("Monticle buit");
	return dades[1];
}
template <class element>
void Monticle<element>::TreureMinim() {
	// pre: cert (error: es buit)
	// post: elimina l’element més petit del monticle i reajusta la resta
	if (esBuit())
		throw("Monticle buit");
	dades[1] = dades[nDades];
	nDades--;
	ajustar(1, nDades);
}
template <class element>
void Monticle<element>::ferMonticle() {
	// pre: els elements són a la taula
	// post: organitza els elements com un monticle
	int esq = nDades / 2 + 1;
	int n = 1;
	cout << "Inici:   ";
	mostrarNivells();
	cout << endl;
	while (esq > 1) {
		esq--;
		ajustar(esq, nDades);
		cout << "Pas " << n << ":   ";
		mostrarNivells();
		cout << endl;
		n++;
	}
}
template <class element>
void Monticle<element>::mostrarNivells()const{
	for (int i = 1; i <= nDades;i++) cout << dades[i] << " ";
}
template <class element>
void Monticle<element>::mostrarPreordre(int n)const {
	cout << dades[n] << " ";
	if ((2 * n) <= nDades) mostrarPreordre(2 * n);
	if ((2 * n + 1) <= nDades) mostrarPreordre(2 * n + 1);

}

template <class element>
bool Monticle<element>::esBuit() const {
	// pre: cert
	// post: retorna cert si el monticle es buit
	return(nDades == 0);
}
template <class element>
void Monticle<element>::reservar() {
	// pre: maxDades inicialitzat (error: bad alloc)
	// post: reserva espai per guarda els elements a la taula
	dades = new element[maxDades + 1]; // 0..maxDades, i 0 no es fa servir!
}

template <class element>
void Monticle<element>::copiar(const Monticle &o) {
	// pre: cert (error: bad alloc)
	// post: fa una còpia dels valors del monticle (estatics i dinamics)
	maxDades = o.maxDades;
	nDades = o.nDades;
	reservar();
	for (int i = 0; i <= nDades; i++) {
		dades[i] = o.dades[i];
	}
}
template <class element>
void Monticle<element>::alliberar() {
	// pre: cert
	// post: allibera tota la memòria reservada pel monticle
	delete[] dades;
}


template class Monticle<int>;

