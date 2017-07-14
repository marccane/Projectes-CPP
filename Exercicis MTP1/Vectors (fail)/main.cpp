#include <iostream>

using namespace std;

struct vector3dim
{
    double x,y,z;
} v1,v2,resultat;

vector3dim suma(vector3dim v1,vector3dim v2)
{
    vector3dim temp;
    temp.x=v1.x+v2.x;
    temp.y=v1.y+v2.y;
    temp.z=v1.z+v2.z;
    return temp;
}

vector3dim resta(vector3dim v1,vector3dim v2)
{
    vector3dim temp;
    temp.x=v1.x-v2.x;
    temp.y=v1.y-v2.y;
    temp.z=v1.z-v2.z;
    return temp;
}

vector3dim multiplicacio(vector3dim v1, double mult)
{
    vector3dim temp;
    temp.x=v1.x*mult;
    temp.y=v1.y*mult;
    temp.z=v1.z*mult;
    return temp;
}

vector3dim prodvect(vector3dim v1,vector3dim v2)
{
    vector3dim temp;
    temp.x=v1.y*v2.z-v1.z*v2.y;
    temp.y=v1.z*v2.x-v1.x*v2.z;
    temp.z=v1.x*v2.y-v1.y*v2.x;
    return temp;
}

int main()
{
    int hemisferinord=0,n;
    char operacio;
    bool comprovacio=0;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "ENTRAR COMPONENT X:" << endl;
    cin >> v1.x;
    cout << "ENTRAR COMPONENT Y:" << endl;
    cin >>v1.y;
    cout << "ENTRAR COMPONENT Z:" << endl;
    cin >>v1.z;
    for (int i=0; i<5 or operacio=='f'; i++)
    {


        cout << "ENTRAR OPERACIO (s, r, m, v, f):" << endl;
        cin >> operacio;
        n=i;
        if (operacio == 'f')break;

        if(operacio=='s')
        {
            cout << "ENTRAR COMPONENT X:" << endl;
            cin>>v2.x;
             cout << "ENTRAR COMPONENT Y:" << endl;
            cin>>v2.y;
            cout << "ENTRAR COMPONENT Z:" << endl;
            cin>>v2.z;
            resultat=suma(v1,v2);
        }
        if(operacio=='r')
        {
            cout << "ENTRAR COMPONENT X:" << endl;
            cin>>v2.x;
            cout << "ENTRAR COMPONENT Y:" << endl;
            cin>>v2.y;
            cout << "ENTRAR COMPONENT Z:" << endl;
            cin>>v2.z;
            resultat=resta(v1,v2);
        }
        if(operacio=='m')
        {
            double vreal;
            cout<<"ENTRAR UN VALOR REAL:"<<endl;
            cin>>vreal;
            resultat=multiplicacio(v1,vreal);
        }
        if(operacio=='v')
        {
            cout << "ENTRAR COMPONENT X:" << endl;
            cin>>v2.x;
            cout << "ENTRAR COMPONENT Y:" << endl;
            cin>>v2.y;
            cout << "ENTRAR COMPONENT Z:" << endl;
            cin>>v2.z;
            resultat=prodvect(v1,v2);
            n++;
        }
        cout << "RESULTAT: (" << resultat.x << ", " << resultat.y << ", " << resultat.z << ")" << endl;
        if(resultat.z>0)hemisferinord+=1;
        else
        {
            n+=1;
            comprovacio=true;
        }
            if (comprovacio)
            {
                cout << "NOMBRE D'OPERACIONS: " << n << endl;
                cout << "RESULTATS A L'HEMISFERI NORD: " << hemisferinord;
            }

        }

}

