/*
 *  estructuraDinamica.h
 *  EstructuraDinamica
 *
 *  Created by Joan Surrell on Wed Oct 06 2004.
 *  Copyright (c) 2004-2006 IMA-UdG. All rights reserved.
 *
 * Aquest fitxer es comu a tots els programes que usen l'estructura dinamica
 * simplement encadenada. Cal implementar nomes els metodes que demana cada 
 * enunciat. 
 */

#ifndef TAD_estructuraDinamica_h
#define TAD_estructuraDinamica_h

#include <cstdlib>
#include <iostream>
using namespace std;

struct node
{
    int dada;
    node *seguent;
};

class estructuraDinamica
{
    node * inici;
public:
    estructuraDinamica();
    estructuraDinamica(const estructuraDinamica & e);
    
    void AfegirInici(int i);
    void AfegirFinal(int i);
    void InserirOrdenadament(int i);

    void AfegirDespres(int i, int j);
    void AfegirAbans(int i, int j);
    
    void Esborrar(int i);
	int TreureFinal();
    bool Existeix(int i) const;

	void OmplirInici(int n);
	void OmplirFinal(int n);
	int nElements() const;
	
    void Llistar() const;

    ~estructuraDinamica();
};


#endif
