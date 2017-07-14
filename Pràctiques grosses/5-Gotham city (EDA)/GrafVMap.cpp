//Marc Cané Salamià
//u1939666
//Practica Algoritmica
#include "GrafVMap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

GrafVMap::GrafVMap(int nVertexs, bool dirigit)
{
    _dirigit=dirigit;
    _arestes.resize(nVertexs+1);
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
        int afrom, ato;
        string stub;
        vertex v_entrada;
        aresta a_entrada;
        _arestes.resize(1);
        f_ent>>stub;
        while(stub!="#")
        {
            f_ent>>v_entrada.nom;
            _arestes.push_back(v_entrada);
            _nVertexs++;
            f_ent>>stub;
        }
        f_ent>>afrom;
        while(!f_ent.eof())
        {
            f_ent>>ato>>a_entrada.prob_atemptat>>a_entrada.distancia;
            AfegirAresta(afrom,ato,a_entrada);
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

bool GrafVMap::ExisteixAresta(int v1, int v2) const
{
    bool c=esValid(v1) and esValid(v2);
    return c and _arestes[v1].veins.count(v2) == 1;
}

void GrafVMap::AfegirAresta(int v1, int v2, const aresta &a)
{
    _arestes[v1].veins[v2] = a;
    if (not _dirigit)
        _arestes[v2].veins[v1] = a;
    _nArestes++;
}

void GrafVMap::EsborrarAresta(int v1, int v2){
    if(ExisteixAresta(v1,v2)){
        _arestes[v1].veins.erase(v2);
        if (!_dirigit)_arestes[v2].veins.erase(v1);
        _nArestes--;
    }
    else cout<<"No existeix l'aresta a borrar: "<<v1<<" "<<v2<<endl;
}

int GrafVMap::Numero_veins(int v) const
{
    return _arestes[v].veins.size();
}

aresta GrafVMap::Dades_aresta(int v1, int v2)const
{
    map<int,aresta>::const_iterator it=_arestes[v1].veins.find(v2);
    if(it!=_arestes[v1].veins.end())return it->second;
}

void GrafVMap::Transformar_vertex(const string &a, const string &b, int &c, int &d){
    for(int i=1;i<=_nVertexs;i++){
        if(_arestes[i].nom==a)c=i;
        else if(_arestes[i].nom==b)d=i;
    }
}

string GrafVMap::Nom_vertex(int v) const{
	return _arestes[v].nom;
}
