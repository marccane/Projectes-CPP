#include <iostream>
using namespace std;

#include "ArbreBinari.h"

//!Arbre binari té arrel(punter a node), node té fills i contingut

ArbreBinari::ArbreBinari()
{
	arrel = NULL;
}

ArbreBinari::ArbreBinari(node * a)
{
	arrel = a;
}

ArbreBinari::ArbreBinari(ArbreBinari & a, ArbreBinari & b, char contin)
{
	arrel = new node(a.arrel,b.arrel,contin);
	a.arrel = NULL;
	b.arrel = NULL;
}

node::node(node *a,node *b,char cont){
    fe=a;
    fd=b;
    c=cont;
}

void ArbreBinari::arrelar(ArbreBinari & a, ArbreBinari & b, char c) {
  *this = ArbreBinari(a, b, c);
}

ArbreBinari::ArbreBinari(char c[]){
    int t=0;
    arrel=iArbreBinari(c,t);
}

node * ArbreBinari::iArbreBinari(char cad[], int &i){
    node * res=NULL;
    char c=cad[i];
    i++;
    if(cad[i]!='(') //Si no té fills...
        res=new node(NULL,NULL,c); //cas base: fem un node sense fills (fulla)
    else{
        node * aux=NULL, *aux2=NULL;
        i++; //"("
        if(cad[i]!=' ')//si té fill esquerra
            aux=iArbreBinari(cad,i);
        if(cad[i]==' ')i++; //" "
        if(cad[i]!=')')
            aux2=iArbreBinari(cad,i);
        i++; //')'
        res=new node(aux,aux2,c);
    }
    return res;
}

bool ArbreBinari::arbre_nul() const{
    return arrel==NULL;
}
ArbreBinari * ArbreBinari::fill_dret() const{
    //return new ArbreBinari(arrel->fd);
    ArbreBinari * res = new ArbreBinari;
	if (arbre_nul())
		throw("L’arbre es buit");
	else
		res->arrel = arrel->fd;
	return res;
}
ArbreBinari * ArbreBinari::fill_esquerre() const{
    //return new ArbreBinari(arrel->fe);
    ArbreBinari * res = new ArbreBinari;
	if (arbre_nul())
		throw("L’arbre es buit");
	else
		res->arrel = arrel->fe;
	return res;
}
char ArbreBinari::contingut() const{
    if(arrel!=NULL)return arrel->c;
    throw("Aquest arbre es buit");
}
