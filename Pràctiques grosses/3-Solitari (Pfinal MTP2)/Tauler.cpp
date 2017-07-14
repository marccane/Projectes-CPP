#include "Tauler.h"
#include "Baralla.h"
#include <iostream>

using namespace std;

Tauler::Tauler()
{
    a_n=7;
    a_mida=new int[a_n];
    a_mat=new Carta*[a_n];
    for(int i=0;i<a_n;i++){
        a_mat[i]=new Carta[13+i];
    }
}

Tauler::~Tauler(){
    for(int i=0;i<a_n;i++){
        delete []a_mat[i];
    }
    delete []a_mat;
    delete []a_mida;
}

void Tauler::repartir(Baralla bar){
    int comptador=51;
    for(int i=0;i<a_n;i++){
        for(int j=i;j<a_n;j++){
            a_mat[j][i]=bar.Get_Carta(comptador);
            comptador--;
            if(i==j){
                a_mat[i][j].Set_obrir(true);
                a_mida[i]=j+1;
            }
        }
    }
}

void Tauler::mostrar()const{
    int numfila=1, maxfiles=FilesMaximes();
    for(int i=0;i<maxfiles;i++){
        for(int j=0;j<a_n;j++){
            if(i<a_mida[j])a_mat[j][i].mostrar();//!Diria que és aixi
            else cout<<"   ";
        }
        cout<<'f'<<numfila<<endl;
        numfila++;
    }
}

void Tauler::Inserir_Carta_Tauler(Carta inserir, int col){
    a_mat[col-1][a_mida[col-1]]=inserir;//aqui no va un +1pk -1 + +1= 0
    a_mida[col-1]++;
}

Carta Tauler::Get_Carta_Tauler(int col, int fila)const{
    if(fila==-1)return a_mat[col-1][a_mida[col-1]-1];
    else return a_mat[col-1][fila-1];
}

int Tauler::FilesMaximes()const{
    int mesgran=0; //gros o gran?
    for(int i=0;i<a_n;i++){
        if(a_mida[i]>mesgran)mesgran=a_mida[i];
    }
    return mesgran;
}

int Tauler::Mida_Col(int col)const{
    return a_mida[col-1];
}

void Tauler::Treure_Carta(int col){
    a_mida[col-1]--;
}

void Tauler::Obrir_ultima(int col){
    if(!Get_Carta_Tauler(col).esoberta())
        a_mat[col-1][a_mida[col-1]-1].Set_obrir(true);
}
