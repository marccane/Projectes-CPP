#include <iostream>

using namespace std;

int main()
{
    int entrada,numaprovar=2,numdivisibles=0, guardarentrada;
    bool numactualsumat=false;
    cout<<"ENTRA UN ENTER MAJOR O IGUAL A 2:"<<endl;
    cin>>guardarentrada;
    entrada=guardarentrada;
    while(entrada>1)
    {
        if(entrada%numaprovar == 0)
        {   entrada/=numaprovar;
            if(!numactualsumat){numdivisibles++; numactualsumat=true;}
        }
        else
        {
            numactualsumat=false;
           numaprovar++;
        }
    }
    cout<<"NOMBRE DE FACTORS PRIMERS DIFERENTS DE "<<guardarentrada<<":"<<numdivisibles<<endl;
    return 0;
}
