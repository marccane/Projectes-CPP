//Marc Cané Salamià
//u1939666
//Sessió 7
#include "GrafVList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

GrafVList::GrafVList(int nVertexs, bool dirigit){
    _dirigit=dirigit;
    _arestes.resize(nVertexs);
}

GrafVList::GrafVList(const char *nomFitxerTGF, bool dirigit){
    ifstream f_ent;
    f_ent.open(nomFitxerTGF, ifstream::in);
    _dirigit=dirigit;
    _nArestes=0;
    _nVertexs=0;
    if (f_ent.fail()) cerr << "Arxiu no trobat" <<endl;
    else {
        int afrom, ato;
        string entrada;
        _arestes.resize(1);
        f_ent>>entrada;
        while(entrada!="#"){
            _arestes.resize(_arestes.size()+1);
            _nVertexs++;
            f_ent>>entrada;
        }
        f_ent>>afrom;
        while(!f_ent.eof()){
            f_ent>>ato;
            _arestes[afrom].push_back(ato);
            _nArestes++;
            f_ent>>afrom;
        }
        f_ent.close();
    }
}

int GrafVList::nVertexs() const{
    return _nVertexs;
}

int GrafVList::nArestes() const{
    return _nArestes;
}

bool GrafVList::esDirigit() const{
    return _dirigit;
}

//Pre: l'aresta que volem esborrar existeix
//Post: L'aresta v1,v2 ha sigut eliminada
void GrafVList::EsborrarAresta(int v1, int v2){
    _arestes[v1].remove(v2);
    if(!_dirigit)_arestes[v2].remove(v1);
    _nArestes--;
}

void GrafVList::EscriureGraf() const{
    for(int i=1;i<=_nVertexs;i++){
        cout<<"Vertex: "<<i<<" Arestes: ";
        for(list<int>::const_iterator it=_arestes[i].begin();it!=_arestes[i].end();it++)
            cout<<*it<<",";
        cout<<endl;
    }
}

// Pre: cert
// Post: diu si hi ha aresta de v1 a v2
bool GrafVList::ExisteixAresta(int v1, int v2) const
{
    if (not esValid(v1) or not esValid(v2)) return false;
    else return (_arestes[v1].end() != find(_arestes[v1].begin(), _arestes[v1].end(), v2));
}

// Pre: v1 i v2 son vertexs del graf
// Post: afegeix l'aresta (v1,v2) si no existia
void GrafVList::AfegirAresta(int v1, int v2)
{
    if (not esValid(v1) or not esValid(v2)) throw "Alguna aresta no es valida";
    else if (not ExisteixAresta(v1,v2))
    {
        _nArestes++;
        _arestes[v1].push_back(v2);
        if (not _dirigit) _arestes[v2].push_back(v1);
    }
}

int GrafVList::Numero_veins(int v) const{
    return _arestes[v].size();
}

/*_arestes.resize(1);
string entrada;
//char cstr[100];
//int stoi;
//f_ent.getline(cstr,80);
//entrada=cstr;
f_ent>>entrada;
while(entrada!="#"){
    /*stringstream ss(entrada);
    ss >> stoi;*/
    //list<int> test;
    //_arestes.push_back(test);
    //f_ent.getline(cstr,80);
    //entrada=cstr;
   /* _arestes.resize(_arestes.size()+1);
    _nVertexs++;
    f_ent>>entrada;
}*/
