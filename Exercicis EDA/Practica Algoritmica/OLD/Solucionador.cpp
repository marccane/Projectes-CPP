#include "Solucionador.h"
#include <iostream>
#include "Solucio.h"
#define not !
using namespace std;

Solucionador::Solucionador(){
    encertat=false;
	nSolucions = 0;
}

void Solucionador::trobarUnaSolucio(Solucio &sol)
{
// pre: no encertat ^ sol és parcial
// pos: no encertat o encertat ^ sol és completa
    Candidat iCan(sol.Get_nvertex());
    while (not iCan.esFi() && not encertat)
    {
        if (sol.acceptable(iCan))
        {
            sol.anotar(iCan);
            if (not sol.completa())
            {
                trobarUnaSolucio(sol); // iCan.actual()??
                if (not encertat)
                    sol.desanotar(iCan);
            }
			else {
				nSolucions++;
				encertat = true;
			}
        }
        iCan.seguent();
    }
}

bool Solucionador::Solucionar(Solucio &inicial)
{
// pre: cert
// pos: retorna si ha trobat o no la Solucio (i la guarda si l’ha trobada)
    //sol = inicial;
    trobarUnaSolucio(inicial);
    return encertat;
}
