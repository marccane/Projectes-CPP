#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H
#include "Solucio.h"

class Solucionador
{
    public:
        Solucionador();
		//Solucio obtenirSolucio() const;
		void trobarUnaSolucio(Solucio &);
		bool Solucionar(Solucio &inicial);
		void trobarTotes(Solucio &sol);
    private:
        // inv: nSolucions=0
        int nSolucions;
        bool encertat;
        //Solucio sol; // pot ser una variable local
};

#endif // SOLUCIONADOR_H
