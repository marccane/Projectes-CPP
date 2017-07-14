#include "LlistaLlibres.h"
#include "Llibre.h"
#include <iostream>

using namespace std;

LlistaLlibres::LlistaLlibres()
{
// Pre:--; Post: llista buida
    a_inici=NULL;
}
LlistaLlibres::LlistaLlibres(const LlistaLlibres &o)
{
// Pre:--; Post: la llista es copia de o
    a_inici = NULL;
    copiar(o);
}
bool LlistaLlibres::existeix(Llibre e) const
{
// Pre:--; Post: ens diu si e existeix a la llista
    /*Node *p = a_inici;
    bool fiCerca = false;
    bool trobat = false;
    while ((p!=NULL) && (!fiCerca))
    {
        if (p->dada <= e) //atencio al simbol
            fiCerca= true;
        else
            p = p->seg;
    }
    if (fiCerca)
    {
        trobat = p->dada == e;
    }
    return(trobat);
    */
    for(Node* p=a_inici;p!=NULL;p=p->seg){
        if(p->dada==e)return true;
    }
    return false;
}
bool LlistaLlibres::buida() const
// Pre:--; Post: Retorna cert si la llista es buida i fals en cas contrari
{
    return (a_inici==NULL);
}
void LlistaLlibres::llistar() const
{
// Pre: -
// Post: Mostra per pantalla els elements de la llista
    for(Node* p=a_inici;p!=NULL;p=p->seg){
        p->dada.Mostrar();
    }
}
void LlistaLlibres::inserir(Llibre e)
{
// Pre:-
// Post: Llista amb l'enter entrat afegit de manera creixent a la llista
    Node *p, *q, *ant;
    bool trobat = false;
    ant = NULL;
    q = a_inici;
    while((q!=NULL) && (!trobat))
    {
        if(!(q->dada<e))trobat=true;  //atencio a la condicio
        else{
            ant=q;
            q=q->seg;
        }
    }
    if (trobat){
        if (!(q->dada==e)){
            p=new Node;
            p->dada=e;
            //p->dada.Inserir(e);
            if(a_inici==q)a_inici=p;
            else ant->seg=p;
            p->seg=q;
        }
    }
    else
    {
        p=new Node;
        p->dada=e;
        //p->dada.Inserir(e);
        p->seg=NULL;
        if(buida())a_inici=p;
        else ant->seg=p;
    }
}
void LlistaLlibres::esborrar(Llibre e)
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
void LlistaLlibres::copiar(const LlistaLlibres &o)
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
LlistaLlibres::~LlistaLlibres()
{
// Pre: --; Post: memoria dinamica alliberada
    alliberar();
}
void LlistaLlibres::alliberar()
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

void LlistaLlibres::Actualitzar_Setmana_Llibres(Llibre a){
    for(Node* p=a_inici;p!=NULL;p=p->seg){
        if(a==p->dada){
            p->dada.Actualitzar_Setmana_Llibre(a);
        }
    }
}

void LlistaLlibres::Actualitzar_llibres(){
    for(Node* p=a_inici;p!=NULL;p=p->seg){
        p->dada.Actualitzar_setmana();
    }
}

void LlistaLlibres::Mostrar_mes_venuts(){
    int mesvenut=0, quantitat=0, temp;
    Llibre mesvenuts[50], temp2;
    for(Node* p=a_inici;p!=NULL;p=p->seg){
        temp=p->dada.Venuts_darrermes();
        if(temp>mesvenut){
            quantitat=0;
            mesvenut=temp;
            mesvenuts[quantitat]=p->dada;
            quantitat++;
        }
        else if(temp==mesvenut){
            mesvenut=temp;
            mesvenuts[quantitat]=p->dada;
            quantitat++;
        }
    }
    for(int i=0;i<quantitat;i++){
        for(int j=quantitat-1;j>i;j--){
            if(mesvenuts[j]<mesvenuts[j-1]){
                temp2=mesvenuts[j];
                mesvenuts[j]=mesvenuts[j-1];
                mesvenuts[j-1]=temp2;
            }
        }
    }
    for(int i=0;i<quantitat;i++){
        mesvenuts[i].Mostrar();
    }
}

void LlistaLlibres::Eliminar_novenuts(){
     for(Node* p=a_inici;p!=NULL;p=p->seg){
        if(p->dada.Venuts_darrermes()==0)
            esborrar(p->dada);
    }
}
