#include <iostream>
#include "Pacient.h"
#include "CuaPacients.h"

using namespace std;

void Mostrar_menu(){
    cout<<"OPCIONS:"<<endl<<
    "1: ENTRAR UN PACIENT"<<endl<<
    "2: SORTIR UN PACIENT"<<endl<<
    "3: MOSTRAR LLISTA D'ESPERA"<<endl<<
    "4: MOSTRAR NOMBRE DE PACIENTS EN ESPERA"<<endl<<
    "5: MOSTRAR RESUM DELS PACIENTS ATESOS"<<endl<<
    "9: MOSTRAR EL MENU D'OPCIONS"<<endl<<
    "0: SORTIR DEL PROGRAMA"<<endl;
}

int main()
{
    int opcio=1, espera;
    Pacient temp;
    CuaPacients cua;

    Mostrar_menu();
    while(opcio){
        cout<<"OPCIO:"<<endl;
        cin>>opcio;
        switch(opcio){
        case 1:
            cout<<"ENTRA EL PACIENT:"<<endl;
            temp.LlegirPacient();
            cua.encua(temp);
        break;
        case 2:
            //temp=cua.primer(); //pot ser aixo que el fa crashejar?
            if(cua.buida())cout<<"NO HI HA PACIENTS ESPERANT"<<endl;
            else{
                temp=cua.primer(); //era aixo
                temp.LlegirHoraSortida();
                cout<<"SURT PACIENT:"<<endl;
                temp.Mostrar();
                espera=temp.TempsEspera();
                cua.SumaTemps(espera);
                cout<<"TEMPS D'ESPERA: "<<espera<<" MINUTS"<<endl;
                cua.desencua();
            }
        break;
        case 3:
            cua.MostrarCua();
        break;
        case 4:
            cout<<"NOMBRE DE PACIENTS EN ESPERA:"<<endl<<cua.EnEspera()<<endl;
        break;
        case 5:
            cua.ResumPacients();
        break;
        case 9:
            Mostrar_menu();
        break;
        }
    }
    cout<<"FINAL DEL PROGRAMA"<<endl;
    return 0;
}
