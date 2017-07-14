#include <iostream>

using namespace std;

int euclides(int a, int b)
{
    int gros,petit,cocient,r,mcd;
    if(a>=b){
        gros=a;
        petit=b;
    }

    else{
        gros=b;
        petit=a;
    }

    do{ mcd=petit;
        cocient=gros/petit;
        r=gros-(petit*cocient);
        gros=petit;
        petit=r;
    }
    while(r!=0);

    return mcd;
}

int main()
{   int a,b,mcm;
    cout<<"INTRODUEIX VALOR 1:"<<endl;
    cin>>a;
    cout<<"INTRODUEIX VALOR 2:"<<endl;
    cin>>b;
    cout<<"MCM("<<a <<","<<b<<")="<<a*b/euclides(a,b)<<endl;
}
