#ifndef CUAESTATICA_H
#define CUAESTATICA_H

#include "Cua.h"


const int MIDA_DEFECTE = 1000;

template <class element>
class CuaEstatica : public Cua<element> {
public:
	CuaEstatica(int mida = MIDA_DEFECTE); // pre: mida>=0; post: una cua que pot guardar mida elements
	CuaEstatica(const CuaEstatica &o); // pre: cert post: es fa un duplicat
	~CuaEstatica(); // pre: cert; post: s’ha alliberat tota la memòria
	CuaEstatica & operator =(const CuaEstatica &o); // pre: cert post: es fa una còpia de l’objecte

	void Encua(const element &e); // pre: cert; post: es posa l’element e al final
	void Desencua(); // pre: no buida; post: s’ha tret el primer element de la cua
	
	element Primer() const; // pre: no buida; post: es retorna el primer element de la cua
	bool esBuida() const; // pre: cert; post: cert si la cua no té elements
	bool esPlena() const; // pre: cert; post: cert si no es poden posar més elements a la cua 
private:
	void reserva();
	void copia(const CuaEstatica &o);
	void allibera();

	// inv 0<=nDades<=maxDades
	element * dades;
	int inici, nDades, maxDades;
};

#endif // CUAESTATICA_H
