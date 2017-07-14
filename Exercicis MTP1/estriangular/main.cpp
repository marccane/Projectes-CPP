#include <iostream>

using namespace std;

int main()
{
   int a, numero=0;
   cout<<"ENTREU UN ENTER MAJOR QUE ZERO:"<<endl;
   cin>>a;
   int iteracions=1;
   bool pertany=false;
   while (numero<=a){
        //cout<<numero<<" ";
        if(numero==a)pertany=true;
        numero+=iteracions;
        iteracions++;
   }

   if(pertany)cout<<a<<" ES TRIANGULAR"<<endl;
   else cout<<a<<" NO ES TRIANGULAR"<<endl;

    return 0;
}
