#include <iostream>
using namespace std;
int main(){
    int dies,hores,minuts,segons;
    cout<<"ENTRAR DIES:"<<endl;
    cin>>dies;
    cout<<"ENTRAR HORES:"<<endl;
    cin>>hores;
    cout<<"ENTRAR MINUTS:"<<endl;
    cin>>minuts;
    cout<<"ENTRAR SEGONS:"<<endl;
    cin>>segons;
    hores+=24*dies;
    minuts+=60*hores;
    segons+=60*minuts;
	cout<<"TOTAL SEGONS: "<<segons<<endl;
}
