#ifndef ARBREBINARI_H
#define ARBREBINARI_H




template <class element>
class ArbreBinari {
public:
	ArbreBinari() {} //no cal en la classe virtual
	ArbreBinari(ArbreBinari *a, ArbreBinari *b, element c) { };
	virtual ~ArbreBinari() { } // cal una implementacio buida
	virtual bool esBuit() const = 0;
	virtual element Contingut() const = 0;
	virtual ArbreBinari * FillEsquerre() const = 0;
	virtual ArbreBinari * FillDret() const = 0;
	// virtual void Arrelar(ArbreBinari *a, ArbreBinari *b, const element &c) = 0;
};


#endif // ARBREBINARI_H
