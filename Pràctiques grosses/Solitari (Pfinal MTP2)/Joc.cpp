#include <iostream>
#include "Joc.h"
#include "PilaCartes.h"
#include "Tauler.h"
#include "Carta.h"

using namespace std;

Joc::Joc(Baralla a)
{
    a_guanyada=false;
    a_tauler.repartir(a);
    emplenar_ma(a);
    mostrar();
    MostrarMenu();
}

void Joc::MostrarMenu()const{
    cout<<"MENU"<<endl<<
    "1. OBRIR UNA CARTA (O TORNAR A COMENCAR)"<<endl<<
    "2. POSAR UNA CARTA (MA->TAULER)"<<endl<<
    "3. POSAR UNA CARTA (MA->PILA)"<<endl<<
    "4. MOURE UNA CARTA (TAULER->TAULER)"<<endl<<
    "5. MOURE UNA CARTA (TAULER->PILA)"<<endl<<
    "6. RECUPERAR UNA CARTA (PILA->TAULER)"<<endl<<
    "9. MOSTRAR MENU"<<endl<<
    "0. ABANDONAR LA PARTIDA"<<endl;
}

void Joc::TriarOpcio(){
    cout<<"OPCIO: "<<endl;
    cin>>a_opcio;
}

void Joc::Mostrar_Cim_Pila(const PilaCartes &pila)const{
    if(pila.buida())cout<<"   ";
    else pila.cim().mostrar();
}

void Joc::mostrar(){
    cout<<"ESTAT DEL JOC"<<endl;
    for(int i=0;i<4;i++){
        Mostrar_Cim_Pila(a_pals[i]);
    }
    Mostrar_Cim_Pila(a_ma);
    Mostrar_Cim_Pila(a_descartades);
    cout<<endl;
    for(int i=1;i<=7;i++)cout<<"c"<<i<<" ";
    cout<<endl;
    a_tauler.mostrar();
    a_guanyada=Partida_Guanyada();
    cout<<(a_guanyada?"JOC ACABAT":"JOC EN CURS")<<endl;
}

void Joc::emplenar_ma(Baralla bar){
    for(int i=0;i<=23;i++)
        a_ma.empila(bar.Get_Carta(i));
}

