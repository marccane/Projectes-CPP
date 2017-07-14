#include <iostream>
#include <cmath>

using namespace std;
/*! 4. (**) Feu	una	funció	que,	donat	un	enter	no	negatiu k	i	un	real	x,	calculi,	amb	un
cost	Θ(k), el	sumatori	1+x+x2+...+xk */

int sumatori(int k, double x){
    int res;
    if(k==0)res=1;
    else res=pow(x,k)+sumatori(k-1,x);
    return res;
}

int sumatori2(const int k, const double x, int actual, double xactual){
    int res=xactual;
    if(actual==k)res=xactual;
    else if(actual<k)res+=sumatori2(k,x,actual+1,xactual*x);
    return res;
}

int main()
{
    int k,x;
    while(1){
        cout<<"Entra k i x: ";
        cin>>k>>x;
        cout << sumatori(k,x) <<" sum2: "<<sumatori2(k,x,0,1)<< endl;
    }
    return 0;
}
