#ifndef Solucio_H
#define Solucio_H
#include "Candidat.h"
#include <vector>

using namespace std;

class Solucio
{
    public:
        Solucio();
        Candidat inicialitzarCandidats() const;
        bool acceptable(const Candidat &iCan) const;
        void anotar(const Candidat &iCan);
        void desanotar(const Candidat &iCan);
        bool completa() const;
        void mostrar() const;
    private:
        Solucio & operator=(const Solucio &o);
        void copia(const Solucio &o){};

        int niv, mida;
};

#endif // Solucio_H
