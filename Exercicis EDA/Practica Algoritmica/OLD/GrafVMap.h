//Marc Cané Salamià
//u1939666
//Sessió 8
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

class GrafVMap
{
public:
    GrafVMap(int nVertexs = MIDA_DEFECTE, bool dirigit = false);
    GrafVMap(const char *nomFitxerTGF, bool dirigit = false);
    int nVertexs() const;
    int nArestes() const;
    bool esDirigit() const;
    //void AfegirAresta(int v1, int v2, etiqueta e);
    bool ExisteixAresta(int v1, int v2) const;
    void EsborrarAresta(int v1, int v2);
    void escriureGraf(const char * nomFitxerTGF) const;
    aresta Pes_aresta(int v1, int v2)const;
    //void Modificar_Pes(int v1, int v2, etiqueta pes);
    int Numero_veins(int v)const;
    void EscriureGraf() const;
    void AfegirAresta(int v1, int v2, const aresta &a);
    aresta Dades_aresta(int v1, int v2) const;
    void Transformar_vertex(const string &a, const string &b, int &c, int &d);
	string Nom_vertex(int v) const;

private:
    int _nVertexs; // = _arestes.size()-1 (despreciem element 0)
    int _nArestes;
    bool _dirigit;
    //vector< map<int,etiqueta> > _arestes; // veïns o successors (depenent si dirigit)
    vector<vertex> _arestes;
};

#endif // GRAFVMAP_H


