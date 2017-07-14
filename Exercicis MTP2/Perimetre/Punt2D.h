#ifndef PUNT2D_H
#define PUNT2D_H
#include <iostream>
using namespace std;

class Punt2D {
// Descripci󺠵n punt al pla 2D
public:
// CONSTRUCTORS
  Punt2D(double x, double y);
  // Pre:--; Post: el punt 고(x,y)
  Punt2D();
  // Pre:--; Post: el punt 고(0,0)

// CONSULTORS
  double x() const;
  /* Pre: --; Post: retorna coordenada cartesiana x del punt */
   double y() const;
   /* Pre: --; Post: retorna coordenada cartesiana y del punt */
   double dist(Punt2D p) const;
   /* Pre: --; Post: retorna distᯣia entre el punt i p */
   void mostra() const;
   /* Pre: --; Post: mostra el punt en forma (x,y) */
   Punt2D puntMig(Punt2D p) const;
   // Pre:--; Post: retorna punt mig entre el punt i p
   bool EsIgual(Punt2D p) const;
   // Pre:--; Post: retorna cert si els dos punts són iguals

// MODIFICADORS
   void despl(double vx, double vy);
   /* Pre:--; Post: punt despla袴 amb vector (vx,vy) */
   void canviaPosicio(double x, double y);
   /* Pre:--; Post: el punt 고(x,y) */

// MɔODES DE CLASSE
   static double dist(Punt2D p, Punt2D q);
   // Pre: --; Post: retorna distᯣia entre p i q

//-------------------------------------------------------
private:
  double a_x;
  double a_y;
};

#endif // PUNT2D_H
