#include <iostream>
#include <vector>
using namespace std;

bool esdescendent(int a[]){ //hardcodejat i efisient
    return a[0]>a[1] and a[1]>a[2];
}

void mostrar_vector(int a[]){
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
}

void copiar_array(int a[], int b[][6], int c){
    for(int i=0;i<3;i++)b[i][c]=a[i];
}

void ordenar_permutacio(int p[]){
    for(int i=0;i<3;i++)
        for(int j=i;j<3;j++)
            if(p[i]>p[j])
                swap(p[i],p[j]);
}

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

void copiar_permutacio(vector<int> v, int t[], int p){
    for(int i=0;i<3;i++)t[i]=v[p+i];
}

void treure_perm_original(int p_o[], int p[][6]){
    int t;
    for(int i=0;i<6;i++)
        if(p_o[0]==p[0][i] and p_o[1]==p[1][i] and p_o[2]==p[2][i])t=i;
    if(t!=5)
        for(int i=0;i<3;i++)
            swap(p[i][t],p[i][5]);
}

bool valors_diferents(int a[]){
    return a[0]!=a[1] and a[1]!=a[2] and a[0]!=a[2];
}

int main()
{
    bool bingo=false;
    int comptador=0;
    int cin_int_temp=1, permutacions[3][6], perm_temp[3], perm_original[3];
    vector<int> cadena_s;
    while(!bingo){ //que va aqui?
        cin>>cin_int_temp;
        cadena_s.push_back(cin_int_temp);
        comptador++;
        copiar_permutacio(cadena_s,perm_original,comptador-3);
        if(comptador>=8 and valors_diferents(perm_original)){
            copiar_permutacio(cadena_s,perm_temp,comptador-3);
            permutar_it(perm_temp,permutacions);
            treure_perm_original(perm_original,permutacions);
            bool trobat=true;
            int actual, num_perm_trobades=0;
            for(int i=0;i<5 and trobat;i++){ //iterem per totes les permutacions
                actual=0;
                bool trobat2=false;
                while(!trobat2 and actual+2<cadena_s.size()){ //! +2 o +3?? //iterem per tota la cadena
                    //bool perm_entera=true;//una permutacio de les 5 ha estat trobada

                    /*for(int j=0;j<3 and perm_entera;j++) //iterem per comprovar si a la posicio actual de la cadena la permutacio actual coincideix
                        if(cadena_s[actual+j]!=permutacions[j][i])
                            perm_entera=false;*/
                    if(cadena_s[actual]==permutacions[0][i] and cadena_s[actual+1]==permutacions[1][i] and cadena_s[actual+2]==permutacions[2][i]){
                        //num_perm_trobades++;
                        trobat2=true;
                    }
                    //if(perm_entera)trobat=true;
                    actual++;
                }
                if(!trobat2)trobat=false;
                //if(trobat)num_perm_trobades++;
            }
            //if(num_perm_trobades==5)bingo=true;
            if(trobat){
                bingo=true;
                cout<<"BINGO a la posicio "<<comptador<<endl<<"La combinacio guanyadora es:";
                mostrar_vector(perm_original);
            }
        }
    }
    return 0;
}
