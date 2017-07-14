/*
 *  estructuraDinamica.cpp
 *  EstructuraDinamica
 *
 *  Created by Didac Barragan & Joan Surrell.
 *  Copyright (c) 2004 IMA-UdG.
 *
 * JSS - 2008
 *    cal afegir-hi els metodes a implementar
 */

#include <cstdlib>
#include <iostream>

#include "estructuraDinamica.h"


estructuraDinamica::estructuraDinamica()
{
	inici = NULL;
}

estructuraDinamica::~estructuraDinamica(){
    node *it=inici, *seg;
    while(it->seguent!=NULL){
        seg=it->seguent;
        delete it;
        it=seg;
    }
    delete it;
}

/*
void estructuraDinamica::InserirOrdenadament(int n){
    node* nou=new node, *act=inici, *ant=NULL;
	nou->dada=n;
	//nou->seguent=NULL; //if inici!=null
	if(inici==NULL){
        nou->seguent=NULL;
        inici=nou;
	}
	else {
        while(act->seguent!=NULL and act->dada<n){
            ant=act;
            act=act->seguent;
        }
        if(ant==NULL){
            if(act->dada<n){
                nou->seguent=act->seguent;
                act->seguent=nou;
            }
            else{
                nou->seguent=inici;
                inici=nou;
            }
        }
        else{
            if(act->dada<n){
                nou->seguent=act->seguent;
                act->seguent=nou;
            }
            else{
                ant->seguent=nou;
                nou->seguent=act;
            }
        }
    }
}*/

void estructuraDinamica::InserirOrdenadament(int n){
    node* nou=new node, *act=inici, *ant=NULL;
	nou->dada=n;
	//nou->seguent=NULL; //if inici!=null
	if(inici==NULL){
        nou->seguent=NULL;
        inici=nou;
	}
	else {
        while(act->seguent!=NULL and act->dada<n){
            ant=act;
            act=act->seguent;
        }
        if(act->dada<n){
            nou->seguent=act->seguent;
            act->seguent=nou;
        }
        else if(ant==NULL){
            nou->seguent=inici;
            inici=nou;
        }
        else{
            ant->seguent=nou;
            nou->seguent=act;
        }
    }
}

void estructuraDinamica::Llistar() const
{
	node * p;

	p = inici;
	while (p != NULL)
	{
		cout << p->dada << " ";
		p = p-> seguent;
	}
	cout << endl;
}


