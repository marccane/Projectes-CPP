/*
 *  cuaDinamica.h
 *  cuaDinamica
 *
 *  Created by Joan Surrell on Tue Oct 31 2006.
 *  Copyright (c) 2004-2006 IMA-UdG. All rights reserved.
 *
 * Aquest fitxer conte la definicio de la cua dinamica simplement
 * encadenada. Cal implementar tots els metodes.
 * La definicio s'ha fet per una cua d'enters, pero es pot
 * adaptar facilment a qualsevol tipus base.
 */

#ifndef TAD_cuaDinamica_h
#define TAD_cuaDinamica_h

#include <cstdlib>
#include <iostream>
using namespace std;

typedef int element; //"descomentar" per fer una cua d'enter
// typedef char element; //"descomentar" per fer una cua de caracters

struct node
{
    element dada;
    node *seguent;
};

class cuaDinamica
{
    node * inici, * final;
public:
    cuaDinamica();
    cuaDinamica(const cuaDinamica & e); // no es demana

    void Encua(element e);
    void Desencua();
    element Primer() const;
    bool Buida() const;

    ~cuaDinamica();
};


#endif
