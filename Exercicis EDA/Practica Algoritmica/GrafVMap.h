//Marc Cané Salamià
//u1939666
//Practica Algoritmica
#ifndef GRAFVMAP_H
#define GRAFVMAP_H
#include <vector>
#include <map>
#include <fstream>
using namespace std;

const int MIDA_DEFECTE = 100;

struct aresta{
    float prob_atemptat;
    int distancia;
};

struct vertex{
    string nom;
    map<int,aresta> veins;
};

/** \brief  Conte les dades d'un graf amb arestes ponderades i vertex amb nom*/
class GrafVMap
{
    public:
        /** @pre nVertexs>=0
        @post el graf ha sigut inicialitzat*/
        GrafVMap(int nVertexs = MIDA_DEFECTE, bool dirigit = false);
        /** @pre nomFitxerTGF conte el nom d'un arxiu TGF valid
        @post el graf ha carregat les dades del fitxer*/
        GrafVMap(const char *nomFitxerTGF, bool dirigit = false);
        /** @pre cert
        @post retorna el nombre de vertex del graf */
        int nVertexs() const;
        /** @pre cert
        @post retorna el nombre d'arestes del graf*/
        int nArestes() const;
        /** @pre cert
        @post retorna cert si el graf es dirigit*/
        bool esDirigit() const;
        /** @pre cert
         @post retorna cert si hi ha aresta de v1 a v2*/
        bool ExisteixAresta(int v1, int v2) const;
        /** @pre: l'aresta que volem esborrar existeix
        @post L'aresta v1,v2 ha sigut eliminada*/
        void EsborrarAresta(int v1, int v2);
        /** @pre 0<v<nVertex
        @post retorna el numero de veins del vertex n*/
        int Numero_veins(int v)const;
        /** @pre  v1 i v2 son vertexs del graf
         @post afegeix l'aresta (v1,v2) si no existia*/
        void AfegirAresta(int v1, int v2, const aresta &a);
        /** @pre cert
        @post els index dels vertex de nom a,b estan a c,d*/
        void Transformar_vertex(const string &a, const string &b, int &c, int &d);
        /** @pre cert
        @post retorna les dades de la aresta v1,v2*/
        aresta Dades_aresta(int v1, int v2) const;
        /** @pre cert
        @post retorna el nom del vertex v*/
        string Nom_vertex(int v) const;

    private:
        /** @pre cert
        @post retorna cert si el vertex es valid*/
        bool esValid(int v)const{return v>=1 and v<=_nVertexs;}

        int _nVertexs; // = _arestes.size()-1 (despreciem element 0)
        int _nArestes;
        bool _dirigit;
        vector<vertex> _arestes;
};

#endif // GRAFVMAP_H


