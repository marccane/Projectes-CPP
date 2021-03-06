#include <iostream>
#include <iomanip>
using namespace std;
    //project started at 31/10/14 - 22:40

    double elevar(float a, int b){//base, exponent
        double c=a;
        for (int i=1;i<b;i++){
            c=c*a;
        }//end for
        return c;
    }//end funct elevar

    long factorial(int a){//factorial fins al n=12
        long b;
        if (a==1){return 1;}
        else {b=a*factorial(a-1);}//recursivitat suiii
        return b;
    }//end funct factorial

    double sinus(float a){
        double b=a,elev,fact;
        int c=3;
        for (int i=0;i<3;i++){
            elev=elevar(a,c);
            fact=factorial(c);
            b=b-(elev/fact);
            c+=2;
            if (i!=3){
            elev=elevar(a,c);
            fact=factorial(c);
            b=b+(elev/fact);
            c+=2;
            }
        }//end for
        return b;
    }//end funct sinus

    int main(){
        const double pi=3.1415926535;
        int a; double b; bool c;
        while(1<2){
        cout<<"Tria una opcio: ";
        cout <<"1-Rad  2-Deg  3-Exit"<<endl;
        cout<<"Opcio: ";
        cin>>a;
        c=true;
        if (a==1){
                cout <<"Entra l'angle del qual vols ";
                cout<<"coneixer el sinus (Rad): ";
                cin>>b;
                while(c){
                        if (b>pi){b=b-pi;}
                        else {c=false;}
                }
                 cout<<"Sin "<<b<<" = "<<setprecision(10)<<sinus(b)<<endl;
        }//endif 1
        else if (a==2){
                cout <<"Entra l'angle del qual vols ";
                cout<<"coneixer el sinus (Deg): ";
                cin>>b;
                b=(b*pi)/180;
                while(c){
                        if (b>pi){b=b-pi;}
                        else {c=false;}
                }
                 cout<<"Sin "<<b<<" = "<<setprecision(10)<<sinus(b)<<endl;
        }//endif 2
        else if (a==3){return 1;}
        else if (a==102){}
        else {cout<<"Nope. Try again."<<endl;}
        }//end while loop
}//end main
