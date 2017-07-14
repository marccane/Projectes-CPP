#include "Solucionador.h"
#include <iostream>
#include "Solucio.h"
using namespace std;

Solucionador::Solucionador(){
    encertat=false;
}

void Solucionador::trobarUnaSolucio(Solucio &sol, const Posicio &pos)
{
// pre: no encertat ^ sol és parcial
// pos: no encertat o encertat ^ sol és completa
    Candidat iCan(pos);
    while (not iCan.esFi() && not encertat)
    {
        if (sol.acceptable(iCan))
        {
            sol.anotar(iCan);
            if (not sol.completa())
            {
                trobarUnaSolucio(sol, iCan.actual());
                if (not encertat)
                    sol.desanotar(iCan);
            }
            else
                encertat = true;
        }
        iCan.seguent();
    }
}

bool Solucionador::Solucionar(Solucio &inicial, Posicio pos_ini)
{
// pre: cert
// pos: retorna si ha trobat o no la Solucio (i la guarda si l’ha trobada)
    //sol = inicial;
    trobarUnaSolucio(inicial,pos_ini);
    return encertat;
}
