//Marc Cané Salamià
//u1939666
//Bingo permutatiu
#include "Contenidor.h"
#include <sstream>
using namespace std;

Contenidor::Contenidor(const string &id, const triplet &inicial){
    _identificador=id;
    Afegir(inicial);
}

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
//if((it*)[0]==t[0] and (it*)[1]==t[1] and (it*)[2]==t[2])

string Contenidor::Crear_Identificador(const triplet &i){
    ostringstream t;
    char c='-';
    t<<i[0]<<c<<i[1]<<c<<i[2];
    return t.str();
}

string Contenidor::Get_identificador() const{
    return _identificador;
}

int Contenidor::Tamany() const{
    return _cont.size();
}
