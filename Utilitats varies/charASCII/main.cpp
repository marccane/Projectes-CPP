#include <iostream>

using namespace std;
#define firstvalue 20
int main()
{
    char a=firstvalue;
    int b=0;
    for (int z=firstvalue;z<255;z++){
    if(z!=10){cout <<z<<":"<<a;}
    if(z!=99){cout<<" ";}
    a++;
    if(z==99){cout<<endl;}
    if(z>=99){
            if(b==13){cout<<endl;b=0;}
            b++;}
    }
    //13 PL
    char symbol;
    cin.get(symbol);
}
