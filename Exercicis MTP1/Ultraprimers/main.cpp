#include <iostream>
#include <math.h>

using namespace std;

bool esprimer(int n){
    int d=2;
    bool esdivisible=(n%d==0);
    while(!esdivisible && (d*d)<n){
        d++;
        esdivisible=(n%d==0);
    }
    if(!esdivisible or n==2)
    return true;
    return false;
}

int SumaDigits(string a, int lenght){
    int suma=0;
    for(int i=0;i<lenght;i++){
        suma+=a[i]-'0';
    }
    return suma;
}

int lestandardecesuname(string aixonohohauriadeferjo){ //lstoi no funciona, pel que m'he vist obligat a fer aixo
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
    cout<<"ENTRA UN ENTER:"<<endl;
    cin>>entrada;
    int entradaint=lestandardecesuname(entrada);
    int suma=SumaDigits(entrada, bau5->length());
    if(esprimer(entradaint) && esprimer(suma) and entradaint!=1)
    cout<<"ES ULTRAPRIMER"<<endl;
    else cout<<"NO ES ULTRAPRIMER"<<endl;
    return 0;
}
