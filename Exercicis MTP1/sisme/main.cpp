#include <iostream>
#define filinea <<endl
#define escriu cout<<
#define escriure escriu //no passa dos cops oi??
using namespace std;

int main(){



    double a,b,c;
    cout<<"MAGNITUD ANTEPENULTIM SISME:" filinea ;
    cin>>a;
    escriu "MAGNITUD PENULTIM SISME:" filinea ;
    cin>>b;
    escriu "MAGNITUD DARRER SISME:" filinea ;
    cin>>c;

    if(a>=4 || b>=4 || c>=4){escriu "ALERTA VERMELLA" filinea ;
}

    else if(c>b and b>a and c>=3)
    escriu "ALERTA TARONJA" filinea ;

    else if(c>b and b>a and c<3 and a<3 and b<3)
        escriu "ALERTA GROGA" filinea ;
    else escriu "NO HI HA ALERTA" filinea ;

}


