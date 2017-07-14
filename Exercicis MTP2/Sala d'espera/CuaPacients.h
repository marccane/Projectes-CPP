#ifndef CUAPACIENTS_H
#define CUAPACIENTS_H
#include <string>
#include "Pacient.h"
using namespace std;

class CuaPacients {
// Descripci�: una cua d�strings
    public:
         // CONSTRUCTORS I DESTRUCTOR ----------------------------------
         CuaPacients();
         // Pre: --; Post: cua buida
         CuaPacients(const CuaPacients& o); // const. de c�pia
         // Pre: --; Post: aquesta cua �s c�pia de la Cua o
         ~CuaPacients();
         // Pre: --; Post: mem�ria alliberada
         // CONSULTORS -------------------------------------------------
         bool buida() const;
         // Pre: -- ; Post: retorna cert si la cua �s buida; fals en c.c.
         Pacient primer() const;
         void ResumPacients();
         // Pre: cua no buida; Post: retorna c�pia del primer string de la cua
         void MostrarCua();
         int EnEspera();
         // MODIFICADORS -----------------------------------------------
         void encua(Pacient s);
         // Pre: --; Post: ha afegit s al final de la cua
         void desencua();
         // Pre: cua no buida; Post: ha eliminat el primer element de la cua
         void SumaTemps(int temps);
         // OPERADORS REDEFINITS --------------------------------------
         CuaPacients& operator=(const CuaPacients& o);
         // Pre: -- ; Post: aquesta cua �s c�pia de o
    private:
         struct Node{
         Pacient valor;
         Node* seg;
         };
         // ATRIBUTS
         Node* a_primer; // punter al primer de la cua
         Node* a_darrer; // punter al darrer de la cua
         int atesos, tempstotal;
         //M�todes
         void copia(const CuaPacients& o);
         void allibera();
};
 #endif // CUAPACIENTS_H
