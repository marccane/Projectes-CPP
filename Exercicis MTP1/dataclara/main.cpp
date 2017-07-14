#include <iostream>

using namespace std;

int main()
{   int data,dia,mes,any;
    bool anycorrecte=true;
    bool anydetraspas=false;
    cout << "INTRODUEIX LA DATA:" << endl;
    cin>>data;
    dia=data/1000000;
    data=data-dia*1000000;
    mes=data/10000;
    any=data-=mes*10000;

    if (any%4==0){
            anydetraspas=true;
        if (any%100==0){
            if (any%400!=0){
              anydetraspas=false;
            }
        }
        else{anydetraspas=true;}
    }
    else {
    anydetraspas=false;
}
    if (any<1600 or any>3399){
        anycorrecte=false;

    }
    else if(mes<1 or mes>12){
       anycorrecte=false;
    }

    if(mes==1 and dia >31) anycorrecte=false;
    if(mes==2){
            if (anydetraspas and dia>29){
                    anycorrecte=false;
            }
            else if (!anydetraspas and dia >28){

                anycorrecte=false;
            }
    }
    if(mes==3 and dia >31) anycorrecte=false;
    if(mes==4 and dia >30) anycorrecte=false;
    if(mes==5 and dia >31) anycorrecte=false;
    if(mes==6 and dia >30) anycorrecte=false;
    if(mes==7 and dia >31) anycorrecte=false;
    if(mes==8 and dia >31) anycorrecte=false;
    if(mes==9 and dia >30) anycorrecte=false;
    if(mes==10 and dia >31) anycorrecte=false;
    if(mes==11 and dia >30) anycorrecte=false;
    if(mes==12 and dia >31) anycorrecte=false;

    if (anycorrecte){

       cout <<"LA DATA ES CORRECTA"<<endl;
    }

     else {

        cout <<"LA DATA ES INCORRECTA"<<endl;

     }


    return 0;

}
