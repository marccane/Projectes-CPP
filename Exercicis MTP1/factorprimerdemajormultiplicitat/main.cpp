#include <iostream>

using namespace std;

int main(){
    int entrada,numaprovar=2, guardarentrada, numdemultiplicitats=0, numesrepetit=0, numesgrosdemultiplicitats=0;
    cout<<"ENTRA UN ENTER MAJOR O IGUAL A 2:"<<endl;
    cin>>guardarentrada;
    entrada=guardarentrada;
    while(entrada>1){
        if(entrada%numaprovar == 0){
            entrada/=numaprovar;
            numdemultiplicitats++;
            if(numesgrosdemultiplicitats<=numdemultiplicitats){
                    numesgrosdemultiplicitats=numdemultiplicitats;
                    numesrepetit=numaprovar;
            }
        }
        else{
           numdemultiplicitats=0;
           numaprovar++;
        }
    }
    cout<<"FACTOR PRIMER DE MAJOR MULTIPLICITAT: "<< numesrepetit <<endl;
    cout<<"MULTIPLICITAT: "<< numesgrosdemultiplicitats  <<endl;
    return 0;
}
