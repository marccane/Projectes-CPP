#include "Punt2D.h"
#include <cmath>

Punt2D::Punt2D() {
// Pre:--; Post: el punt és (0,0)
 a_x=0;
 a_y=0;
}

Punt2D::Punt2D(double x, double y) {
// Pre:--; Post: el punt és (x,y)
 a_x=x;
 a_y=y;
}

double Punt2D::x() const {
// Pre: --; Post: retorna coordenada x del punt
 return a_x;
}

double Punt2D::y() const {
// Pre: --; Post: retorna coordenada y del punt
 return a_y;
}

double Punt2D::dist(Punt2D p) const {
// Pre:--; Post: retorna distància entre el punt i p
 double difX= a_x-p.a_x;
 double difY= a_y-p.a_y;
 return sqrt(difX*difX+difY*difY);
}

void Punt2D::mostra() const {
//Pre:--; Post: mostra el punt en format (x,y)
 cout << "(" << a_x << "," << a_y << ")" << endl;
}

Punt2D Punt2D::puntMig(Punt2D p) const {
// Pre:--; Post: retorna punt mig entre el punt i p
 return Punt2D((a_x+p.a_x)/2, (a_y+p.a_y)/2);
}

bool Punt2D::EsIgual(Punt2D p) const {
// Pre:--; Post: retorna cert si els dos punts són iguals
return (a_x==p.a_x && a_y==p.a_y);
}

void Punt2D::despl(double x, double y) {
// Pre:--; Post: punt desplaçat amb vector (x,y)
a_x+= x;
a_y+= y;
}

void Punt2D::canviaPosicio(double x, double y) {
// Pre:--; Post: el punt és (x,y)
   a_x= x;
   a_y= y;
}

double Punt2D::dist(Punt2D p, Punt2D q) {  // metode de classe
// Pre:--; Post: retorna distància entre p i q
   return p.dist(q);  // o bé q.dist(p)
}

