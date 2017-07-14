#include <iostream>
#include <stdlib.h>

using namespace std;

void ordenar_superior (int taula[], const int pos, const int MIDA_NORMAL){
    int posbona=pos+1;
    for(int i=0; i<MIDA_NORMAL-pos-1; i++){
        taula[i]=taula[posbona];
        posbona++;
    }
}

int numdigits(int valor){
    int creativitat=1;
    if (valor<10)return 1;
    while(valor>=10){
        valor/=10;
        creativitat++;
        }
    return creativitat;
}

void fer_espais(int numespais){
    for(int i=0; i<numespais; i++){
        cout<<" ";
    }
}

void calcular(int valor, int numinputs, int superior[], int mitja[], int inferior[]){
    int pos1=numinputs-1;
	inferior[pos1]=superior[pos1]; //Queeee lleeeig canéee has pseudo-hardcodejat una variable! No em tornis a parlar més d'ara endavant
    mitja[pos1]=0;

	for(int i=numinputs-2; i>=0; i--){
        mitja[i]=valor*inferior[i+1];
        inferior[i]=superior[i]+mitja[i];
    }
}

int main()
{
    short unsigned const int MIDA_NORMAL=10+1, VALORS_MAX=50+2;
    int superior[MIDA_NORMAL], mitja[MIDA_NORMAL], inferior[MIDA_NORMAL],valors[VALORS_MAX];
    int pos, numinputs, numespais;
    const char o1=162, a1=133, e1=130, e2=138;
    string entradaescrita;

    cout<<"Rufinitzador: el teu solucionador massiu d'equacions rufinianes!"<<endl<<endl;
    cout<<"Entra els termes de l'equaci"<<o1<<" per ordre descendent. El coeficient m"<<a1<<"xim "<<e1<<"s "<<MIDA_NORMAL-1<<endl;
    cout<<"Has de pr"<<e2<<"mer 'Intro' per cada valor que entris, nom"<<e1<<"s un per fila."<<endl<<"Escriu 'stop' quan hagis acabat."<<endl;

    pos=MIDA_NORMAL-1;
    while(cin>>entradaescrita){
        if (entradaescrita=="stop" and pos<MIDA_NORMAL-2)break;
        if (pos<0)break;
        superior[pos]=atoi(entradaescrita.c_str());
        pos--;
    }
    numinputs=MIDA_NORMAL-pos-1;

    if(pos!=-1)ordenar_superior(superior, pos, MIDA_NORMAL);

    cout<<"Ok, ara entra els valors que vols provar, escriu 'stop' quan estiguis"<<endl;
    pos=0;
    while(cin>>entradaescrita){
        if (entradaescrita=="stop" and pos)break;
        if (pos>VALORS_MAX-3)break;
        valors[pos]=atoi(entradaescrita.c_str());
        pos++;
    }
    cout<<endl;

    for (int i=0; i<pos; i++){
        numespais=numdigits(valors[i]);
        if(valors[i]<0)numespais++;
        calcular(valors[i],numinputs,superior,mitja,inferior);
        fer_espais(numespais);
        cout<<"*";
        for(int j=numinputs-1; j>=0; j--){
            cout<<superior[j]<<" ";
        }
        cout<<endl<<valors[i]<<"*";
        //fer_espais() //fer els espais que ocupa el primer digit util de superior[]
        for(int j=numinputs-1; j>=0; j--){
            cout<<mitja[j]<<" ";
        }
        //for(int j=0; j<; j++){        } //TODO: implementar separacio dinamica
        cout<<endl;
        for(int j=0; j<20; j++)cout<<"*";
        cout<<endl;
        fer_espais(numespais);
        cout<<"*";
        for(int j=numinputs-1; j>=0; j--){
            cout<<inferior[j]<<" ";
        }
        cout<<endl<<endl;
    }

    cout<<"Prem 'Intro' per sortir";
    char symbol;
    cin.get(symbol);
    cin.get(symbol);

    return 0;
}
