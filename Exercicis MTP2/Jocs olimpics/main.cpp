#include <iostream>
#include <string>

using namespace std;

const int MAX_INSCRIPCIONS=5000;

struct Atleta{
    string nom, pais, modalitat;
};

void Mostrar_Atletes(Atleta Atletes[], int inscrits){
    for(int i=0;i<inscrits;i++){
        cout<<Atletes[i].nom<<" - "<<Atletes[i].pais<<" - "<<Atletes[i].modalitat<<endl;
    }
}

int Buscar_Atleta(Atleta Atletes[], Atleta entrada, int inscrits){
    int resultat=-1;
    bool trobat=false;
    for(int i=0;i<inscrits and !trobat;i++){
        if(Atletes[i].nom==entrada.nom and Atletes[i].pais==entrada.pais and Atletes[i].modalitat==entrada.modalitat){
            trobat=true;
            resultat=i;
        }
    }
    return resultat;
}

void Intercanviar(Atleta &a, Atleta &b){
    Atleta temp=a;
    a=b;
    b=temp;
}

void Ordenar(Atleta Atletes[], int inscrits){//NPM
    for(int i=0;i<inscrits;i++){
        for(int j=inscrits-1;j>i;j--){
            if(Atletes[j].nom<Atletes[j-1].nom)
                Intercanviar(Atletes[j],Atletes[j-1]);
            else if(Atletes[j].nom==Atletes[j-1].nom){
                if(Atletes[j].pais<Atletes[j-1].pais)
                    Intercanviar(Atletes[j],Atletes[j-1]);
                else if(Atletes[j].pais==Atletes[j-1].pais){
                    if(Atletes[j].modalitat<Atletes[j-1].modalitat)
                        Intercanviar(Atletes[j],Atletes[j-1]);
                }
            }
        }
    }
}

void Ordenar2(Atleta Atletes[], int inscrits){//MNP
    for(int i=0;i<inscrits;i++){
        for(int j=inscrits-1;j>i;j--){
            if(Atletes[j].modalitat<Atletes[j-1].modalitat)
                Intercanviar(Atletes[j],Atletes[j-1]);
            else if(Atletes[j].modalitat==Atletes[j-1].modalitat){
                if(Atletes[j].nom<Atletes[j-1].nom)
                    Intercanviar(Atletes[j],Atletes[j-1]);
                else if(Atletes[j].nom==Atletes[j-1].nom){
                    if(Atletes[j].pais<Atletes[j-1].pais)
                        Intercanviar(Atletes[j],Atletes[j-1]);
                }
            }
        }
    }
}

void Ordenar3(Atleta Atletes[], int inscrits){//PNM
    for(int i=0;i<inscrits;i++){
        for(int j=inscrits-1;j>i;j--){
            if(Atletes[j].pais<Atletes[j-1].pais)
                Intercanviar(Atletes[j],Atletes[j-1]);
            else if(Atletes[j].pais==Atletes[j-1].pais){
                if(Atletes[j].nom<Atletes[j-1].nom)
                    Intercanviar(Atletes[j],Atletes[j-1]);
                else if(Atletes[j].nom==Atletes[j-1].nom){
                    if(Atletes[j].modalitat<Atletes[j-1].modalitat)
                        Intercanviar(Atletes[j],Atletes[j-1]);
                }
            }
        }
    }
}

void Inscriure_Atletes(Atleta Atletes[], int &inscrits){
    Atleta entrada;
    cout<<"ISCRIPCIONS ALS JOCS OLIMPICS 2012"<<endl;
    while(entrada.nom!="#"){
        cout<<"NOM: "<<endl;
        cin>>entrada.nom;
        if(entrada.nom!="#"){
            cout<<"NACIONALITAT I MODALITAT: "<<endl;
            cin>>entrada.pais>>entrada.modalitat;
            if(Buscar_Atleta(Atletes,entrada,inscrits)==-1){
                Atletes[inscrits]=entrada;
                inscrits++;
                cout<<"LA INSCRIPCIO S'HA FET CORRECTAMENT"<<endl;
            }
            else cout<<"INSCRIPCIO JA FETA ANTERIORMENT"<<endl;
            cout<<"ATLETES PARTICIPANTS:"<<endl;
            Ordenar(Atletes,inscrits);
            Mostrar_Atletes(Atletes,inscrits);
        }

    }
    cout<<"FINAL DEL PERIODE D'INSCRIPCCIONS ALS JOCS OLIMPICS 2012"<<endl;
    cout<<"ATLETES PARTICIPANTS:"<<endl;
    Ordenar(Atletes,inscrits);
    Mostrar_Atletes(Atletes,inscrits);
}

void Mostrar_Nom(Atleta Atletes[], int inscrits, string a){
    bool algun=false;
    for(int i=0;i<inscrits;i++)
            if(a==Atletes[i].nom){
                if(!algun)cout<<"ATLETES PARTICIPANTS:"<<endl;
                algun=true;
                cout<<Atletes[i].nom<<" - "<<Atletes[i].pais<<" - "<<Atletes[i].modalitat<<endl;
            }
    if(!algun)cout<<"NO S'HA TOBAT CAP INSCRIPCIO AMB AQUEST CAMP"<<endl;
}

