#include "Data.h"
#include <iostream>
using namespace std;
//CONSTRUCTORS
Data::Data(){
//Pre: --
//Post: es la data xx/xx/xxxx
    dia=0;
    mes=0;
    any=3000;
    esigual=false;
}
//CONSULTORS
void Data::mostrar() const{
// Pre: --
// Post: mostra la data actual en format dia/mes/any
    cout<<dia<<"/"<<mes<<"/"<<any;
}

bool Data::esMesAntiga(Data d){
// Pre:--
// Post: cert si d és una data posterior a l’actual.
    bool mesantic=false;
    if(any<d.any)
        mesantic=true;
    else if(any==d.any){
        if(mes<d.mes)
            mesantic=true;
        else if(mes==d.mes){
            if(dia<d.dia)
                mesantic=true;
            else if(dia==d.dia)
                esigual=true;
        }
    }
    return mesantic;
}
//MODIFICADORS
/*
void Data::llegir(){
// Pre: --
// Post: llegeix dates dia/mes/any fins a llegir-ne una de vàlida.
    int tempany, tempmes, tempdia;
    bool primercop=true;
    do{
        if(!primercop){
            cout<<"ENTRA UNA DATA VALIDA: "<<endl;
            primercop=false;
        }
        cin>>tempdia>>tempmes>>tempany;
    }while(!esDataValida(tempdia,tempmes,tempany));
    dia=tempdia;
    mes=tempmes;
    any=tempany;
}
*/
void Data::llegir(int tonteria){
// Pre: --
// Post: llegeix dates dia/mes/any fins a llegir-ne una de vàlida.
    string a;
    if(tonteria==0)a="INTRODUEIX DATA D'INTERES: ";
    else a="DATA: ";
    cin>>dia>>mes>>any;
    while(!esDataValida(dia,mes,any)){
        cout<<a<<endl;
        cin>>dia>>mes>>any;
    }
}
// FUNCIONS DE CLASSE
bool Data::esDataValida(int dia, int mes, int any){
//Pre: --
//Post: cert si dia/mes/any seria una data vàlida, fals altrament
    bool correcte= true;
    bool traspas = (any%4==0) and (any%100!=0 or any%400==0);
    if((any>3399 or any<1600 or mes>12 or mes < 1 or dia<1 or dia>31))
    correcte =false;
    else if((mes==4 or mes==6 or mes==9 or mes==11) and (dia>30)) correcte=false;
    else if(traspas and mes==2 and dia>29)
    correcte =false;
    else if(not traspas and mes==2 and dia>28)
    correcte = false;
    return correcte;
}
