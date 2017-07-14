#include <iostream>

using namespace std;

int ComptarXifres(int numero){
    int xifres=1;
    while(numero>9){
        numero/=10;
        xifres++;
    }
    return xifres;
}

int Potencia10(int potencia){
    int res=1;
    for(int i=0;i<potencia;i++){
        res*=10;
    }
    return res;
}

int SumaXifres(int numero){
    int suma=0,temporal, xifres=ComptarXifres(numero)-1, valordexifresantigues=0;
    while(xifres>=0){
        temporal=numero;
        temporal-=valordexifresantigues;
        temporal/=Potencia10(xifres);
        valordexifresantigues+=temporal*Potencia10(xifres);
        suma+=temporal;
        xifres--;
    }
    return suma;
}

bool Pcaisdx(int a, int b){ //Parella consecutiva amb igual suma de xifres
    return (SumaXifres(a)==SumaXifres(b));
}

int main(){
    int num1, num2=0, acabar=0;
    bool continuar=true, tocalu=true, primera=true, parellesconsecutives=false;
    while(continuar){
        if(tocalu)cin>>num1;
        else cin>>num2;
        if(num1==-1 or num2==-1)continuar=false;
        else{
            tocalu=!tocalu;
            if(!primera)
                if(Pcaisdx(num1,num2)){
                    parellesconsecutives=true;
                    continuar=false;
                }
            primera=false;
        }
    }
    if(parellesconsecutives)
        while(acabar!=-1)cin>>acabar;
    cout<<"DADES:"<<endl;
    if(parellesconsecutives){
        cout<<"LA SEQUENCIA CONTE UNA PARELLA CONSECUTIVA AMB IGUAL SUMA DE XIFRES:";
        if(tocalu)cout<<num1<<","<<num2<<endl;
            else cout<<num2<<","<<num1<<endl;
    }
    else cout<<"LA SEQUENCIA NO CONTE UNA PARELLA CONSECUTIVA AMB IGUAL SUMA DE XIFRES."<<endl;
    return 0;
}
