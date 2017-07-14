//Marc Cané Salamià
//u1939666
//Bingo permutatiu
#include "Contenidor.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef vector<int> triplet;

/** @pre - @post El triplet esta ordenat*/
void ordenar_triplet(triplet &t){
    for(int i=0;i<3;i++)
        for(int j=i;j<3;j++)
            if(t[i]>t[j])
                swap(t[i],t[j]);
}

/** @pre - @post El triplet es mostra per la sortida estandar*/
void mostrar_triplet(const triplet &t){
    cout<<t[0]<<" "<<t[1]<<" "<<t[2]<<endl;
}

/** @pre - @post El triplet s'ha desplacat una posicio enrera*/
void desplacar_actual(triplet &t){
    t[0]=t[1];
    t[1]=t[2];
}

/** @pre - @post El triplet f ha estat copiat a d*/
void copiar_triplet(triplet &d, const triplet &f){
    for(int i=0;i<3;i++)
        d[i]=f[i];
}

/** @pre - @post Retorna cert si els valors del triplet son diferent*/
bool valors_diferents(const triplet &t){
    return t[0]!=t[1] and t[1]!=t[2] and t[0]!=t[2];
}

/** @pre - @post El seguent numero del bingo ha estat llegit*/
void llegir_seguent(triplet &t){
    desplacar_actual(t);
    cin>>t[2];
}

int main()
{
    int seqlen=3;
    string id_actual;
    bool bingo=false, heminserit;
    triplet actual(3), copia(3);
    unordered_map<string,Contenidor> contenidors;
    unordered_map<string,Contenidor>::iterator it;

    cin>>actual[0]>>actual[1]>>actual[2];
    while(!bingo){
        if(valors_diferents(actual)){
            heminserit=false;
            copiar_triplet(copia,actual);
            ordenar_triplet(copia);
            id_actual=Contenidor::Crear_Identificador(copia);
            it=contenidors.find(id_actual);

            if(it==contenidors.end())
                contenidors[id_actual].Afegir(actual);
            else if(!it->second.Existeix(actual)){
                it->second.Afegir(actual);
                heminserit=true;
            }

            if(heminserit and it->second.Tamany()==6){
                bingo=true;
                cout<<"BINGO! "<<endl<<"Sequence length = "<<seqlen<<endl<<"Winning Sequence = ";
                mostrar_triplet(actual);
            }
            else llegir_seguent(actual);
        }
        else llegir_seguent(actual);
        seqlen++;
    }
    return 0;
}
