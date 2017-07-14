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
    myfile.open(nomfitxer); /// ".\\algo.txt"
    if(!myfile.is_open()){
        cout<<"Arxiu no trobat"<<endl;
    }
    else{
        string temp;
        getline(myfile,temp);
        //cout<<temp;
        mida_lab=temp.length();
        cout<<mida_lab<<endl;
        myfile.close();
        myfile.open(nomfitxer); /// que lleeig, pero probablement és més eficient que convertir l'string

        char in;//Com llegir: bools? enters? nope, chars?
        for(int i=0;i<mida_lab;i++){
            for(int j=0;j<mida_lab;j++){
                myfile>>in;
                laberint[j][i] = in=='1';
                visitats[i][j]=false;
            }
            //myfile>>in; //endl? cal??
        }
        for(int i=0;i<mida_lab;i++){
            for(int j=0;j<mida_lab;j++)
                cout<<char(laberint[j][i]+218); //177
            cout<<endl;
        }
    }
}

void Solucio::mostrar() const{
     for(int i=0;i<candidats.size();i++){
        candidats[i].mostrar();
    }
}

bool Solucio::acceptable(const Candidat &iCan) const
{
// pre: cert
// pos: retorna cert si el Candidat es pot afegir a la solució
    //Posicio temp=iCan.Get_anterior();
    //int x=temp.x+despl[iCan.actual()].x, y=temp.y+despl[iCan.actual()].y;
    Posicio actual=iCan.actual();
    int x=actual.x, y=actual.y;
    bool dinsrang=actual.x>=0 && actual.y>=0 && actual.x<mida_lab && actual.y<mida_lab;
    bool podempassar=laberint[x][y];
    //iCan.mostrar(); cout<<dinsrang<<podempassar<<!visitats[x][y]<<" x: "<<x<<" y: "<<y<<endl;
    return dinsrang && podempassar && !visitats[x][y];
}
void Solucio::anotar(const Candidat &iCan)
{
// pre: iCan és acceptable
// pos: afegeix iCan a la Solucio
    niv++;
    visitats[iCan.actual().x][iCan.actual().y]=true;
    candidats.push_back(iCan);
    //iCan.mostrar(); cout<<endl;
}
void Solucio::desanotar(const Candidat &iCan)
{
// pre: iCan és el darrer Candidat anotat
// pos: es treu iCan de la Solucio (darrer Candidat anotat)
    candidats.pop_back();
    niv--;
}
bool Solucio::completa() const
{
// pre: cert
// pos: retorna cert si la solució ja és completa
    //return actual.x==mida_lab && actual.y==mida_lab;
    //Posicio pfinal(mida_lab-1,mida_lab-1);
    int fi=mida_lab-1;
    Posicio actual=candidats.back().actual();
    return actual.x==fi and actual.y==fi;
}