void Mostrar_Pais(Atleta Atletes[], int inscrits, string a){
    bool algun=false;
    for(int i=0;i<inscrits;i++)
            if(a==Atletes[i].pais){
                if(!algun)cout<<"ATLETES PARTICIPANTS:"<<endl;
                algun=true;
                cout<<Atletes[i].nom<<" - "<<Atletes[i].pais<<" - "<<Atletes[i].modalitat<<endl;
            }
    if(!algun)cout<<"NO S'HA TOBAT CAP INSCRIPCIO AMB AQUEST CAMP"<<endl;
}

void Mostrar_Modalitat(Atleta Atletes[], int inscrits, string a){
    bool algun=false;
    for(int i=0;i<inscrits;i++)
            if(a==Atletes[i].modalitat){
                if(!algun)cout<<"ATLETES PARTICIPANTS:"<<endl;
                algun=true;
                cout<<Atletes[i].nom<<" - "<<Atletes[i].pais<<" - "<<Atletes[i].modalitat<<endl;
            }
    if(!algun)cout<<"NO S'HA TOBAT CAP INSCRIPCIO AMB AQUEST CAMP"<<endl;
}

void Solapar(Atleta Atletes[], int &inscrits, int pos){
    for(int i=pos;i<=inscrits;i++){
        Atletes[i]=Atletes[i+1];
    }
    inscrits--;
}

int main()
{
    Atleta Atletes[MAX_INSCRIPCIONS], temp;
    string a_buscar;
    int inscrits=0;
    char opcio='a',opcio2;
    Inscriure_Atletes(Atletes,inscrits);
    do{
        cout<<"(m) MOSTRAR"<<endl<<"(e) ESCOLLIR"<<endl<<"(d) DESINSCRIURE"<<endl<<"(s) SORTIR"<<endl;
        cin>>opcio;
        switch(opcio){
        case 'm':
            opcio2='a';
            while(opcio2!='n' and opcio2!='m' and opcio2!='p'){
                cout<<"(n) PER NOM"<<endl<<"(m) PER MODALITAT"<<endl<<"(p) PER PAIS"<<endl;
                cin>>opcio2;
                if(opcio2!='n' and opcio2!='m' and opcio2!='p')cout<<"OPCIO NO VALIDA"<<endl;
            }
            if(opcio2=='n'){
                Ordenar(Atletes,inscrits);
                cout<<"ATLETES PARTICIPANTS:"<<endl;
                Mostrar_Atletes(Atletes,inscrits);
            }
            else if(opcio2=='m'){
                Ordenar2(Atletes,inscrits);
                cout<<"ATLETES PARTICIPANTS:"<<endl;
                Mostrar_Atletes(Atletes,inscrits);
            }
            else if(opcio2=='p'){
                Ordenar3(Atletes,inscrits);
                cout<<"ATLETES PARTICIPANTS:"<<endl;
                Mostrar_Atletes(Atletes,inscrits);
            }
        break;
        case 'e':
            opcio2='a';
            Ordenar(Atletes,inscrits);
            while(opcio2!='n' and opcio2!='m' and opcio2!='p'){
                cout<<"(n) PER NOM"<<endl<<"(m) PER MODALITAT"<<endl<<"(p) PER PAIS"<<endl;
                cin>>opcio2;
                if(opcio2!='n' and opcio2!='m' and opcio2!='p')cout<<"OPCIO NO VALIDA"<<endl;
            }
            if(opcio2=='n'){
                cout<<"NOM A CERCAR:"<<endl;
                cin>>a_buscar;
                Mostrar_Nom(Atletes,inscrits,a_buscar);
            }
            else if(opcio2=='m'){
                cout<<"MODALITAT A CERCAR:"<<endl;
                cin>>a_buscar;
                Mostrar_Modalitat(Atletes,inscrits,a_buscar);
            }
            else if(opcio2=='p'){
                cout<<"PAIS A CERCAR:"<<endl;
                cin>>a_buscar;
                Mostrar_Pais(Atletes,inscrits,a_buscar);
            }
        break;
        case 'd':
            int postemp;
            cout<<"NOM: "<<endl<<"NACIONALITAT I MODALITAT: "<<endl;
            cin>>temp.nom>>temp.pais>>temp.modalitat;
            postemp=Buscar_Atleta(Atletes,temp,inscrits);
            if(postemp==-1)
                cout<<"L'ATLETA JA NO CONSTAVA A LA LLISTA"<<endl;
            else{
                Solapar(Atletes,inscrits,postemp);
                cout<<"L'ATLETA S'HA DESINSCRIT"<<endl;
            }
        break;
        case 's':
            cout<<"US ESPEREM EL 2016!"<<endl;
        break;
        default:
            cout<<"OPCIO NO VALIDA"<<endl;
        break;
        }
    }while(opcio!='s');

    return 0;
}
