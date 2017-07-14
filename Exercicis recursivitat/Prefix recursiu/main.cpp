#include <iostream>

using namespace std;

bool i_prefix(string a, string b, int pos){
    bool resultat=false;
    pos--;
    if(pos==0)resultat=a[pos]==b[pos];
    else if(a[pos]==b[pos])resultat=i_prefix(a,b,pos);
    return resultat;
}

bool prefix(string a, string b){
    return i_prefix(a,b,a.length());
}

int main()
{
    string a,b="holamon";
    while(1){
        cin>>a;
        cout<<prefix(a,b)<< endl;
    }
    return 0;
}
//cout<<a[pos]<<"=="<<b[pos]<<" pos="<<pos<<endl;
