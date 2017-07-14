#ifndef ARBREBINARIDINAMIC_H
#define ARBREBINARIDINAMIC_H

#include "ArbreBinari.h"

template <class element>
class ArbreBinariDinamic : public ArbreBinari<element> {
public:
	ArbreBinariDinamic(); // pre: -; post: crea un arbre buit
	ArbreBinariDinamic(ArbreBinariDinamic*a, ArbreBinariDinamic*b, const element &c); // pre: a<>NULL ^ b<>NULL; post: crea un arbre amb els parametres donats
	~ArbreBinariDinamic(); // pre: cert; post: elimina la memòria que té reservada l’arbre

	bool esBuit() const; // pre: cert; post: cert si l’arbre és buit
	element Contingut() const; // pre: cert; post: retorna l’element que hi ha a l’arrel
	ArbreBinari<element> * FillEsquerre() const; // pre: no buit; post: retorna el fill esquerre
	ArbreBinari<element> * FillDret() const; // pre: no buit; post: retorna el fill dret
    /// void Arrelar(ArbreBinari *a, ArbreBinari *b, element c);
	void mostrar(ArbreBinari<element> * a) const;
	void CrearArbreBaratu(ArbreBinari<element>* a);
private:
	struct Nus {
		element cont;
		Nus *fe, *fd;

		Nus();
		Nus(Nus *a, Nus *b, const element &c);
		~Nus();
	};

	ArbreBinariDinamic(const ArbreBinariDinamic &a); // no es pot usar el ct de còpia
	ArbreBinariDinamic & operator=(const ArbreBinariDinamic &a); // no es pot usar l'op =


	// inv: arrel=NULL o arrel és un punter a una jerarquia disjunta de nodes
	Nus * arrel; // representació de l’arbre


};

#endif // ARBREBINARIDINAMIC_H
