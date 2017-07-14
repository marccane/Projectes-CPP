#include <iostream>
#include <cmath>

using namespace std;

int Extreure_digit(int numero, int posicio){
    int temp, temp2;
    temp=numero/pow((float)10,posicio-1);
    temp2=temp-((temp/10)*10);
    return temp2;
}

bool DigitCoincident(int a, int b, int posicio){
    if(Extreure_digit(a,posicio)==Extreure_digit(b,posicio))return true;
    else if(posicio==1)return false;
    else return(DigitCoincident(a,b,posicio-1));
}

int Comptar_digits(int n){
    int c=1;
    while(n>10){n/=10;c++;}
    return c;
}

int MenorNumDigits(int a, int b){
    int t1=Comptar_digits(a), t2=Comptar_digits(b);
    return (t1<t2?t1:t2);
}

int main()
{
    int e1, e2;
    cout<<"ENTRA DOS ENTERS:"<<endl;
    cin>>e1>>e2;
    cout<<(DigitCoincident(e1,e2,MenorNumDigits(e1,e2))?"TENEN UN":"NO TENEN CAP")<<" DIGIT COINCIDENT"<<endl;
    return 0;
}
