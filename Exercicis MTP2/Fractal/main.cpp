#include <iostream>
#include <cmath>

using namespace std;

const int TAMANY=1000;

void Netejar_fb(char fb[][TAMANY]){
    for(int i=0;i<TAMANY;i++)
        for(int j=0;j<TAMANY;j++)
            fb[i][j]=' ';
}

void Escriure_fb(int n, const char fb[][TAMANY]){
	int temp=pow(3,n);
    for(int i=0;i<temp;i++){
        for(int j=0;j<temp;j++)
            cout<<fb[j][i];
        cout<<endl;
    }
}

void Fractal(const int n, const int x, const int y, const int mida, const char c, char fb[][TAMANY]){
    if(n==0)fb[x][y]=c;
    else{
        int temp=mida/3;
        Fractal(n-1,x,y,temp,c,fb);
        Fractal(n-1,x+mida,y,temp,c,fb);
        Fractal(n-1,x+2*mida,y,temp,c,fb);
        Fractal(n-1,x,y+mida,temp,c,fb);
        Fractal(n-1,x+2*mida,y+mida,temp,c,fb);
        Fractal(n-1,x,y+2*mida,temp,c,fb);
        Fractal(n-1,x+mida,y+mida*2,temp,c,fb);
        Fractal(n-1,x+mida*2,y+mida*2,temp,c,fb);
    }
}

int main()
{
    char fb[TAMANY][TAMANY], entrada;
    int n;
    Netejar_fb(fb);
    cin>>n>>entrada;
    Fractal(n,0,0,pow(3,n-1),entrada,fb);
    Escriure_fb(n,fb);
    return 0;
}
