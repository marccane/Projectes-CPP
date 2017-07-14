#include <iostream>
//#include <string.h> //memcpy()

using namespace std;

/*
bool iguals(int a*, int b*){
    bool res=true;
    for(int i=0;i<3;i++)
        if(a[i]!=b[i])res=false;
    return res;
}*/

/*bool esdescendent2(int a[]){
    bool res;
}*/

//Pre: el vector a ha d'estar ordenat creixentment
/*void permutar(int a[], int b){
    if(!esdescendent(a)){
        cout<<"Sintercanvia: "<<b<<" amb "<<b+1<<endl;
        swap(a[b],a[b+1]);
        mostrar_vector(a);
        permutar(a,(b==0?MAX:b-1));
    }
}*/

bool esdescendent(int a[]){ //hardcodejat i efisient
    return a[0]>a[1] and a[1]>a[2];
}

void mostrar_vector(int a[]){
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
}

//Pre: el vector a ha d'estar ordenat creixentment
void permutar(int a[], bool b){
    mostrar_vector(a);
    if(!esdescendent(a)){
        if(b)swap(a[0],a[2]);
        else swap(a[1],a[2]);
        permutar(a,!b);
    }
}

int main()
{
    //memcpy(b,a,3*sizeof(int));
    int a[]={1,2,3};
    permutar(a,0);
    return 0;
}
