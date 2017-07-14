//Marc Cané Salamià
//u1939666
//Practica Algoritmica
#include "Solucio.h"
#include <iostream>
#include <fstream>
using namespace std;

Solucio::Solucio(){
    prob_at=0;
}

Solucio::Solucio(char* nomfitxer, int max_dist, float max_atemp, const string &p_origen, const string &p_desti)
{
    graf=GrafVMap(nomfitxer);
    nvertex=graf.nVertexs();
    graf.Transformar_vertex(p_origen,p_desti,origen,desti);
    solucio.push_back(origen);
	visitats.resize(nvertex+1);
	for (int i = 0; i < nvertex + 1; i++)visitats[i] = false;
	visitats[origen]=true;
	maxdist = max_dist;
	max_prob = max_atemp;
	distact = 0;
	prob_at = 1;
}

bool Solucio::acceptable(const Candidat &iCan) const
{
	bool res = false;
	if (solucio.back()!=iCan.actual() and graf.ExisteixAresta(solucio.back(), iCan.actual())) {
		aresta temp = graf.Dades_aresta(solucio.back(), iCan.actual());
		res = distact + temp.distancia <= maxdist and temp.prob_atemptat <= max_prob and !visitats[iCan.actual()];
	}
	//cout << (res?"ACCEPTEM: ":"rebutjem: ") << graf.Nom_vertex(solucio.back())<<" -> "<< graf.Nom_vertex(iCan.actual()) << endl;
	return res;
}

void Solucio::anotar(const Candidat &iCan)
{
    aresta temp=graf.Dades_aresta(solucio.back(),iCan.actual());
    distact+=temp.distancia;
	prob_at*=(1-temp.prob_atemptat);
    visitats[iCan.actual()]=true;
    solucio.push_back(iCan.actual());
}

void Solucio::desanotar(const Candidat &iCan)
{
    solucio.pop_back();
    aresta temp=graf.Dades_aresta(solucio.back(),iCan.actual());
    visitats[iCan.actual()]=false;
    prob_at/=(1-temp.prob_atemptat);
    distact-=temp.distancia;
}

bool Solucio::completa() const
{
    return solucio.back()==desti;
}

int Solucio::Get_nvertex() const{
    return nvertex;
}

void Solucio::mostrar() const{
	cout << "Per anar de "<<graf.Nom_vertex(origen)<<" a "<<graf.Nom_vertex(desti)<<" tenim el seguent cami:"<<endl;
	for (unsigned i = 0; i < solucio.size(); i++) {
		cout << (i==0?"     ":"-")<< graf.Nom_vertex(solucio[i]);
	}
	cout << endl << "amb una probabilitat de patir un atemptat de " << 1-prob_at <<
    endl<<"i amb una distancia total de " << (float)distact/1000 << " quilometres"<<endl;
}

bool Solucio::esMillor(Solucio &optima) const{
   return prob_at>optima.prob_at;
}

void Solucio::Buscar_Prometedor(Candidat &iCan) const{
    Candidat millor(nvertex,invalid);
    iCan=Candidat(nvertex);
    int v=solucio.back();
    float millor_prob=1;
    while(!iCan.esFi()){
        if(vorac.ExisteixAresta(v,iCan.actual())){
            aresta t=vorac.Dades_aresta(v,iCan.actual());
            if(t.prob_atemptat<millor_prob){
                millor_prob=t.prob_atemptat;
                millor=iCan;
            }
            else if(t.prob_atemptat==millor_prob and t.distancia<vorac.Dades_aresta(v,millor.actual()).distancia)
                    millor=iCan;
        }
        iCan.seguent();
    }
    iCan=millor;
}

void Solucio::Inicialitzar_vorac(){
    vorac=graf;
}

void Solucio::Afegir_Candidat(Candidat iCan){
    vorac.EsborrarAresta(solucio.back(),iCan.actual());
    anotar(iCan);
}
