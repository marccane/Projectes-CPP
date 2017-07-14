#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include "Solucio.h"
#include "Solucionador.h"

using namespace std;

/*int a2i(const char *s)
{
 int sign=1;
 if(*s == '-')
        sign = -1;
 s++;
 int num=0;
 while(*s)
  {
    num=((*s)-'0')+num*10;
    s++;
  }
 return num*sign;
}*/

void mostrar_ajuda(){
    cout<<"*** Obtencio de camins segurs entre dos nodes ***"<<endl
    <<"Utilitzacio: ./camisegur opcio fitxer"<<endl
    <<"on opcio pot ser:"<<endl
    <<"-h, --help : mostra aquest missatge d’ajuda i surt"<<endl
    <<"-u o d a len: cerca un camí entre o i d on tots els segments tenen"<<endl
    <<"    probabilitat d’atemptat <= a i longitud camí <= len"<<endl
    <<"-s o d len: cerca un camí entre o i d amb una longitud <=len"<<endl
    <<"que minimitzi la probabilitat de patir un atemptat."<<endl
    <<"-g o d: utilitza una estrategia vorac (greedy) per buscar"<<endl
    <<"        un cami entre o i d amb seguretat relativament alta."<<endl
    <<"fitxer ha de ser un fitxer de text en el format TGF descrit"<<endl;
}

int main(int argc, char** argv)
{
    /*char p=argv[1][1];
    if(argc<2){
        cout<<"Falten arguments (\"./camisegur --help\" per ajuda)"<<endl;
        return 1;
    }
    else if(p=='-' or argv[1][2]=='h'){
        mostrar_ajuda();
    }
    else if(p=='u'){
        if(argc<6){ //falten paràmetres
            string nomarxiu(argv[argc-1]);
            size_t trobat=nomarxiu.find('.');
            if(trobat!=string::npos)
                cout<<"Falten parametres"<<endl;
            else cout<<"Falta el nom del fitxer"<<endl;
        }
        else{
            int dist=atoi(argv[5]);
            float prob_atempt = atof(argv[4]);
            string nomarxiu(argv[6]), origen(argv[2]), desti(argv[3]);

            solucioReines sIni(8);
            solucionarUna algBack;
            bool teSolucio = algBack.solucionar(sIni);
            if (teSolucio) {
                solucioReines sol = algBack.obtenirSolucio();
                sol.mostrar(); // caldria fer el mètode
            } else cout << "L'algoritme no té solució" << endl;
        }
    }
    else if(p=='s'){

    }
    else if(p=='g'){

    }
    else{
        cout<<"Opcio desconeguda: "<<argv[1]<<endl;
        return 10;
    }
    */

    string nomarxiu, origen, desti;
    int max_dist;
    float max_atempt;
    cin>>nomarxiu>>max_dist>>max_atempt>>origen>>desti;

    char nomarxiunoconst[100];
    strcpy_s(nomarxiunoconst,nomarxiu.c_str());
    Solucio sIni(nomarxiunoconst,max_dist,max_atempt,origen,desti);
    Solucionador algBack;
    bool teSolucio = algBack.Solucionar(sIni);
    if (teSolucio) {
        //Solucio sol = algBack.obtenirSolucio();
        sIni.mostrar(); // caldria fer el mètode
    } else cout << "L'algoritme no té solució" << endl;
	
    return 0;
}
