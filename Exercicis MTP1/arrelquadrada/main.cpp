#include <iostream>
#include <cmath>

using namespace std;

int main(){

    string x="ENTRA EL COEFICIENT DE X2:";
    string y="ENTRA EL COEFICIENT DE X:";
    string z= "ENTRA EL TERME INDEPENDENT:";
    string veritat="aquest exercici és una mica.. no se com dir-ho... una mica LLEIG!";
    float a , b , c;

    cout.setf(ios::fixed);
    cout.precision(1);

    cout<< x <<endl ;
    cin>>a;
    cout<< y <<endl ;
    cin>>b;
    cout<< z <<endl ;
    cin>>c;

    if (a==0)
    {
        if(b)
        {
            cout<< "x= "<< (-c)/b <<endl ;
            return 0;
       }
        if(a==0 and b==0 and c==0)        {
            cout<< "HI HA INFINITES SOLUCIONS" <<endl ;
            return 0;
        }
        else        {
            cout<< "NO HI HA SOLUCIO" <<endl ;
            return 0;
        }
    }



    float discriminant=sqrt(b*b-4*a*c);

    if (discriminant>0){
        cout<< "x1= "<< (-b+discriminant)/2*a <<endl ;
        cout<< "x2= "<< (-b-discriminant)/2*a <<endl ;
    }
    else if (discriminant==0){
        cout<< "x= "<<(-b)/(2*a) <<endl ;
    }
    else{
        cout<< "x1= " << (-b)/(2*a) << "+" << sqrt(-(b*b-4*a*c))/(2*a) <<"i"<<endl ;
        cout<< "x2= " << (-b)/(2*a) << "-" << sqrt(-(b*b-4*a*c))/(2*a) <<"i"<<endl ;
    }
}
