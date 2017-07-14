#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H
#include "Solucio.h"
#include "Candidat.h"

class Solucionador
{
    public:
        Solucionador();
		//Solucio obtenirSolucio() const;
		void trobarUnaSolucio(Solucio &, const Posicio&);
		bool Solucionar(Solucio &inicial, Posicio pos_ini);
    private:
        void trobarTotes(Posicio);
        // inv: nSolucions=0
        int nSolucions;
        bool encertat;
        //Solucio sol; // pot ser una variable local
};

#endif // SOLUCIONADOR_H
