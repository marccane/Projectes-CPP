#include <iostream>

using namespace std;

//Retorna cert si el caràcter passat és una lletra minuscula i fals en cas contrari
bool EsLletra(char caracter){
    return (caracter>='a' and caracter<='z');
}

//Programa que busca la paraula amb major valors alfabètic
//d'una sequència de caràcters entrada i en diu el seu valor i la seva primera lletra
int main(){
    char caracter, bigfirstchar, primeralletra;
    bool ultimeralletra=false;
    int sumatori=0, numdelletres=0;
    float majorvalor=0, temp;
    cout.setf(ios::fixed);
    cout.precision(2);
    do{
        cin.get(caracter);
        if(EsLletra(caracter)){
            if(!ultimeralletra){
                primeralletra=caracter;
            }
            sumatori+=caracter-'a'+1;
            numdelletres++;
            ultimeralletra=true;
        }
        else{
            if(ultimeralletra){ //ultimeralletra / sumatori / numdelletres
                temp=(float)sumatori/(float)numdelletres;
               // cout<<sumatori<<"/"<<numdelletres<<"="<<temp<<endl;
                if(temp>=majorvalor){
                    majorvalor=temp;
                    bigfirstchar=primeralletra;
                }
            }
            numdelletres=0;
            sumatori=0;
            ultimeralletra=false;
        }
      //  cout<<"he arribat al final del loop per el caracter ="<<caracter<<endl;
    }
    while(caracter!='#');
    cout<<"INTRODUEIX EL TEXT ACABAT EN '#' I PULSA <INTRO>:"<<endl;
    cout<<"PARAULA AMB MAJOR VALOR ALFABETIC TE PRIMERA LLETRA= "<<bigfirstchar<<endl;
    cout<<"EL SEU VALOR ALFABETIC ES "<<majorvalor<<endl;
}

