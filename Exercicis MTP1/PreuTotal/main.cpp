#include <iostream>

using namespace std;

int main()
{
    float a,b;
    cout << "ENTRA L'IMPORT DE LA VENDA:"<<endl;
    cin>>a;
    cout<<"ENTRA EL TANT PER CENT DE DESCOMPTE A APLICAR:"<<endl;
    cin>>b;
    cout<<endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<"DESCOMPTE:"<<endl<<b*a/100<<endl;
    cout<<"IMPORT DE LA VENDA AMB DESCOMPTE:"<<endl<<a-(b*a/100);
    cout<<endl<<"IVA 21 PER CENT:"<<endl<<21*(a-(b*a/100))/100;
    cout<<endl<<"TOTAL:"<<endl<<a-(b*a/100)+21*(a-(b*a/100))/100<<endl;

    return 0;
}
