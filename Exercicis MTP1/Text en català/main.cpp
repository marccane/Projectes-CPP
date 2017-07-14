#include <iostream>

using namespace std;

int main()
{
    int as=0, fs=0, totals=0;
    char caracter=0;
    do{
        cin>>caracter;
        if(caracter>='a' and caracter<='z'){
            totals++;
            switch(caracter){
            case 'a':
                as++;
                break;
            case 'f':
                fs++;
                break;
            }
        }
    }
    while(caracter!='.');
    int temp=as*100/totals, temp1=fs*100/totals;
    //cout<<as<<" "<<fs<<" "<<temp<<" "<<temp1<<" "<<totals<<endl;
    cout<<"ENTRA UN MISSATGE:"<<endl;
    if(temp>=10 and temp<=12 and temp1>=4 and temp1<=6)
        cout<<"TEXT ESCRIT EN CATALA."<<endl;
    else cout<<"TEXT NO ESCRIT EN CATALA."<<endl;
    return 0;
}

