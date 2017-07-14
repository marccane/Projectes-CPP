//Marc Cané Salamià
//u1939666
//Pràctica 4
/*******************************************************************************
 * Arbre Binari Caracters
 *
 * Conte totes les operacions, pero nomes cal implementar les necessaries
 * Si no es demana el contrari, millor no implementar el destructor.
 *
 * 2008
 * JSS - Actualitzats els metodes
 *******************************************************************************/
#ifndef ARBRE_BINARI_CARACTER_H
#define ARBRE_BINARI_CARACTER_H
#include <cstdlib>
#include <string>
using namespace std;

struct node {
    node();
    node(node*,node*,int);
    void node_preordre(string &s);
    node* nodePoda();
    ~node();
	node * fe, * fd;
	int c;
	};

class ArbreBinari{

    // inv: arrel=NULL o arrel és un punter a una jerarquia disjunta de nodes
	node * arrel;
	node * iArbreBinari(char[], int &i);
	// pre: cert; post: retorna cert si el caràcter es un numero
	static inline bool esnumero(char);
	// pre: cert; post: retorna l'enter que s'ha llegit del vector
	static int Llegir_numeros(char*, int &i);
	// pre: cert; post: retorna el numero de fulles de l'arbre
	int nFulles() const;
	// pre: cert; post: cert si l’arbre és buit
	bool esBuit() const;
	// pre: no buit; post: retorna el fill dret
	ArbreBinari * FillDret() const;
	// pre: no buit; post: retorna el fill esquerre
	ArbreBinari * FillEsquerre() const;
	// pre: cert; post: retorna l’element que hi ha a l’arrel
	int contingut() const;
	// pre: cert; post: fa un arbre amb els subarbres a i b
	void arrelar(ArbreBinari & a, ArbreBinari & b, int c);

public:
    //Constructors
    // pre: -; post: crea un arbre buit
	ArbreBinari();
	ArbreBinari(node * a);
	// pre: a<>NULL ^ b<>NULL; post: crea un arbre amb els parametres donats
	ArbreBinari(ArbreBinari & a, ArbreBinari & b, int c);
	ArbreBinari(char cadena[]);
	// Pre: cadena conte el recorregut en preordre d'un arbre d'enters en el format vist a teoria
	// Post: s'ha creat un arbre que correspon al recorregut en preordre que hi ha a cadena
	ArbreBinari(string cadena);
    // pre: cert; post: elimina la memòria que té reservada l’arbre
	~ArbreBinari();

	// Metodes per resoldre el problema plantejat
	// Pre: --
	// Post: diu si el nombre de fulles d'aquest arbre coincideix amb el valor del node arrel
	bool teArrelFulles() const;
	// Pre: --
	// Post: s'han eliminat tots els nodes fulla d'aquest arbre
	void podaFulles();
	// Pre: --
	// Post: retorna cadena amb el recorregut en preordre d'aquest arbre en el format vist a teoria o "<<arbre buit>>" si l'arbre es buit
	string preOrdre() const;

};

#endif
