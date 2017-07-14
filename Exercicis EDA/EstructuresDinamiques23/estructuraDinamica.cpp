/*
 *  estructuraDinamica.cpp
 *  EstructuraDinamica
 *
 *  Created by Joan Surrell on Wed Oct 06 2004.
 *  Copyright (c) 2004-2006 IMA-UdG. All rights reserved.
 *
 *
 * JSS - 2008
 *    cal afegir-hi els metodes a implementar
 */

#include "estructuraDinamica.h"
#include <iostream>

using namespace std;


estructuraDinamica::estructuraDinamica( )
{
	inici = NULL;
}

estructuraDinamica::~estructuraDinamica(){
    /*node *q=inici, *seg; //falla algu que no acabo de veure :(
    if(inici!=NULL){
        while(q->seguent!=inici){
            seg=q->seguent;
            delete q;
            q=seg->seguent;
        }
        delete q;
    }*/
    node *creativitat[100], *q=inici;
    int comptador=0;
    while(q!=NULL and q->seguent!=inici){creativitat[comptador++]=q;q=q->seguent;}
    for(int i=0;i<comptador;i++)delete creativitat[i];
}

void estructuraDinamica::OmplirFinal(int n){
    node *it=inici, *q, *nou, *stub=new node;
    if(inici==NULL){
        q=stub;
    }
    else{
        while(it->seguent!=inici)it=it->seguent;
        q=it;
    }
    for(int i=1;i<=n;i++){
        nou=new node;
        nou->dada=i;
        q->seguent=nou;
        q=nou;
    }
    if(inici==NULL)inici=stub->seguent;
    nou->seguent=inici;
    delete stub;
}

int estructuraDinamica::nElements()const{
    node *q
    =inici;
    int c=0;
    if(inici!=NULL){
        while(q->seguent!=inici){
            q=q->seguent;
            c++;
        }
        c++;
    }
    return c;
}

void estructuraDinamica::AfegirInici(int n){
	node* p=new node, *q=inici;
	p->dada=n;
	p->seguent=inici; //if inici!=null
	if(inici==NULL)	p->seguent=p;
	else {
        while(q->seguent!=inici)q=q->seguent;
        q->seguent=p;
    }
    inici=p;
}

void estructuraDinamica::AfegirFinal(int n){
	node *p=new node, *q=inici;
	p->dada=n;
	p->seguent=inici;
	if(inici==NULL){
        inici=p;
        p->seguent=p;
	}
    else {
        while(q->seguent!=inici)q=q->seguent;
        q->seguent=p;
    }
}

void estructuraDinamica::AfegirAbans(int n, int m){
    node *p=new node, *q=inici, *ant=NULL, *anticinici=inici, *r=inici;
	p->dada=n;

    if(inici==NULL){
        inici=p;
        p->seguent=p;
    }
    else{
        while(q->dada!=m){
            ant=q;
            q=q->seguent;
        }
        p->seguent=q;
        if(q==inici){
            p->seguent=inici;
            while(r->seguent!=inici)r=r->seguent;
            r->seguent=p;
            inici=p; //! NO MOURE AQUESTA LINIA AMUNT
        }
        else ant->seguent=p;
    }
}

bool estructuraDinamica::Existeix(int n) const{
    bool resultat=false;
    node *q=inici;
    if(inici!=NULL){
        while(q->seguent!=inici and !resultat){
            if(q->dada==n)resultat=true;
            q=q->seguent;
        }
        if(q->dada==n)resultat=true;
    }
    return resultat;
}

void estructuraDinamica::Llistar() const
{
    node *p;

    if (inici != NULL)
    {
        cout << inici->dada << " ";
        p = inici->seguent;
        while (p !=inici)
        {
            cout << p->dada << " ";
            p = p->seguent;
        }
    }
    cout << endl;
}
