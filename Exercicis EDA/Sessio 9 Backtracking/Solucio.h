#ifndef Solucio_H
#define Solucio_H
#include "Candidat.h"
#include <vector>

using namespace std;

class Solucio
{
    public:
        Solucio(char*);
        Candidat inicialitzarCandidats() const;
        bool acceptable(const Candidat &iCan) const;
        void anotar(const Candidat &iCan);
        void desanotar(const Candidat &iCan);
        bool completa() const;
        void mostrar() const;
    private:
        Solucio & operator=(const Solucio &o);
        void copia(const Solucio &o){};
        bool laberint[100][100], visitats[100][100];
        vector<Candidat> candidats;
        int niv, mida_lab;
};

#endif // Solucio_H
