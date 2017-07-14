#include "Pacient.h"
#include <iostream>
using namespace std;

Pacient::Pacient()
{
    //ctor
}

void Pacient::Mostrar() const{
    cout<<"CODI: "<<codi<<endl;
    cout<<"NOM: "<<nom<<endl;
    cout<<"HORA ENTRADA: ";
    entrada.Mostrar();
}

void Pacient::LlegirPacient(){
    cout<<"CODI:"<<endl;
    cin>>codi;
    cout<<"NOM:"<<endl;
    cin.ignore(50,'\n');
    getline(cin, nom);
    cout<<"HORA ENTRADA:"<<endl;
    entrada.Llegir();
}

void Pacient::LlegirHoraSortida(){
    cout<<"HORA ACTUAL:"<<endl;
    sortida.Llegir();
}

int Pacient::TempsEspera() const{
    return entrada.MinutsDiferencia(sortida);
}

int Pacient::GetCodi() const{
    return codi;
}

string Pacient::GetNom() const{
    return nom;
}

void Pacient::MostrarHoraArribada() const{
    entrada.Mostrar();
}
