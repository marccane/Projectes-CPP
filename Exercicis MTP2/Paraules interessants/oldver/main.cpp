#include <iostream>
#include <fstream>
#include "Paraula.h"

using namespace std;

bool esrepetit(string temp, int &pos_repetit, int limit, Paraula mots_int_sortida[]){
    bool trobat=false;
    int i=0;
    while(i<=limit and !trobat){ //<=???
        if(temp==mots_int_sortida[i].GetParaula())
            trobat=true;
        i++;
    }
    i--; //si oi??
    pos_repetit=i;
    return trobat;
}

bool eslletra(char lletra){
    return (lletra<='Z' and lletra>='A' or lletra<='z' and lletra>='a');
}

string Llegir_paraules(fstream &fitxer){
    char lletra='0';
    string par;
    if(!eslletra(lletra))
        fitxer.get(lletra);
    while(eslletra(lletra)){
        par+=lletra;
        fitxer.get(lletra);
    }
    return par;
}

//void Ordenar

int main()
{
    string nomfixter="fitxerProva.txt", mots_interes_entrada[20], temp;
    fstream fitxer;
    cout<<"MOTS D'INTERES SEPARATS PER ESPAIS I ACABANT AMB #:"<<endl;
    int pos=0, num_interessants=0, pos_repetit, num_mots_interes_entrada;
    {   string entrada;
        do{
            cin>>entrada;
            mots_interes_entrada[pos]=entrada;
            pos++;
        }while(entrada!="#");
    }
    num_mots_interes_entrada=pos-1;
    Paraula entrada, mots_int_sortida[7500];
    if(pos==0)cout<<"NO HI HA PARAULES A CERCAR"<<endl;
    else{
        cout<<"INTRODUEIX EL NOM DEL FITXER A PROCESSAR:"<<endl;
        //cin>>nomfixter;
        fitxer.open(nomfixter.c_str());
        if(!fitxer.is_open())cout<<"NO S'HA POGUT OBRIR EL FITXER"<<endl;
        else{
            cout<<"PROCESSANT EL FITXER "<<nomfixter<<endl;
            pos=0;
            while(!fitxer.eof()){
                cout<<"TOY AL 1"<<endl;
                //fitxer>>temp;
                temp=Llegir_paraules(fitxer);
                entrada.Modificar(temp);
                entrada.Mostrar();
                if(entrada.esdinteres(mots_interes_entrada,num_mots_interes_entrada)){
                    cout<<"TOY AL 2"<<endl;
                    if(esrepetit(entrada.GetParaula(),pos_repetit,pos,mots_int_sortida)){
                        cout<<"TOY AL 3"<<endl;
                        mots_int_sortida[pos_repetit].incrementar_comptador();
                    }
                    else{
                        cout<<"TOY AL 4"<<endl;
                         mots_int_sortida[pos]=entrada;  //.modificar(temp)?
                         pos++;
                    }
                }
            }
            cout<<"LES PARAULES D'INTERES TROBADES A "<<nomfixter<<" SON:"<<endl;
            //ordenar
            for(int i=0;i<pos;i++){
                mots_int_sortida[i].Mostrar();
            }
            cout<<"TOTAL "<<pos<<" PARAULES"<<endl;
        }
    }
    return 0;
}