void Joc::Jugar(){
    int fila, col, col_d, pila;
    Carta origen;
    while(a_opcio!=0 and !a_guanyada){
        TriarOpcio();
        switch(a_opcio){
        case 0: break;
        case 1:
            if(a_ma.buida() and !a_descartades.buida())
                a_descartades.Girar_Cartes(a_ma);
            else if(!a_ma.buida()){
                Carta temp=a_ma.cim();
                temp.Set_obrir(true);
                a_ma.desempila();
                a_descartades.empila(temp);
            }
            mostrar();
            break;
        case 2:
            if(!a_descartades.buida()){
                col=Demanar_columna();
                if(PosarAlTauler(a_descartades.cim(),col))
                    a_descartades.desempila();
                else cout<<"LA CARTA NO ES POT POSAR A LA COLUMNA "<<col<<endl;
            }
            else cout<<"NO HI HA CAP CARTA PER AGAFAR"<<endl;
            mostrar();
            break;
        case 3:
            if(!a_descartades.buida()){
                if(PosarALaPila(a_descartades.cim()))
                    a_descartades.desempila();
                else cout<<"NO ES POT APILAR LA CARTA"<<endl;
            }
            else cout<<"NO HI HA CAP CARTA PER AGAFAR"<<endl;
            mostrar();
            break;
        case 4:
            Demanar_origen(col,fila);
            if(col>0 and col<=7 and fila>0 and fila<=a_tauler.Mida_Col(col) and a_tauler.Get_Carta_Tauler(col,fila).esoberta()){
                cout<<"ENTRA LA COLUMNA DESTI:"<<endl;
                cin>>col_d;
                if(col_d>0 and col_d<=7){
                    origen=a_tauler.Get_Carta_Tauler(col,fila);
                    if(a_tauler.Get_Carta_Tauler(col_d).Casen(origen) or origen.EsRei() and a_tauler.Mida_Col(col_d)==0){
                        int limit=a_tauler.Mida_Col(col);
                        for(int i=fila;i<=limit;i++){
                            a_tauler.Inserir_Carta_Tauler(a_tauler.Get_Carta_Tauler(col,i),col_d);
                            a_tauler.Treure_Carta(col);
                        }
                        a_tauler.Obrir_ultima(col);
                    }
                    else cout<<"LA CARTA NO ES POT POSAR A LA COLUMNA "<<col_d<<endl;
                }
                else cout<<"LA CARTA NO ES POT POSAR A LA COLUMNA "<<col_d<<endl;
            }
            else cout<<"LA CARTA NO ES POT MOURE"<<endl;
            mostrar();
            break;
        case 5:
            cout<<"ENTRA LA COLUMNA ORIGEN:"<<endl;
            cin>>col;
            if(col>0 and col<=7 and a_tauler.Mida_Col(col)>0){
                if(PosarALaPila(a_tauler.Get_Carta_Tauler(col))){
                    a_tauler.Treure_Carta(col);
                    a_tauler.Obrir_ultima(col);
                }
                else cout<<"LA CARTA NO ES POT APILAR"<<endl;
            }
            else cout<<"LA CARTA NO ES POT APILAR"<<endl;
            mostrar();
            break;
        case 6:
            cout<<"ENTRA LA PILA:"<<endl;
            cin>>pila;
            pila--;
            if(!a_pals[pila].buida()){
                cout<<"A QUINA COLUMNA LA VOLS POSAR:"<<endl;
                cin>>col;
                if(a_tauler.Get_Carta_Tauler(col).Casen(a_pals[pila].cim())){
                    a_tauler.Inserir_Carta_Tauler(a_pals[pila].cim(),col);
                    a_pals[pila].desempila();
                }
                else cout<<"LA CARTA NO ES POT POSAR A LA COLUMNA "<<col<<endl;
            }
            else cout<<"A LA PILA NO HI HA CAP CARTA PER RECUPERAR"<<endl;
            mostrar();
            break;
        case 9: MostrarMenu(); break;
        default:
            cout<<"OPCIO NO DEFINIDA "<<a_opcio<<endl;
            MostrarMenu();
            mostrar();
            break;
        }
    }
    cout<<(a_guanyada?"PARTIDA GUANYADA":"PARTIDA ABANDONADA")<<endl;
}

int Joc::Demanar_columna()const{
    int col;
    cout<<"A QUINA COLUMNA LA VOLS POSAR:"<<endl;
    cin>>col;
    return col;
}

void Joc::Demanar_origen(int &col, int &fila)const{
    cout<<"ENTRA LA COLUMNA ORIGEN I LA FILA ORIGEN:"<<endl;
    cin>>col>>fila;
}

bool Joc::PosarAlTauler(Carta car, int col){
    bool HaSigutPossible=true;
    if(col<=7 and col>0){
        if(a_tauler.Get_Carta_Tauler(col).Casen(car) or a_tauler.Mida_Col(col)==0 and car.EsRei())
            a_tauler.Inserir_Carta_Tauler(car,col);
        else HaSigutPossible=false;
    }
    else HaSigutPossible=false;
    return HaSigutPossible;
}

bool Joc::Partida_Guanyada(){
    bool guanyada=true;
    for(int i=0;i<4;i++){
        if(!(a_pals[i].Pila_Completada() and guanyada))guanyada=false;
    }
    return guanyada;
}

bool Joc::PosarALaPila(Carta car){
    bool HaSigutPossible=false;
    const char pals[]={'P','c','d','T'};
    int index_pila;
    char temp=car.Get_Pal();
    for(int i=0;i<4;i++)if(temp==pals[i])index_pila=i;
    bool condicio1, condicio2=false;
    condicio1=a_pals[index_pila].buida() and car.EsA();
    if(!a_pals[index_pila].buida())condicio2=car.Casen(a_pals[index_pila].cim(),true);
    if(condicio1 or condicio2){
        a_pals[index_pila].empila(car);
        HaSigutPossible=true;
    }
    return HaSigutPossible;
}
