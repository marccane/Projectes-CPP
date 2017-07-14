//Marc Cané Salamià
//u1939666
//Sessió 7
#ifndef GRAFVLIST_H
#define GRAFVLIST_H

#include <vector>
#include <list>
#include <fstream>
const int MIDA_DEFECTE = 1000;

class GrafVList
{
public:
    GrafVList(int nVertexs = MIDA_DEFECTE, bool dirigit = false);
    GrafVList(const char *nomFitxerTGF, bool dirigit = false);
    int nVertexs() const;
    int nArestes() const;
    bool esDirigit() const;
    void AfegirAresta(int v1, int v2);
    bool ExisteixAresta(int v1, int v2) const;
    void EsborrarAresta(int v1, int v2);
    void EscriureGraf() const;
    int Numero_veins(int v) const;
private:
    int _nVertexs; // = _arestes.size()-1 (despreciem element 0)
    int _nArestes;
    bool _dirigit;
    std::vector< std::list<int> > _arestes; // veïns o successors (depenent si dirigit)
    bool esValid(int v) const
    {
        return v >= 1 and v <= _nVertexs;
    }
};

#endif // GRAFVLIST_H
