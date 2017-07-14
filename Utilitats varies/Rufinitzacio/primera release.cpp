#include <iostream>
#include <stdlib.h>

using namespace std;

void ordenar_superior (int taula[], const int pos, int MIDA_NORMAL){
    int posbona=pos+1;
    for(int i=0; i<MIDA_NORMAL-pos-1; i++){
        taula[i]=taula[posbona];
        posbona++;
    }
    //cout<<MIDA_NORMAL-pos-1<<endl; //num de inputs que hem fet
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
    inferior[numinputs]=superior[numinputs]; //Queeee lleeeig canéee has pseudo-hardcodejat una variable! No em tornis a parlar més d'ara endavant
    //mitja[numinputs-1]=valor*inferior[numinputs];
    for(int i=numinputs-1; i>=0; i--){
        mitja[i]=valor*inferior[i+1];
        inferior[i]=superior[i]+mitja[i];
    }
}

int main()
{
    short unsigned const int MIDA_NORMAL=10+2, VALORS_MAX=50+2;
    int superior[MIDA_NORMAL], mitja[MIDA_NORMAL], inferior[MIDA_NORMAL],valors[VALORS_MAX];
    int entrada, pos, numinputs, numespais;
    string entradaescrita;

    cout<<"Entra els termes de la equacio per ordre descendent, admet coeficients de fins a "<<MIDA_NORMAL-1<<" escriu stop quan estiguis"<<endl;
    pos=MIDA_NORMAL-1;
    while(cin>>entradaescrita){
        if (entradaescrita=="stop" and pos<MIDA_NORMAL-2)break;
        if (pos<0)break;
        superior[pos]=atoi(entradaescrita.c_str());
        //cout<<superior[pos]<<endl;
        pos--;
    }
    //cout<<pos<<endl;
    numinputs=MIDA_NORMAL-pos-1;

    /*
    for(int i=0; i<MIDA_NORMAL; i++){
        cout<<"superior["<<i<<"]"<<" = "<<superior[i]<<endl;
    }
    */

    if(pos!=-1)ordenar_superior(superior, pos, MIDA_NORMAL);

    cout<<"Ok, ara entra els valors que vols provar, escriu stop quan estiguis"<<endl;
    pos=0;
    while(cin>>entradaescrita){
        if (entradaescrita=="stop" and pos)break;
        if (pos+1>VALORS_MAX-2)break;
        valors[pos]=atoi(entradaescrita.c_str());
        //cout<<valors[pos]<<" "<<endl;
        pos++;
    }

    /*
    for(int i=0; i<MIDA_NORMAL; i++){
        cout<<"superior["<<i<<"]"<<" = "<<superior[i]<<endl;
    }
    */

    for (int i=0; i<pos-1; i++){ //pos-1??
        numespais=numdigits(valors[i]);
        if(valors[i]<0)numespais++;
        calcular(valors[i],numinputs,superior,mitja,inferior);
        fer_espais(numespais);
        cout<<"*";
        for(int j=numinputs; j>=0; j--){
            cout<<superior[j]<<" ";
        }
        cout<<endl<<valors[i]<<"*";
        //fer_espais() //fer els espais que ocupa el primer digit util de superior[]
        cout<<"0 "; //temporal
        for(int j=numinputs-1; j>=0; j--){
            cout<<mitja[j]<<" ";
        }
        //for(int j=0; j<; j++){        } //TODO: implementar separacio dinamica
        cout<<endl;
        for(int j=0; j<20; j++)cout<<"*";
        cout<<endl;
        fer_espais(numespais);
        cout<<"*";
        for(int j=numinputs; j>=0; j--){
            cout<<inferior[j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
