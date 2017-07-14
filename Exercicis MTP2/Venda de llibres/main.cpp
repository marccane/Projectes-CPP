#include <iostream>
#include "LlistaLlibres.h"
#include "Llibre.h"

using namespace std;

void Llegir_Setmana(LlistaLlibres &llista){
    Llibre entrada;
    entrada.Llegir();
    while(!entrada.Esfinal()){
        if(!llista.existeix(entrada)){
            llista.inserir(entrada);
        }
        else{
            llista.Actualitzar_Setmana_Llibres(entrada);
        }
        entrada.Llegir();
    }
}

int main()
{
    LlistaLlibres llista;
    char resposta='S';
    int setmana=1;
    while(resposta=='S'){
        cout<<"--- SETMANA "<<setmana<<" ---"<<endl;
        cout<<"ENTRA LES VENDES SETMANALS:"<<endl;
        Llegir_Setmana(llista);
        //cout<<"DEBUG:"<<llista.a_inici->dada.nom<<" "<<llista.a_inici->dada.autor<<" "<<llista.a_inici->dada.ventes_setmana[0]<<" "<<" "<<llista.a_inici->dada.ventes_setmana[1]<<" "<<llista.a_inici->dada.ventes_setmana[2]<<" "<<llista.a_inici->dada.ventes_setmana[3]<<endl;
        cout<<"LLISTAT ALFABETIC DE VENDES MENSUAL:"<<endl;
        if(setmana!=1)llista.Eliminar_novenuts();
        llista.llistar();
        cout<<endl<<"LLIBRE MES VENUT DEL MES:"<<endl;
        llista.Mostrar_mes_venuts();
        cout<<endl<<"VOLS INTRODUIR UNA NOVA SETMANA? (S/N)"<<endl;
        cin>>resposta;
        cin.ignore(100,'\n');
        llista.Actualitzar_llibres();
        setmana++;
    }
    return 0;
}

/*!
Programa principal:
Crear llista ordenada de llibres *******buida******
Llegir llistat vendes setmanals
Mostrar llistat alfabètic
Mostrar llibre/s més venut/s
Demanar si es vol introduir una nova setmana
mentre (resposta==‘S’) {
Actualitzar llibres per a una nova setmana
Llegir llistat vendes setmanals
Eliminar llibres no venuts
Mostrar llistat alfabètic
Mostrar llibre/s més venut/s
Demanar si es vol introduir una nova setmana
}
Dades:
Una llista ordenada de llibres
*/
