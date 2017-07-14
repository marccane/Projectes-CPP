#include <iostream>

using namespace std;

int mult_rusa(int a, int b){
    int res=0;
    if(a==1)res=b;
    else{
        if(a&1)res+=b;
        res+=mult_rusa(a/2,b*2);
    }
    return res;
}

int main()
{
    int a, b;
    while(1){
        cin>>a>>b;
        cout<<mult_rusa(a,b)<<endl;
    }
    return 0;
}
