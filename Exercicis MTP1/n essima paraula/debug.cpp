#include <iostream>
#include <fstream>

using namespace std;

bool eslletra(char a){
    return (a>='a' and a<='z' or a>='A' and a<='Z' or a>='0' and a<='9');
}

//Aquedy programa localitza la n-essima paraula que comença amb un caràcter entrat
//per l'usuari i que té un nombre x de lletres, també entrades per l'usuari
int main()
{
    char lletra_entrada, actual, primeralletra;
    int paraules_entrada, llargada_entrada, contadorlletres=0, contadorparaules=0, contadorparaulesespecials=0;
    bool ultimeralletra=false, trobat=false;
    string nomarxiu;
    fstream fitxer;

    cin>>nomarxiu;

    cout<<"NOM DEL FITXER:"<<endl;
    fitxer.open( nomarxiu.c_str() , fstream::in);
    if ( not fitxer.is_open() ) {
    cout << "NO S'HA TROBAT EL FITXER" << endl;
    return 1;
    }

    cin>>lletra_entrada>>paraules_entrada>>llargada_entrada;
    //cin>>paraules_entrada;
    //cin>>llargada_entrada;
    //cin>>paraules_entrada>>llargada_entrada>>lletra_entrada;
    do{
        //cout<<actual;
        fitxer>>noskipws>>actual;
        if(eslletra(actual)){
            if(!ultimeralletra){
                primeralletra=actual;
                contadorparaules++;
            }
            contadorlletres++;
            ultimeralletra=true;
        }
        else{
            if(ultimeralletra and primeralletra==lletra_entrada and contadorlletres==llargada_entrada){
            //cout<<"Estic al 1, cnt par especials="<<contadorparaulesespecials<<"la ultima paraula tenia "<<contadorlletres<<" lletres"<<endl;
            contadorparaulesespecials++;
            if(contadorparaulesespecials==paraules_entrada)trobat=true;
            }
            contadorlletres=0;
            ultimeralletra=false;
        }
    }
    while(!fitxer.eof() and !trobat);
    cout<<"LLETRA INICIAL:"<<endl;
    cout<<"NUMERO PARAULES:"<<endl<<"LLARGADA PARAULA:"<<endl;
    //if(contadorparaulesespecials!=paraules_entrada)cout<<"very meni mal"<<endl;
    if(trobat)cout<<"LA PARAULA NUMERO "<<paraules_entrada<<" DE "<<llargada_entrada<<" LLETRES QUE COMENCA PER "<<lletra_entrada<<" ES LA PARAULA NUMERO "<<contadorparaules<<" DEL FITXER"<<endl;
    else cout<<"EL FITXER NO CONTE "<<paraules_entrada<<" PARAULES DE "<<llargada_entrada<<" LLETRES QUE COMENCIN PER "<<lletra_entrada<<endl;
    return 0;
}
