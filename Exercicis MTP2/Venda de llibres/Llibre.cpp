#include "Llibre.h"
#include <iostream>

using namespace std;

Llibre::Llibre()
{
    for(int i=0;i<4;i++)ventes_setmana[i]=0;
}

void Llibre::Llegir(){
    cout<<"NOM:"<<endl;
    getline(cin,nom);
    if(nom!="#"){
        cout<<"AUTOR:"<<endl;
        getline(cin,autor);
        cout<<"VENDES SETMANALS:"<<endl;
        cin>>ventes_setmana[0];
        cin.ignore(100,'\n');
    }
}
void Llibre::Mostrar(){
    cout<<nom<<", "<<autor<<": "<<Venuts_darrermes()<<endl; //??
}
int Llibre::Venuts_darrermes(){
     int total=0;
     for(int i=0;i<4;i++)total+=ventes_setmana[i]; //cuidao amb la condicio
     return total;
}
bool Llibre::Esfinal(){
    return nom=="#";
}
void Llibre::Actualitzar_setmana(){
    //for(int i=2;i!=0;i--)ventes_setmana[i+1]=ventes_setmana[i]; //no estci completament segur k estigui B
    ventes_setmana[3]=ventes_setmana[2];
    ventes_setmana[2]=ventes_setmana[1];
    ventes_setmana[1]=ventes_setmana[0];
    ventes_setmana[0]=0;
}

bool Llibre::operator==(Llibre b){
    return nom==b.nom;
}

bool Llibre::operator<(Llibre b){
    return nom<b.nom;
}

bool Llibre::operator<=(Llibre b){
    return nom<=b.nom;
}

int Llibre::Get_ventesultimasetmana() const{
    return ventes_setmana[0];
}

void Llibre::Actualitzar_Setmana_Llibre(Llibre a){
    ventes_setmana[0]=a.ventes_setmana[0];
}

void Llibre::Inserir(Llibre a){
    nom=a.nom;
    autor=a.autor;
    ventes_setmana[0]=a.ventes_setmana[0];
}
