#include <iostream>

using namespace std;

bool sufix(int a, int b){
    bool res;
    if(a<10)res=a%10==b%10;
    else if(a%10!=b%10)res=false;
    else res=sufix(a/10,b/10);
    //cout<<a%10<<" "<<b%10<<endl;
    return res;
}

int main()
{
    int a,b;
    while(1){
        cin>>a>>b;
        cout<<sufix(a,b)<<endl;
    }
    return 0;
}
