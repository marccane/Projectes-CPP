#include <iostream>

using namespace std;

bool EsDivisible(int a, int b){
    return (a%b==0);
}

//! Retorna la suma dels divisors d'un enter sense incluirse a ell mateix
int SumaDivisors(int const numero){
    int numaprovar=2, suma=1;
    while(numaprovar<numero){
        if(EsDivisible(numero,numaprovar)){
            suma+=numaprovar;
        }
        numaprovar++;
    }
    return suma;
}

bool SonAmics(int a, int b){
    return (SumaDivisors(a)==b and SumaDivisors(b)==a);
}

int main(){ 
    int num1, num2=0, parellesamics=0;
    bool continuar=true, tocalu=true, primera=true;
    while(continuar){
        if(tocalu)cin>>num1;
        else cin>>num2;
        if(num1==-1 or num2==-1)continuar=false;
        else{
            tocalu=!tocalu;
            if(!primera)
                if(SonAmics(num1,num2))parellesamics++;
            primera=false;
        }
    }
    cout<<"DADES:"<<endl;
    cout<<"HEM TROBAT "<<parellesamics<<" PARELLES DE NOMBRES AMICS."<<endl;
    return 0;
}
