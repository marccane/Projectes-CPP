#include <iostream>

using namespace std;

bool esvocal(char c){
    return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
}

int numvocals(string s, int pos){
    int res=0;
    if(esvocal(s[pos]))res++;
    if(pos!=0)res+=numvocals(s,pos-1);
    return res;
}

int main()
{
    string s="abcdefghij";
    cout<<numvocals(s,s.length())<<endl;
    while(1){
        cin>>s;
        cout<<numvocals(s,s.length())<<endl;
    }
    return 0;
}
