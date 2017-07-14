#include "Posicio.h"

Posicio Posicio::operator+(const Posicio& suma){
    return Posicio(x+suma.x,y+suma.y);
}

bool Posicio::operator==(const Posicio& pos){
    return x==pos.x and y==pos.y;
}
