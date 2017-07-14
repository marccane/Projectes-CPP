#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string a;
    ofstream fitxer;
    fitxer.open("ascii.txt");
    if(!fitxer.is_open()){
        cerr<<"No s'ha trobat l'arxiu"<<endl;
        return 1;
    }
    cout<<"Entra frase"<<endl;
    cin>>noskipws>>a;
    for(int i=0;i<a.length();i++){
        fitxer<<(int)a[i]<<",";
    }
    fitxer.close();
    return 0;
}
