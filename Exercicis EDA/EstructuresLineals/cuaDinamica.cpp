#include "cuaDinamica.h"

cuaDinamica::cuaDinamica()
{
    inici=final=NULL;
}

cuaDinamica::~cuaDinamica(){
    node *q=inici, *t=NULL;
    while(q!=NULL and q->seguent!=NULL){
        t=q;
        q=q->seguent;
        delete t;
    }
    if(inici!=NULL)delete q;
}

void cuaDinamica::Encua(element e){
    node *nou=new node;
    nou->dada=e;
    nou->seguent=NULL;

    if(inici==NULL){
        inici=final=nou;
    }
    else{
        final->seguent=nou;
        final=nou;
    }
}

void cuaDinamica::Desencua(){
    node *temp=inici;
    if(inici!=NULL){
        if(inici==final)inici=final=NULL;
        else inici=inici->seguent;
        delete temp;
    }
}

bool cuaDinamica::Buida()const{
    return inici==NULL;
}

element cuaDinamica::Primer()const{
    return inici->dada;
}

