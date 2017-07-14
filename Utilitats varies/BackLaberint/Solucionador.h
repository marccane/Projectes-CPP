#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H
#include "Solucio.h"
#include "Candidat.h"

class Solucionador
{
    public:
        Solucionador();
		void trobarUnaSolucio(Solucio &, const Posicio&);
		bool Solucionar(Solucio &inicial, Posicio pos_ini);
    private:
        void trobarTotes(Posicio);
        int nSolucions;
        bool encertat;
};

#endif // SOLUCIONADOR_H
