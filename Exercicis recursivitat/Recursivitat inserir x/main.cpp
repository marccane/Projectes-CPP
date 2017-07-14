#include <iostream>

using namespace std;

int pos_inserir(int v[], int x, int esq, int dre){
    int mig=(esq+dre)/2, res=mig;
    if(esq>=dre and v[mig]<x)res++;
    else{
        if(x<v[mig])dre=mig-1;
        else esq=mig+1;
        res=pos_inserir(v,x,esq,dre);
    }
    return res;
}

int main()
{
    int v[]={2,3,5,8,12,36,38,50}, x, elements=(sizeof(v)/sizeof(*v));
    while(1){
        cin>>x;
        cout<<"va a la pos "<<pos_inserir(v,x,0,elements-1)<<endl;
    }
    return 0;
}
