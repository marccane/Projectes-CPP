#include "Solucio.h"
#include <iostream>
#include <string>
#include <fstream>
#define and &&
#define not !
using namespace std;

Solucio::Solucio(char* nomfitxer, int max_dist, float max_atemp, const string &p_origen, const string &p_desti) //ints o strings??
{
// pre: n>0
// pos: Solucio preparada per resoldre un problema de mida
    //graf.GrafVMap(nomfitxer);
    graf=GrafVMap(nomfitxer);
    nvertex=graf.nVertexs();
    graf.Transformar_vertex(p_origen,p_desti,origen,desti);
    solucio.push_back(origen);
	visitats.resize(nvertex + 1); //vertex o arestes?
	for (int i = 0; i < nvertex + 1; i++)visitats[i] = false;
	maxdist = max_dist;
	max_prob = max_atemp;
	distact = 0;
	prob_at = 1; //?
}

bool Solucio::acceptable(const Candidat &iCan) const
{
// pre: cert
// pos: retorna cert si el Candidat es pot afegir a la solució
	bool res = false;
	if (graf.ExisteixAresta(solucio.back(), iCan.actual())) {
		aresta temp = graf.Dades_aresta(solucio.back(), iCan.actual());
		//cout << "n=" << niv << endl;
		//cout << distact << " " << temp.distancia << " " << maxdist << " " << temp.prob_atemptat << " " << max_prob << " " << iCan.actual() << " " << visitats[iCan.actual()] << endl;
		res = distact + temp.distancia <= maxdist and temp.prob_atemptat <= max_prob and !visitats[iCan.actual()];
	}
	//cout << (res?"acceptem: ":"rebutjem: ") << solucio.back()<<" " << iCan.actual() << endl;
	return res;
}
void Solucio::anotar(const Candidat &iCan)
{
// pre: iCan és acceptable
// pos: afegeix iCan a la Solucio
    //iCan.mostrar(); cout<<endl;
    aresta temp=graf.Dades_aresta(solucio.back(),iCan.actual());
    //prob_antiga=temp.prob_atemptat;
    distact+=temp.distancia;
    //cout<< prob_at<<endl; //!DEBUG
	prob_anterior = prob_at;
	prob_at=(1-prob_at)*(1-temp.prob_atemptat);
    visitats[iCan.actual()]=true;
    //candidats.push_back(iCan);
    solucio.push_back(iCan.actual());
    niv++;

}
void Solucio::desanotar(const Candidat &iCan)
{
// pre: iCan és el darrer Candidat anotat
// pos: es treu iCan de la Solucio (darrer Candidat anotat)
    aresta temp=graf.Dades_aresta(solucio.back(),iCan.actual());
    prob_at=prob_anterior;
    //prob_at=-(temp.prob_atemptat/(1-prob_at)); //revisar
    //cout<< prob_at<<endl; //!DEBUG
    distact-=temp.distancia;
    solucio.pop_back();
    niv--;
}
bool Solucio::completa() const
{
// pre: cert
// pos: retorna cert si la solució ja és completa
    return solucio.back()==desti;
}

int Solucio::Get_nvertex() const{
    return nvertex;
}

void Solucio::mostrar() {
	cout << "Per anar de A a C tenim el seguent cami:"<<endl;
	/*while (!solucio.empty()) {
		cout << graf.Nom_vertex(solucio.back()) << "-"; //back()??
		solucio.pop_back();
	}*/
	for (int i = 0; i < solucio.size(); i++) {
		cout << (i==0?" ":"-")<< graf.Nom_vertex(solucio[i]);
	}
	cout << endl << "amb una probabilitat de patir un atemptat de " << prob_at <<
		endl<<" i amb una distancia total de " << distact << " quilometres"<<endl;
}
