#include <iostream>

using namespace std;

void descomposicio(int n, int provar){
    if(n!=1){
        if(n%provar==0){
            cout<<provar<<" ";
            descomposicio(n/provar,provar);
        }
        else descomposicio(n,provar+1);
    }
}

int main()
{
    int n;
    while(1){
        cin>>n;
        descomposicio(n,2);
        cout<<endl;
    }
    return 0;
}
