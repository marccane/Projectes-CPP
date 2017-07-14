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

node * ArbreBinari::iArbreBinari(char cad[], int &i){
    node * res=NULL;
    int c=Llegir_numeros(cad,i);

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

int ArbreBinari::Llegir_numeros(char * c, int &i){
    int num=0;
    while(esnumero(c[i])){
        num*=10;
        num+=c[i]-'0';
        i++;
    }
    return num;
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

int ArbreBinari::contingut() const{
    if(arrel!=NULL)return arrel->c;
    throw("Aquest arbre es buit");
}

bool ArbreBinari::esnumero(char c){
    return c>='0' and c<='9';
}
