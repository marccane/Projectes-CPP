#include "LlistaOrdEnters.h"
#include <iostream>

using namespace std;

LlistaOrdEnters::LlistaOrdEnters()
{
// Pre:--; Post: llista buida
    a_inici=NULL;
}
LlistaOrdEnters::LlistaOrdEnters(const LlistaOrdEnters &o)
{
// Pre:--; Post: la llista es copia de o
    a_inici = NULL;
    copiar(o);
}
bool LlistaOrdEnters::existeix(int e) const
{
// Pre:--; Post: ens diu si e existeix a la llista
    Node *p = a_inici;
    bool fiCerca = false;
    bool trobat = false;
    while ((p!=NULL) && (!fiCerca))
    {
        if (p->dada >= e)
            fiCerca= true;
        else
            p = p->seg;
    }
    if (fiCerca)
    {
        trobat = p->dada == e;
    }
    return(trobat);
}
bool LlistaOrdEnters::buida() const
// Pre:--; Post: Retorna cert si la llista es buida i fals en cas contrari
{
    return (a_inici==NULL);
}
void LlistaOrdEnters::llistar() const
{
// Pre: -
// Post: Mostra per pantalla els elements de la llista
    for(Node* p=a_inici;p!=NULL;p=p->seg){
        cout<<p->dada<<endl;
    }
}
void LlistaOrdEnters::inserir(int e)
{
// Pre:-
// Post: Llista amb l'enter entrat afegit de manera creixent a la llista
    Node *p, *q, *ant;
    bool trobat = false;
    ant = NULL;
    q = a_inici;
    while((q!=NULL) && (!trobat))
    {
        if(q->dada>=e)trobat=true;
        else{
            ant=q;
            q=q->seg;
        }
    }
    if (trobat){
        if (q->dada!=e){
            p=new Node;
            p->dada=e;
            if(a_inici==q)a_inici=p;
            else ant->seg=p;
            p->seg=q;
        }
    }
    else
    {
        p=new Node;
        p->dada=e;
        p->seg=NULL;
        if(buida())a_inici=p;
        else ant->seg=p;
        //cout<<"Arribo al 11"<<endl;
    }
}
void LlistaOrdEnters::esborrar(int e)
{
// Pre: -
// Post: Llista amb el nombre entrat esborrat
    Node *p, *ant;
    bool trobat = false;
    p = a_inici;
    ant = NULL;
    while((p!=NULL) && (!trobat))
    {
        if(p->dada==e)trobat=true;
        else{
            ant=p;
            p=p->seg;
        }
    }
    if (trobat)
    {
        if(p==a_inici){
            a_inici=a_inici->seg;
        }
        else{
            ant->seg=p->seg;
        }
        delete p;
    }
    else cout<<"Numero no trobat a la llista"<<endl;
}
void LlistaOrdEnters::copiar(const LlistaOrdEnters &o)
{
// Pre: llista buida; Post: aquesta llista es copia de o
    Node *ant, *p, *q;
    if(!o.buida())
    {
        p = o.a_inici;
        q = new Node;
        a_inici = ant = q;
        q->dada= p->dada;
        q->seg= NULL;
        p = p->seg;
        while (p != NULL)
        {
            q= new Node;
            q->dada= p->dada;
            q->seg=NULL;
            ant->seg=q;
            ant= q;
            p = p->seg;
        }
    }
}
LlistaOrdEnters::~LlistaOrdEnters()
{
// Pre: --; Post: memoria dinamica alliberada
    alliberar();
}
void LlistaOrdEnters::alliberar()
{
// Pre: --; Post: memoria dinamica alliberada
    Node *p, *q;
    p = a_inici;
    while (p != NULL)
    {
        q=p;
        p=p->seg;
        delete q;
    }
}
