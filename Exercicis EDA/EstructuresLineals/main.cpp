#include <iostream>
#include "cuaDinamica.h"

using namespace std;

int main()
{
    cuaDinamica q;
    int n;

    cin>>n;
    while(n!=0){
        if(n>0)q.Encua(n);
        else q.Desencua();
        if(q.Buida())cout<<"* ";
        else cout<<q.Primer()<<" ";
        //cout<<(q.Buida()?t:q.Primer())<<' ';
        cin>>n;
    }
    while(!q.Buida()){
        q.Desencua();
        if(q.Buida())cout<<"* ";
        else cout<<q.Primer()<<" ";
    }
    cout<<endl;
    return 0;
}
