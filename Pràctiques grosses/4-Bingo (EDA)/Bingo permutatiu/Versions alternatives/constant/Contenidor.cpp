//Marc Cané Salamià
//u1939666
//Bingo permutatiu
#include "Contenidor.h"
#include <sstream>
using namespace std;

Contenidor::Contenidor(){}

void Contenidor::Afegir(const triplet &t){
    _cont.push_back(t);
}

bool Contenidor::Existeix(const triplet &t){
    list<triplet>::iterator it=_cont.begin();
    while(it!=_cont.end()){
        triplet &tmp=(*it);
        if(tmp[0]==t[0] and tmp[1]==t[1] and tmp[2]==t[2])
            return true;
        it++;
    }
    return false;
}

string Contenidor::Crear_Identificador(const triplet &i){
    ostringstream t;
    char c='-';
    t<<i[0]<<c<<i[1]<<c<<i[2];
    return t.str();
}

int Contenidor::Tamany() const{
    return _cont.size();
}
