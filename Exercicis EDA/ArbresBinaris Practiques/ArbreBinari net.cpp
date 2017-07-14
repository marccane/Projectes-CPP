//Marc Cané Salamià
//u1939666
//Pràctica 4
#include <iostream>
#include <string.h>
#include <sstream>
#include "ArbreBinari.h"
using namespace std;

ArbreBinari::ArbreBinari()
{
	arrel = NULL;
}

ArbreBinari::ArbreBinari(node * a)
{
	arrel = a;
}

ArbreBinari::ArbreBinari(ArbreBinari & a, ArbreBinari & b, int contin)
{
	arrel = new node(a.arrel,b.arrel,contin);
	a.arrel = NULL;
	b.arrel = NULL;
}

node::node(node *a,node *b,int cont){
    fe=a;
    fd=b;
    c=cont;
}

void ArbreBinari::arrelar(ArbreBinari & a, ArbreBinari & b, int c) {
  *this = ArbreBinari(a, b, c);
}

ArbreBinari::ArbreBinari(char c[]){
    int t=0;
    arrel=iArbreBinari(c,t);
}

node* ArbreBinari::iArbreBinari(char cad[], int &i){
    node * res=NULL;
    int c=Llegir_numeros(cad,i);

    if(cad[i]!='(') //Si no té fills...
        res=new node(NULL,NULL,c); //cas base: fem un node sense fills (fulla)
    else{
        node * aux=NULL, *aux2=NULL;
        i++; //"("
        if(cad[i]!=' ') //si té fill esquerra
            aux=iArbreBinari(cad,i);
        if(cad[i]==' ')i++; //" "
        if(cad[i]!=')')
            aux2=iArbreBinari(cad,i);
        i++; //')'
        res=new node(aux,aux2,c);
    }
    return res;
}

int ArbreBinari::Llegir_numeros(char * c, int &i){
    int num=0;
    while(esnumero(c[i]))
		num=num*10+c[i++]-'0';
    return num;
}

bool ArbreBinari::esBuit() const{
    return arrel==NULL;
}

ArbreBinari * ArbreBinari::FillDret() const{
    ArbreBinari * res = new ArbreBinari;
	if (esBuit())
		throw("L’arbre es buit");
	else
		res->arrel = arrel->fd;
	return res;
}

ArbreBinari * ArbreBinari::FillEsquerre() const{
    ArbreBinari * res = new ArbreBinari;
	if (esBuit())
		throw("L’arbre es buit");
	else
		res->arrel = arrel->fe;
	return res;
}

int ArbreBinari::contingut() const{
    if(arrel!=NULL)return arrel->c;
    throw("Aquest arbre es buit");
}

bool ArbreBinari::esnumero(char c){
    return c>='0' and c<='9';
}

//!Sessió 5 EDA

ArbreBinari::~ArbreBinari(){
    if (arrel != NULL)
		delete arrel;
}

node::~node(){
    if (fe != NULL)
		delete fe;
	if (fd != NULL)
		delete fd;
}

ArbreBinari::ArbreBinari(string cadena){
    int t=0;
    char chararr[200];
    memcpy(chararr,cadena.c_str(),sizeof(char)*cadena.length());
    arrel=iArbreBinari(chararr,t);
}

void ArbreBinari::podaFulles(){
    arrel->nodePoda();
}

node* node::nodePoda(){
    node *act=this;
    if(this!=NULL){
        if(fe==NULL and fd==NULL){
            act=NULL;
            delete this;
        }
        else{
            fe=fe->nodePoda();
            fd=fd->nodePoda();
        }
    }
    return act;
}

string ArbreBinari::preOrdre() const{
    string s;
    arrel->node_preordre(s);
    return s;
}

void node::node_preordre(string &s){
    if(this!=NULL){
        stringstream tempstream;
        bool tefills=(fe!=NULL or fd!=NULL);
        tempstream<<c;
        s+=tempstream.str();
        if(tefills){
            s+="(";
            fe->node_preordre(s);
            if(fd!=NULL){
                s+=" ";
                fd->node_preordre(s);
            }
            s+=")";
        }
    }
}

bool ArbreBinari::teArrelFulles() const{
    return esBuit()?false:arrel->c==nFulles();
}

int ArbreBinari::nFulles()const {
    return esBuit()?0:FillEsquerre()->nFulles()+FillDret()->nFulles()+1;
}
