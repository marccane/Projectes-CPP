//Marc Cané Salamià
//u1939666
//Sessió 8
#include <iostream>
#include "GrafVMap.h"
#include <queue>
#include <stack>

using namespace std;

void nodesorigen(const GrafVMap &g, int &numnodesorigen, int &ultimnodeorigen){
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

void nodesterminal(const GrafVMap &g, int &numnodesterminal, int &ultimnodeterminal){
    numnodesterminal=0;
    for(int i=1;i<=g.nVertexs();i++)
        if(g.Numero_veins(i)==0){
            numnodesterminal++;
            ultimnodeterminal=i;
    }
}

bool hihacami(const GrafVMap &graf, int v1, int v2, int cami[]){
    bool visitats[100];
    int actual;
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
            if(!visitats[i] and graf.Pes_aresta(actual,i)>0){
                cua.push(i);
                cami[i]=actual;
                visitats[i]=true;
            }
        }
    }
	return visitats[v2];
}

int ford_fulkerson(GrafVMap &gr, int origen, int desti){
    int flux=0, cami[100], antecessor;
    while(hihacami(gr,origen,desti,cami)){
        int flux_actual;
        for(int i=desti;i!=origen;i=cami[i]){
            antecessor=cami[i];
            flux_actual=min(flux_actual,(int)gr.Pes_aresta(antecessor,i));
        }
        for(int i=desti;i!=origen;i=cami[i]){
            antecessor=cami[i];
            gr.Modificar_Pes(antecessor,i,gr.Pes_aresta(antecessor,i)-flux_actual);
            gr.Modificar_Pes(i,antecessor,gr.Pes_aresta(i,antecessor)+flux_actual);
        }
        flux+=flux_actual;
    }
    return flux;
}

int main(){
    string nomarxiu;
    int nnodesorigen, nnodesterminals, nodeorigen, nodedesti;
    cout<<"Entra el nom de l'arxiu: ";
    cin>>nomarxiu;
    GrafVMap graf(nomarxiu.c_str(),true), graf_res=graf;

    if(graf.nVertexs()!=0){
        nodesorigen(graf,nnodesorigen,nodeorigen);
        nodesterminal(graf,nnodesterminals,nodedesti);
        //graf.EscriureGraf();
        if(nnodesterminals==1 and nnodesorigen==1)
            cout<<ford_fulkerson(graf_res,nodeorigen,nodedesti)<<endl;
        else{
            cout<<"Hi ha d'haver un sol node origen i un sol node terminal"<<endl;
            cout<<"Hi havia "<<nnodesorigen<<" node/s origen i "<<nnodesterminals<<" node/s terminal/s"<<endl;
            return 1;
        }
    }
    return 0;
}
