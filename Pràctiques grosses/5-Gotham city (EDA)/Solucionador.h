//Marc Cané Salamià
//u1939666
//Practica Algoritmica
#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H
#include "Solucio.h"
#include "Candidat.h"

/** \brief  Conte les dades per determinar la millor solucio i per saber si aquesta s'ha trobat*/
class Solucionador
{
    public:
        Solucionador();
        /** @pre  cert
         @post retorna si ha trobat o no la Solucio (i la guarda si l’ha trobada)*/
		bool Solucionar(Solucio &inicial);
		/** @pre  cert
         @post retorna si ha trobat o no la millor Solucio*/
		bool SolucionarOptim(Solucio &actual);
		/** @pre cert
        @post retorna si ha trobat o no una solucio*/
        bool SolucionarVorac(Solucio &);
    private:
        /** @pre  no encertat ^ sol és parcial
         @post no encertat o encertat ^ sol és completa*/
        void trobarUnaSolucio(Solucio &);
        /** @pre @pre  no encertat ^ sol és parcial
         @post no encertat o encertat ^ sol és optima*/
        void trobarMillor(Solucio &actual);

        bool encertat;
        Solucio optima;
};

#endif // SOLUCIONADOR_H
