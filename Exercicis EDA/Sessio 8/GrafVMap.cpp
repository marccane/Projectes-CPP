//Marc Cané Salamià
//u1939666
//Sessió 8
#include "GrafVMap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

GrafVMap::GrafVMap(int nVertexs, bool dirigit)
{
    _dirigit=dirigit;
    _arestes.resize(nVertexs);
}

GrafVMap::GrafVMap(const char *nomFitxerTGF, bool dirigit)
{
    ifstream f_ent;
    f_ent.open(nomFitxerTGF, ifstream::in);
    _dirigit=dirigit;
    _nArestes=0;
    _nVertexs=0;
    if (f_ent.fail()) cerr << "Arxiu no trobat" <<endl;
    else
    {
        int afrom, ato, apes;
        string entrada;
        _arestes.resize(1);
        f_ent>>entrada;
        while(entrada!="#")
        {
            _arestes.resize(_arestes.size()+1);
            _nVertexs++;
            f_ent>>entrada;
        }
        f_ent>>afrom;
        while(!f_ent.eof())
        {
            f_ent>>ato;
            f_ent>>apes;
            _arestes[afrom].insert(pair<int,etiqueta>(ato,float(apes)));
            _nArestes++;
            f_ent>>afrom;
        }
        f_ent.close();
    }
}

int GrafVMap::nVertexs() const
{
    return _nVertexs;
}

int GrafVMap::nArestes() const
{
    return _nArestes;
}

bool GrafVMap::esDirigit() const
{
    return _dirigit;
}
/*
//Pre: l'aresta que volem esborrar existeix
//Post: L'aresta v1,v2 ha sigut eliminada
void GrafVMap::EsborrarAresta(int v1, int v2){
    _arestes[v1].remove(v2);
    if(!_dirigit)_arestes[v2].remove(v1);
    _nArestes--;
}*/

void GrafVMap::EscriureGraf() const{
    for(int i=1;i<=_nVertexs;i++){
        cout<<"Vertex: "<<i<<" Arestes: ";
        for(map<int,etiqueta>::const_iterator it=_arestes[i].begin();it!=_arestes[i].end();it++)
            cout<<it->first<<" "<<it->second<<",";
        cout<<endl;
    }
}

// Pre: cert
// Post: diu si hi ha aresta de v1 a v2
bool GrafVMap::ExisteixAresta(int v1, int v2) const
{
    return _arestes[v1].count(v2) == 1;
}
// Pre: v1 i v2 son vertexs del graf
// Post: afegeix l'aresta (v1,v2) si no existia
void GrafVMap::AfegirAresta(int v1, int v2, etiqueta e)
{
    _arestes[v1][v2] = e;
    _nArestes++;
    if (not _dirigit) _arestes[v2][v1] = e;
}

int GrafVMap::Numero_veins(int v) const
{
    return _arestes[v].size();
}

etiqueta GrafVMap::Pes_aresta(int v1, int v2)const
{
    map<int,etiqueta>::const_iterator it=_arestes[v1].find(v2);
    if(it!=_arestes[v1].end())return it->second;
    else return 0;
}

void GrafVMap::Modificar_Pes(int v1, int v2, etiqueta pes)
{
    /*map<int,etiqueta>::iterator it=_arestes[v1].find(v2);
    if(it!=_arestes[v1].end())_arestes[v1][v2]=pes;//it->second=pes;
    */
    _arestes[v1][v2]=pes;
}
