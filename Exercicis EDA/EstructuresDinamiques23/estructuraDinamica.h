/*
 *  estructuraDinamica.h
 *  EstructuraDinamica
 *
 *  Created by Santi Espigule.
 *  Copyright (c) 2004 IMA-UdG.
 *
 * Aquest fitxer es comu a tots els programes que usen l'estructura circular
 * simplement encadenada. Cal implementar nomes els metodes que demana cada
 * enunciat.
 */

#ifndef ESTRUCTURESDINAMIQUES1
#define ESTRUCTURESDINAMIQUES1


#include <cstdlib>
#include <iostream>
using namespace std;


struct node
{
    int dada;
    node * seguent;
};

class estructuraDinamica // circular
{
    node *inici;
public:
    estructuraDinamica();
    estructuraDinamica(estructuraDinamica &e);

    void AfegirInici(int i);
    void AfegirFinal(int i);
    void AfegirDespres(int i, int j);
    void AfegirAbans(int i, int j);
    void InserirOrdenadament(int i);

    bool Existeix(int i) const;
	int TreureFinal();
    void Esborrar(int i);

	void OmplirInici(int n);
	void OmplirFinal(int n);
	int nElements() const;

    void Llistar() const;

    // cal "comentar" el destructor si no s'implementa
    ~estructuraDinamica();
};

#endif
