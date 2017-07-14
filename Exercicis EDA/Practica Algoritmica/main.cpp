//Marc Cané Salamià
//u1939666
//Practica Algoritmica
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <chrono>
#include "Solucio.h"
#include "Solucionador.h"

using namespace std;

typedef chrono::high_resolution_clock Clock;

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

void evaluar_parametres(int argc, char** argv){
    string nomarxiu(argv[argc-1]);
    size_t trobat=nomarxiu.find('.');
    if(trobat!=string::npos) cout<<"Falten parametres"<<endl;
    else cout<<"Falta el nom del fitxer"<<endl;
}

int main(int argc, char** argv)
{
    int max_dist;
    bool teSolucio;
    float max_atempt;
    Solucionador algBack;
    Solucio sol;

    auto t1 = Clock::now();
    if(argc<2){
        cout<<"Falten arguments (\"./camisegur --help\" per ajuda)"<<endl;
        return 2;
    }
    char p=argv[1][1];

    if(p=='h' or p=='-'){
        mostrar_ajuda();
        return 3;
    }
    else if(p=='u'){
        if(argc<6){
            evaluar_parametres(argc,argv);
            return 4;
        }
        else{
            cout<<"Cerquem un cami amb probabilitat atemptat en un tram < que cert valor"<<endl
            <<"=========================================="<<endl;
            max_dist=atoi(argv[5]);
            max_atempt = atof(argv[4]);
            sol=Solucio(argv[6],max_dist,max_atempt,string(argv[2]),string(argv[3]));
            teSolucio = algBack.Solucionar(sol);
        }
    }
    else if(p=='s'){
        if(argc<5){
            evaluar_parametres(argc,argv);
            return 4;
        }
        else{
            cout<<"Cerquem un cami amb probabilitat atemptat global mes baixa"<<endl
            <<"=========================================="<<endl;
            max_dist=atoi(argv[4]);
            max_atempt=1;
            sol=Solucio(argv[5],max_dist,max_atempt,string(argv[2]),string(argv[3]));
            teSolucio = algBack.SolucionarOptim(sol);
        }
    }
    else if(p=='g'){
        if(argc<4){
            evaluar_parametres(argc,argv);
            return 4;
        }
        else{
            cout<<"Cerquem un cami amb un algoritme greedy..."<<endl
            <<"=========================================="<<endl;
            max_dist=0; max_atempt=1;
            sol=Solucio(argv[4],max_dist,max_atempt,string(argv[2]),string(argv[3]));
            teSolucio = algBack.SolucionarVorac(sol);
        }
    }
    else{
        cout<<"Opcio desconeguda: "<<argv[1]<<endl;
        return 5;
    }
    auto t2 = Clock::now();

    if (teSolucio)sol.mostrar();
    else cout << "El problema no te solucio" << endl;

    std::chrono::duration<double> time_span=std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    double segons = time_span.count();
    cout<<"Temps de calcul: "<<segons<<endl;

    return !teSolucio;
}
