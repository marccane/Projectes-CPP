#ifndef PACIENT_H
#define PACIENT_H
#include "Hora.h"
#include <string>
using namespace std;

class Pacient
{
    public:
        Pacient();
        void LlegirPacient();
        void Mostrar() const;
        void LlegirHoraSortida();
        int TempsEspera() const;
        int GetCodi() const;
        string GetNom() const;
        void MostrarHoraArribada() const;
    private:
        int codi;
        Hora entrada, sortida;
        string nom;
};

#endif // PACIENT_H
