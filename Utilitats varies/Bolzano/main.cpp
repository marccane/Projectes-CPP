#include <iostream>
#include <math.h>
#include <iomanip>

#define EsPositiuGeneral EspositiuVariable //Això era la manera més maca de fer-ho (o la menys lletja, depèn de com ho miris)

using namespace std;

bool EspositiuVariable(double x, double coef[]){
    return (
            x*x*x-x-1 //! Introdueix aqui la funció amb la sintaxi de C
            > 0);
}

bool EspositiuSin(double x, double coef[]){
    return (sin(x)+coef[0]*x+coef[1] > 0);
}

bool EspositiuCos(double x, double coef[]){
    return (x*x-cos(x)-2 > 0);
}

/*
void BuscarInterval(double a, double b, double c, double d, double &intervalalt, double &intervalbaix){
    while(!canvidesigne(intervalalt, intervalbaix)){ //buscar un canvi de signe (zero)
        intervalalt+=sumatori;
        intervalbaix-=sumatori;
        sumatori*=10;
    }
}
*/

string CorretgirString(string frase){ //Només arregla els accents de les lletres minúscules
    string *estil=&frase;
    const short unsigned ao=133, eo=138, et=130, it=161, oo=149, ot=162, u=163;
    const short cao=-32, ceo=-24, cet=-23, cit=-19, coo=-14, cot=-13, cu=-6;
    for(unsigned i=0; i<estil->length(); i++)
        switch(frase[i]){
        case cao:	frase[i]=ao;	break;
        case ceo:   frase[i]=eo;    break;
        case cet:   frase[i]=et;    break;
        case cit:   frase[i]=it;    break;
        case coo:   frase[i]=oo;    break;
        case cot:   frase[i]=ot;    break;
        case cu:    frase[i]=u;     break;
        }
    return frase;
}

void iteracionsmaximes(int &iteracions){
    const unsigned imaximes=100, inormals=20;
     if(iteracions>150){cout<<"Masses iteracions, reduit a "<<imaximes<<endl; iteracions=imaximes;}
     else if(iteracions<1){cout<<CorretgirString("Número d'iteracions invàlid. Es faràn ")<<inormals<<"iteracions"<<endl; iteracions=inormals;}
}

int calculariteracions(double alt, double baix, int var){
    double b=alt, a=baix, error=pow(10,-var);
    int resultat=log((b-a)/error)/log(2.0);
    resultat++;
    return resultat;
}

double Bolzano(int iteracions, double valornegatiu, double valorpositiu, bool print, double coef[]){
    double intervalmig=0xD;    bool espositiu;
    for(int i=0; i<=iteracions; i++){
        intervalmig=(valornegatiu+valorpositiu)/2;
        espositiu=EsPositiuGeneral (intervalmig, coef);
        if(print)cout<<i<<" Neg="<<valornegatiu<<" Pos="<<valorpositiu<<" Mig="<<intervalmig<<" f(mig)>0 ="<<espositiu<<endl<<endl;
        if(espositiu)valorpositiu=intervalmig;
        else valornegatiu=intervalmig;
    }
    return intervalmig;
}

//Aquest programa aproxima una funcióusnt el mètode de Bolzano/bisecció.
//És lleig i poc eficient pero es pot implementar amb poc codi i no falla mai, a diferència de Newton

int main(){
    double resultat, coeficients[2], intervalalt, intervalbaix;
    int iteracions, error, precissio; char decisio; bool escriure;

    cout<<CorretgirString("Aquest programa calcula zeros de funcions amb l'ineficient mètode de Bolzano")<<endl<<endl;
    cout<<"Interval Alt? ";
    cin>>intervalalt;
    cout<<"Interval Baix? ";
    cin>>intervalbaix;
    cout<<CorretgirString("Vols entrar el nombre d'iteracions o l'error màxim? (i/e): ");
    cin>>decisio;
    if(decisio=='i'){
        cout<<"Iteracions? (100 max): ";
        cin>>iteracions;
    }
    else{cout<<CorretgirString("Error màxim? (Error=10^-X) Entra només la X: ");
        cin>>error;
        iteracions=calculariteracions(intervalalt,intervalbaix,error);
    }
    iteracionsmaximes(iteracions);
    cout<<CorretgirString("Precissió? (15 max): ");
    cin>>precissio;
    cout<<"Vols que es mostri cada pas en pantalla? (s/n):";
    cin>>decisio;
    if(decisio=='s' or decisio=='y') escriure=true;
    else escriure=false;
    if(precissio>16)precissio=15; //està fet aposta, no és un bug
    cout<<setprecision(precissio);

    if(EsPositiuGeneral (intervalalt,coeficients) and !EsPositiuGeneral (intervalbaix,coeficients) )
        cout<<"Todo correcto? Y yo que me alegro"<<endl<<endl;
    else {cerr<<"Error: L'interval no conte cap arrel"<<endl; return 1;}
    //buscarinterval();
    resultat=Bolzano(iteracions,intervalbaix,intervalalt,escriure,coeficients);
    cout<<"Resultat="<<resultat<<endl;
}
