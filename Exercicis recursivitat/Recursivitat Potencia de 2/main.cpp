#include <iostream>

using namespace std;

bool espotenciade2(int n, int pot){
    bool res=false;
    if(n==pot)res=true;
    else if(pot<n)res=espotenciade2(n,pot*2);
    return res;
}

int main()
{
    int n;
    while(1){
        cin>>n;
        cout<<espotenciade2(n,2)<<endl;
    }
    return 0;
}
