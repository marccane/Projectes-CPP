#include <iostream>
#include <sstream>

using namespace std;

bool escapicua(int num){
    string a;
    stringstream temp;
    temp << num;
    a = temp.str();
    int inversecount=a.length()-1;
    bool hoes=true;
        for(unsigned i=0;i<inversecount and hoes;i++){
            if(a[i]!=a[inversecount])hoes=false;
            inversecount--;
        }
    return hoes;
}

int main()
{
    int num1, num2;
    cout<<"ENTRAR NUMERO 1 :"<<endl;
    cin>>num1;
    cout<<"ENTRAR NUMERO 2 :"<<endl;
    cin>>num2;
    cout<<"CAPICUES ENTRE "<<num1<<" I "<<num2<<endl;
    for(int i=num1;i<=num2;i++){
        if(escapicua(i))cout<<i<<endl;
    }
    return 0;
}
