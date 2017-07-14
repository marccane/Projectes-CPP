#include <iostream>

using namespace std;

int main()
{
    int n=2,d,a, contador=0;
    cout<<"INTRODUEIX VALOR:"<<endl;
    cin>>a;
    cout<<"ELS "<<a<<" PRIMERS NOMBRES PRIMERS SON:"<<endl;
    while(contador<a){
        d=2;
        bool esdivisible=(n%d==0);
        while(!esdivisible && (d*d)<n)
        {
            d++;
            esdivisible=(n%d==0);
        }
        if(!esdivisible or n==2)
        {
            cout <<n <<endl;
            contador++;
        }
        n++;
    }

}
