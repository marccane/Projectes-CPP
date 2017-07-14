#include <iostream>

using namespace std;
/*
int altura_arbre(int numfills){
    int n, amax=0;
    while(numfills>0){
        cin>>n;
        if(n==0){if(amax==0)amax=1;}
        else{
            int temp=altura_arbre(n);
            if(temp>amax)amax=temp;
        }
        numfills--;
    }
    return amax+1;
}//Intent d'optimitzacio fallit */

int altura_arbre(int numfills){
    int n, amax=0;
    for(int i=0;i<numfills;i++){
        cin>>n;
        int temp=altura_arbre(n);
        if(temp>amax)amax=temp;
    }
    return amax+1;
}//Versió bona

/*
int altura_arbre(int numfills){
    int altura=1, n, amax=0;
    for(int i=0;i<numfills;i++){
        cin>>n;
        int temp=altura_arbre(n);
        if(temp>amax)amax=temp;
    }
    altura+=amax;
    return altura;
}//1a revisió */
/*
int altura_arbre(int numfills){
    int n, amax=0;
    for(int i=0;i<numfills;i++){
        cin>>n;
        if(altura_arbre(n)>amax)amax=altura_arbre(n);}
    return amax+1;
}//versió amb menys linies*/

int main()
{
    int arbres, fulles;
    cin>>arbres;
    for(int i=0;i<arbres;i++){
        cin>>fulles;
        cout<<altura_arbre(fulles)<<endl;
    }
    return 0;
}