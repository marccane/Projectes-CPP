#include "Punt2D.h"
#include <iostream>

using namespace std;

int main()
{
     double x, y, perimetre=0;
     Punt2D p, q, Inicial;
     bool primera=true;

     cout << "Entra x: "; cin >> x;
     cout << "Entra y: "; cin >> y;
     Inicial = Punt2D(x,y);
     q=Inicial;

     do{
        if(!primera)q=p;
        else primera=false;
        cout << "Entra x: "; cin >> x;
        cout << "Entra y: "; cin >> y;
        p = Punt2D(x,y);
        perimetre+=p.dist(q);
     }while(!(p.EsIgual(Inicial)));

     cout << "El per"<<char(161)<<"metre "<<char(130)<<"s: "<<perimetre<<endl;
     return 0;
}
