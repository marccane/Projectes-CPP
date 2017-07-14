#include <iostream>

using namespace std;

int main()
{
    int a, fib=2, antic=2, antic2=1;
    cout<<"ENTRA UN ENTER NO NEGATIU:"<<endl;
    cin>>a;
    bool trobat=false;
    if(a==0 or a==1)trobat=true;
    for(int i=0; fib<=a and !trobat; i++){
        if(fib==a)trobat=true;
        else{
            fib=antic+antic2;
            antic2=antic;
            antic=fib;
        }
    }
    if(trobat)cout<<a<<" PERTANY A LA SERIE DE FIBONACCI"<<endl;
    else cout<<a<<" NO PERTANY A LA SERIE DE FIBONACCI"<<endl;
    return 0;
}
