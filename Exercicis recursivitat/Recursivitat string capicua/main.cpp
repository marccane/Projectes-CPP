#include <iostream>

using namespace std;

bool escapicua(string s, int pos){
    const int mida=s.length()-1;
    bool res=true;
    if(s[pos]!=s[mida-pos])res=false;
    else if(pos<mida/2)res=escapicua(s, pos+1);
    return res;
}

int main()
{
    string n;
    while(1){
        cin>>n;
        cout<<escapicua(n,0)<<endl;
    }
    return 0;
}
