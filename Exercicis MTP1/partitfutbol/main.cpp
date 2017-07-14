#include <iostream>
#define filinea <<endl
#define escriu cout<<
using namespace std;

int main()
{
    int a[4];
    cout << "PARTIT ANADA" << endl;
    escriu "EQUIP A:" filinea ;
    cin>>a[0];
    escriu "EQUIP B:" filinea ;
    cin>>a[1];
    escriu "PARTIT TORNADA" filinea ;
    escriu "EQUIP B:" filinea ;
    cin>>a[2];
    escriu "EQUIP A:" filinea ;
    cin>>a[3];

    if(a[0]+a[3]>a[1]+a[2]){
        escriu "ES CLASSIFICA EQUIP A" filinea;
    }
    else if (a[0]+a[3]<a[1]+a[2]) escriu "ES CLASSIFICA EQUIP B" filinea;

    else if(a[0]+a[3]==a[1]+a[2]){
        if(a[1]>a[3]){
                escriu "ES CLASSIFICA EQUIP B PER VALOR GOLS DE FORA" filinea ;
        }
        else if(a[1]<a[3]) escriu "ES CLASSIFICA EQUIP A PER VALOR GOLS DE FORA" filinea ;
        else escriu "CALDRA DESEMPATAR" filinea ;
    }

    return 0;
}
