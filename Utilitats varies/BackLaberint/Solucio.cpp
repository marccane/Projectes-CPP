#include "Solucio.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Solucio::Solucio(char* nomfitxer)
{
// pre: n>0
// pos: Solucio preparada per resoldre un problema de mida
    ifstream myfile;
    myfile.open(nomfitxer);
    if(!myfile.is_open())
        cout<<"Arxiu no trobat"<<endl;
    else{
        string temp;
        getline(myfile,temp);
        mida_lab=temp.length();
        cout<<mida_lab<<endl;
        myfile.close();
        myfile.open(nomfitxer); /// que lleeig, pero probablement és més eficient que convertir l'string

        char in;
        for(int i=0;i<mida_lab;i++){
            for(int j=0;j<mida_lab;j++){
                myfile>>in;
                laberint[j][i] = in;
                visitats[i][j]=false;
            }
        }
    }
}

void Solucio::mostrar(){
    for(unsigned i=0;i<candidats.size();i++){
        candidats[i].mostrar();
        Posicio t=candidats[i].actual();
        laberint[t.x][t.y]='#';
    }
    cout<<endl;

    for(int i=0;i<mida_lab;i++){
        for(int j=0;j<mida_lab;j++)
            cout<<laberint[j][i]; //177 218
        cout<<endl;
    }
}

bool Solucio::acceptable(const Candidat &iCan) const
{
    Posicio actual=iCan.actual();
    int x=actual.x, y=actual.y;
    bool dinsrang=actual.x>=0 && actual.y>=0 && actual.x<mida_lab && actual.y<mida_lab;
    bool podempassar=laberint[x][y]=='1';
    return dinsrang && podempassar && !visitats[x][y];
}
void Solucio::anotar(const Candidat &iCan)
{
    niv++;
    visitats[iCan.actual().x][iCan.actual().y]=true;
    candidats.push_back(iCan);
}
void Solucio::desanotar(const Candidat &iCan)
{
    candidats.pop_back();
    visitats[iCan.actual().x][iCan.actual().y]=false;
    niv--;
}
bool Solucio::completa() const
{
    int fi=mida_lab-1;
    Posicio actual=candidats.back().actual();
    return actual.x==fi and actual.y==fi;
}
