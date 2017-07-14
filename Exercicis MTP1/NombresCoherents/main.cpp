#include <iostream>
#include <math.h>

using namespace std;
/*
int numdigits(int a){
    int creativitat=1;
    while(a>9){
        a/=10;
        creativitat++;
    }
    return creativitat;
}

int SumaDigits(int a){
    int numdi=numdigits(a),temp1,temp2,suma=0;
    while(temp?¿?>9){

    }

    temp1=(a/(10^numdi-1));
    suma+=temp1;
    temp2=(a/(10^numdi-2))-temp1*10^1;

}
*/ //!NOPE

int SumaDigits(string a, int lenght){
    int suma=0;
    for(int i=0;i<lenght;i++){
        suma+=a[i]-'0';
    }
    return suma;
}

long int potencia(int a, int b){
    for(int i=0;i<b;i++){
        a*=a;
    }
    return a;
}//aquesta funcio es erronia, s'ha de repassar

int lestandardecesuname(string aixonohohauriadeferjo){
    int quinavergonya=0,cont=1;
    for(int i=0;i<aixonohohauriadeferjo.length();i++){
        quinavergonya+=(aixonohohauriadeferjo[i]-'0')*pow(10,aixonohohauriadeferjo.length()-cont);
        //cout<<aixonohohauriadeferjo[i]-'0'<<"f"<<aixonohohauriadeferjo.length()-cont<<"MLA";
        //cout<<"quinavergonya+="<<(aixonohohauriadeferjo[i]-'0')<<"*pow(10,"<<aixonohohauriadeferjo.length()<<"-"<<cont<<endl;
        cont++;
    }
    return quinavergonya;
}

int main()
{
    string entrada, *bau5=&entrada;
    cout<<"ENTREU UN NOMBRE:"<<endl;
    cin>>entrada;
    int entradaint=lestandardecesuname(entrada);
    int suma=SumaDigits(entrada, bau5->length());
    //cout<<entradaint<<" suma="<<suma<<endl;
    if(entradaint%suma==0)
    cout<<"ES COHERENT"<<endl;
    else cout<<"NO ES COHERENT"<<endl;
    return 0;
}

//! A RECORDAR: NO ES POT USAR CMATH S'HA DUSAR MATH.H A L'ACME
/*
int lestandardecesuname(string aixonohohauriadeferjo){
    int quinavergonya=0,cont=1,elsenyoracme,elsenyoracme2,elsenyoracme3;
    for(int i=0;i<aixonohohauriadeferjo.length();i++){
        elsenyoracme=aixonohohauriadeferjo.length()-cont;
        elsenyoracme2=aixonohohauriadeferjo[i]-'0';
        elsenyoracme3=potencia(10,elsenyoracme);
        quinavergonya+=elsenyoracme2*elsenyoracme3;
        //cout<<aixonohohauriadeferjo[i]-'0'<<"f"<<aixonohohauriadeferjo.length()-cont<<"MLA";
        //cout<<"quinavergonya+="<<(aixonohohauriadeferjo[i]-'0')<<"*pow(10,"<<aixonohohauriadeferjo.length()<<"-"<<cont<<endl;
        cont++;
    }
    return quinavergonya;
}
*/
