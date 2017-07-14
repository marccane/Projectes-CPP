#include <iostream>

using namespace std;

int main(){
    int entrada,tantpercent;
    cout<<"ENTRAR VALOR:"<<endl;
    cin>>entrada;
    cout<<"ENTRAR TANT PER CENT:"<<endl;
    cin>>tantpercent;
    cout<<"EL "<<tantpercent<<" PER CENT DE "<<entrada<<" ES ";
    cout.setf(ios::fixed);
    cout.precision(1);
	float resultat=(tantpercent*entrada)/100.0;
    cout<<resultat<<endl;
}
