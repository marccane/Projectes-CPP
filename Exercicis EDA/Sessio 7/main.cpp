//Marc Cané Salamià
//u1939666
//Sessió 7
#include <iostream>
#include "GrafVList.h"
#include <queue>
#include <stack>

using namespace std;

void nodesorigen(const GrafVList &g, int &numnodesorigen, int &ultimnodeorigen){
    int nvert=g.nVertexs(), i=1;
    bool entralguna[nvert+1];
    numnodesorigen=0;
    for(int i=1;i<=nvert;i++)entralguna[i]=false;
    while(i<=nvert){
        int j=1;
        while(j<=nvert){
            if(!entralguna[j] and g.ExisteixAresta(i,j))
                entralguna[j]=true;
            j++;
        }
        i++;
    }
    for(int i=1;i<=nvert;i++){
        if(!entralguna[i])ultimnodeorigen=i;
        numnodesorigen+=!entralguna[i];
    }
}

void nodesterminal(const GrafVList &g, int &numnodesterminal, int &ultimnodeterminal){
    numnodesterminal=0;
    for(int i=1;i<=g.nVertexs();i++)
        if(g.Numero_veins(i)==0){
            numnodesterminal++;
            ultimnodeterminal=i;
    }
}

void mostrarcami(GrafVList &graf, int v1, int v2){
    //bool *visitats = new bool[graf.nVertexs()];
    //int *cami = new int[graf.nVertexs()], actual;
    bool visitats[100];
    int cami[200], actual;
    queue<int> cua;

    for(int i=0;i<graf.nVertexs();i++){
        visitats[i]=false;
        cami[i]=-1;
    }
    visitats[v1]=true;
    cua.push(v1);
    while(!cua.empty()){
        actual=cua.front();
        cua.pop();
        for(int i=1;i<=graf.nVertexs();i++){
            if(!visitats[i] and graf.ExisteixAresta(actual,i)){
                cua.push(i);
                cami[i]=actual;
                visitats[i]=true;
            }
        }
    }
    if(!visitats[v2])
        cout<<"No hi ha cami entre els vertex origen i terminal"<<endl;
	else{
		stack<int> pila;
		int i=v2;
		while(i!=-1){
			pila.push(i);
			i=cami[i];
		}

		cout<<"Cami: ";
		while(!pila.empty()){
            cout<<pila.top();
            pila.pop();
            if(!pila.empty())cout<<"-";
		}
		cout<<endl;
	}
	//delete[]cami;
	//delete[]visitats;
}

int main()
{
    string nomarxiu;
    int nnodesorigen, nnodesterminals, nodeorigen, nodedesti;
    cout<<"Entra el nom de l'arxiu: ";
    cin>>nomarxiu;
    GrafVList graf(nomarxiu.c_str(),true);

    if(graf.nVertexs()!=0){
        nodesorigen(graf,nnodesorigen,nodeorigen);
        nodesterminal(graf,nnodesterminals,nodedesti);
        graf.EscriureGraf();
        if(nnodesterminals==1 and nnodesorigen==1)
            mostrarcami(graf,nodeorigen,nodedesti);
        else{
            cout<<"Hi ha d'haver un sol node origen i un sol node terminal"<<endl;
            cout<<"Hi havia "<<nnodesorigen<<" node/s origen i "<<nnodesterminals<<" node/s terminal/s"<<endl;
            return 1;
        }
    }
    return 0;
}

/*
char * cstr = new char [nomarxiu.size()+1];
 strcpy(cstr, nomarxiu.c_str());
 fitxer.open(cstr,…);
 delete [] cstr; */
