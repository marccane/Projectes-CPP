#include <iostream>
#include <cmath>

using namespace std;

int numdigits(int n){
    int digits=1;
    while(n>9){n/=10;digits++;}
    return digits;
}

int deuelevatn(int n){
    int res=1;
    while(n>0){res*=10;n--;}
    return res;
}

int capgirar(int n){
    int res;
    if(n<10)res=n;
    else{
        res=capgirar(n/10);
        res+=deuelevatn(numdigits(n)-1)*(n%10);
    }
    return res;
}

/*
int capgirar(int n){
    int res;
    if(n<10)res=n;
    else{
        res=capgirar(n/10);
        int temp=pow(10,numdigits(n)-1); //aixo no funciona, pow(10,2) retorna 99
        //cout<<temp<<" "<<pow(10,numdigits(n)-1)<<" "<<numdigits(n)<<" "<<numdigits(n)-1<<endl;
        res+=pow(10,numdigits(n)-1)*(n%10);
        cout<<temp<<" "<<pow(10,numdigits(n)-1)<<" "<<numdigits(n)<<" "<<numdigits(n)-1<<endl;
    }
    return res;
}*/

void girar(int n){
    if(n<10)cout<<n;
    else{
        cout<<n%10;
        girar(n/10);
    }
}

int main()
{
    int n;
    while(1){
        cin>>n;
        cout<<capgirar(n)<<endl;
    }
    return 0;
}
