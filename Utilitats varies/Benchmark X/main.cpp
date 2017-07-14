#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>
using namespace std;
int main()
{
    int i,c=0,f;
    bool centdos=false;
    double a,b,average;
    unsigned const iteracions=1000*1000000;
	bool acme=true;
    while (acme)
    {
        int option;
        cout << "                              *MENU PRINCIPAL*" << endl;
        cout << "Escull una opcio:" << endl << "1) SQRT - Calculador d'arrels quadrades" << endl;
        cout << "2) Benchmark - Compara la potencia de coma flotant dels teus ordinadors!" << endl << "3) Quit - Tanca el programa" << endl;
        option =2;
        if (option == 1)
        {
            cout << "Entra el primer digit del qual es fara l'arrel quadrada: ";
            cin >> a;
            cout << "Entra num d'arrels que vols calcular: ";
            cin >> f;
            for (i = 0; i < f; i++)
            {
                cout << "L'arrel quadrada de " << a << " es: ";
                b = sqrt(a);
                cout << setprecision(45) << b << endl;
                a++;
            }
            cout << endl << endl;
        }
        else if (option == 2)
        {
            a = 4325;
            time_t t = time(0);
            double sumatorinutil=-9999;
            for (i = 0; i < iteracions; i++)
            {
                sumatorinutil+=sqrt(a);
                a++;

            }
            cout << "100%" << sumatorinutil<< endl;
            time_t s = time(0);
            s=s-t;
            cout << "El teu ordinador acaba de calcular "<<iteracions/1000000<<" milions d'arrels quadrades en " << s << " segons" << endl;
            if(s){average=iteracions/s;
			cout <<"El promig ha estat de "<< average <<" arrels quadrades per segon!"<<endl<<endl<<endl;
            }
			else cout<<"no sha pogut fer la mitjana"
			acme=false;
        }
        else if (option == 3)
        {
            return 0;
        }
        else if (option == 102)
        {
            if (centdos==false)
            {
                cout << endl<<endl;
                cout << "Nope! jajaja"<<endl<<endl<<endl;
                centdos=true;
            }
            else
            {
                cout <<endl<<endl<< "SELECCIO INVALIDA" << endl<<endl<<endl;
            }
        }
        else if (option == 201)
        {
            cout << "AMB LA COL·LABORACIO DE:" << endl<<endl;
            cout << "      _             _    ____   ___  _ " << endl;
            cout << "  ___| | __ _ _ __ | | _|___ \\ / _ \\/ |" << endl;
            cout << " / __| |/ _` | '_ \\| |/ / __) | | | | |" << endl;
            cout << "| (__| | (_| | | | |   < / __/| |_| | |" << endl;
            cout << " \\___|_|\\__,_|_| |_|_|\\_\\_____|\\___/|_|" << endl<<endl<<endl;
        }
        else
        {
            cout <<endl<<endl<< "SELECCIO INVALIDA" << endl<<endl<<endl;
        }
    }
}
