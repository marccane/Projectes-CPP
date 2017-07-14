#ifndef ARBREBINARIDINAMIC_H
#define ARBREBINARIDINAMIC_H
#include "ArbreBinari.h"

template <class element>
class ArbreBinariDinamic : public ArbreBinari<element> {
  public:
    ArbreBinariDinamic();
    ArbreBinariDinamic(ArbreBinariDinamic *a, ArbreBinariDinamic *b,const element &c);
    ~ArbreBinariDinamic();
    bool esBuit() const;
    element Contingut() const;
    ArbreBinari<element> * FillEsquerre() const;
    ArbreBinari<element> * FillDret() const;
    void Mostrar1() const;
    void CrearArbreBaratu();
  private:
    struct Nus {
        element cont;
        Nus *fe, *fd;
        Nus();
        Nus(Nus *a, Nus *b, const element &c);
        ~Nus();
    };
// inv: arrel=NUL o arrel és un punter a una jerarquia disjunta de nodes
    Nus * arrel; // representació de l’arbre
  public:
// falta declarar els iteradors…
};

#endif
