#include <iostream>

using namespace std;

int immersio_comptar(int ultima, int n, int p[]){
    //Post: Compta les multiples de n fins a ultima
    int compt;
    //cout<<n<<" "<<p[n+1]<<(p[n+1]%p[n]==0?" es divisible per ":" no es divisible per ")<<p[n]<<endl;
    if(n==ultima-1)compt=p[n+1]%p[n]==0;
    else{
        compt=immersio_comptar(ultima, n+1,p)+(p[n+1]%p[n]==0);
    }
    return compt;
}

int comptar_parelles(int enters, int p[], int zeros){
    int parelles=enters-1;
    return immersio_comptar(parelles,0,p)+zeros;
}

int main()
{
    int enters;
    cout<<"ENTRA EL NOMBRE D'ENTERS:"<<endl<<
    "ENTRA ELS ENTERS:"<<endl<<"NOMBRE DE PARELLES:";
    cin>>enters;
    int p[enters], zeros=0, casextrany=0;
    for(int i=0;i<enters;i++){
        cin>>p[i-zeros];
        if(p[i-zeros]==0){
            zeros++;
            if(i==0)casextrany=1;
        }
    }
    enters-=zeros;
    cout<<comptar_parelles(enters,p,zeros)-casextrany<<endl;
    return 0;
}
