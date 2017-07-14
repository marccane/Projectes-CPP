#ifndef ARBREBINARI_H
#define ARBREBINARI_H

template <class element>
class ArbreBinari {
  public:
    ArbreBinari(); // buit
    ArbreBinari(ArbreBinari*a, ArbreBinari*b, const element&c);
    virtual ~ArbreBinari(); // cal una implementacio buida
    virtual bool esBuit() const = 0;
    virtual element Contingut() const = 0;
    virtual ArbreBinari * FillEsquerre() const = 0;
    virtual ArbreBinari * FillDret() const = 0;
// virtual void Arrelar(ArbreBinari*a, ArbreBinari*b, const element &c)=0;
// se substitueix pel constructor amb paràmetres.
};

#endif
