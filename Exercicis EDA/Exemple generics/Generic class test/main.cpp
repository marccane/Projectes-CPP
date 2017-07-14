#include <iostream>
#include "CuaEstatica.h"
//#include "CuaEstatica.cpp"

using namespace std;

int main()
{
    CuaEstatica <int> a;
    a.Encua(20);
    a.Encua(15);
    cout<<a.esBuida();
    cout << a.Primer() << endl;
    a.Desencua();
    cout << a.Primer() << endl;
    return 0;
}
