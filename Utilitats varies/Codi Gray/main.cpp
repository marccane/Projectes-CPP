#include <iostream>
#include <math.h>

using namespace std;

void Gray(int m, int p, char mat[][1024]){
    if(m!=0){
        Gray(m-1,p/2,mat);
        for(int i=0;i<p/2;i++)
            mat[m-1][i]='0';
        for(int i=p/2;i<p;i++)
            mat[m-1][i]='1';
        int t=p/2-1;
        for(int i=p/2;i<p;i++){
            for(int j=0;j<m-1;j++)
                mat[j][i]=mat[j][t];
            t--;
        }
    }
}

int main()
{
    int m,o;
    cin>>m;

    o=pow(2,m);
    char mat[10][1024]; //estatic, m<=10
    //char mat[m][o]; //s'hauria de fer dinamic

    Gray(m,o,mat);

    for(int i=0;i<o;i++){
        for(int j=m-1;j>=0;j--)
            cout<<mat[j][i];
        cout<<endl;
    }

    return 0;
}
