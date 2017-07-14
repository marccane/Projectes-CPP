#pragma once
const int MIDA_DEFECTE = 1000;
template <class element>
class Monticle {
public:
	Monticle(int mida = MIDA_DEFECTE);
	Monticle(const Monticle &o);
	Monticle(element * t, int mida); // crea un monticle a partir d’una taula
	~Monticle();
	Monticle & operator =(const Monticle &o);
	element Minim() const;
	void TreureMinim();
	bool esBuit() const;
	void mostrarNivells()const;
	void mostrarPreordre(int n)const; //Pre: n>0 && monticle no buit
private:
	// 0<=nDades<=maxDades ^ dades[0..nDades-1] és un monticle complet
	element * dades;
	int nDades, maxDades;
	void ajustar(int esq, int dre);
	void ferMonticle();
	void reservar();
	void copiar(const Monticle &o);
	void alliberar();
};
