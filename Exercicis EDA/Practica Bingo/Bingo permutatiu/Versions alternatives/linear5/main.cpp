//Marc Cané Salamià
//u1939666
//Bingo permutatiu
#include <iostream>
#include <vector>
using namespace std;

/** @pre - @post Retorna true si el vector es descendent*/
bool esdescendent(int a[]){
    return a[0]>a[1] and a[1]>a[2];
}

/** @pre - @post El vector es mostra per la sortida estandar*/
void mostrar_vector(int a[]){
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
}

/** @pre 0<=c<6 @post La fila c de b ha estat copiada a l'array a*/
void copiar_array(int a[], int b[][6], int c){
    for(int i=0;i<3;i++)b[i][c]=a[i];
}

/** @pre - @post La permutacio està ordenada*/
void ordenar_permutacio(int p[]){
    for(int i=0;i<3;i++)
        for(int j=i;j<3;j++)
            if(p[i]>p[j])
                swap(p[i],p[j]);
}

/** @pre - @post L'array s conte les permutacions de a*/
void permutar_it(int a[], int s[][6]){
    int c=0;
    bool b=false;
    ordenar_permutacio(a);
    while(!esdescendent(a)){
        copiar_array(a,s,c++);
        if(b)swap(a[0],a[2]);
        else swap(a[1],a[2]);
        b=!b;
    }
    copiar_array(a,s,c);
}

/** @pre 0<p<v.size() @post La permutacio de la posicio p de v ha estat copiada a t*/
void copiar_permutacio(const vector<int> &v, int t[], int p){
    for(int i=0;i<3;i++)t[i]=v[p+i];
}

/** @pre - @post La permutacio p_o s'ha mogut a la fila 5*/
void treure_perm_original(int p_o[], int p[][6]){
    int t;
    for(int i=0;i<6;i++)
        if(p_o[0]==p[0][i] and p_o[1]==p[1][i] and p_o[2]==p[2][i])t=i;
    if(t!=5)
        for(int i=0;i<3;i++)
            swap(p[i][t],p[i][5]);
}

/** @pre - @post Retorna cert si els 3 ultims numeros son diferents*/
bool valors_diferents(const vector<int> &a){
    int i=a.size()-3;
    return a[i+0]!=a[i+1] and a[i+1]!=a[i+2] and a[i+0]!=a[i+2];
}

int main()
{
    bool bingo=false;
    int cin_int_temp=1, actual, permutacions[3][6], perm_temp[3], perm_original[3];
    vector<int> cadena_s;
    while(!bingo){
        cin>>cin_int_temp;
        cadena_s.push_back(cin_int_temp);
        if(cadena_s.size()>=8 and valors_diferents(cadena_s)){
            copiar_permutacio(cadena_s,perm_original,cadena_s.size()-3);
            copiar_permutacio(cadena_s,perm_temp,cadena_s.size()-3);
            permutar_it(perm_temp,permutacions);
            treure_perm_original(perm_original,permutacions);
            bool trobat=true;
            for(int i=0;i<5 and trobat;i++){
                actual=0;
                trobat=false;
                while(!trobat and actual+4<cadena_s.size()){
                    if(cadena_s[actual]==permutacions[0][i] and cadena_s[actual+1]==permutacions[1][i] and cadena_s[actual+2]==permutacions[2][i])
                        trobat=true;
                    actual++;
                }
            }
            if(trobat){
                bingo=true;
                cout<<"BINGO! "<<endl<<"Sequence length = "<<cadena_s.size()<<endl<<"Winning Sequence = ";
                mostrar_vector(perm_original);
            }
        }
    }
    return 0;
}
