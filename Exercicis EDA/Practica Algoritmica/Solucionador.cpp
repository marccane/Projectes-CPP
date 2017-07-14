//Marc Can� Salami�
//u1939666
//Practica Algoritmica
#include "Solucionador.h"
#include <iostream>
#include "Solucio.h"
using namespace std;

Solucionador::Solucionador() {
    encertat=false;
}

void Solucionador::trobarUnaSolucio(Solucio &sol) {
    Candidat iCan(sol.Get_nvertex());
    while (not iCan.esFi() && not encertat) {
        if (sol.acceptable(iCan)) {
            sol.anotar(iCan);
            if (not sol.completa()) {
                trobarUnaSolucio(sol);
                if (not encertat)
                    sol.desanotar(iCan);
            }
            else encertat = true;
        }
        iCan.seguent();
    }
}

void Solucionador::trobarMillor(Solucio &actual) {
    Candidat iCan(actual.Get_nvertex());
    while (!iCan.esFi()) {
        if (actual.acceptable(iCan)){
            actual.anotar(iCan);
            if (!actual.completa())
                trobarMillor(actual);
            else if (actual.esMillor(optima)){
                optima = actual;
                encertat=true;
            }
            actual.desanotar(iCan);
        }
        iCan.seguent();
    }
}

bool Solucionador::SolucionarVorac(Solucio &sol){
    Candidat iCan(sol.Get_nvertex());
    sol.Inicialitzar_vorac();

    while(!sol.completa() and iCan.esValid()){
        sol.Buscar_Prometedor(iCan);
        if(iCan.esValid())
            sol.Afegir_Candidat(iCan);
    }
    if(sol.completa())
        encertat=true;

    return encertat;
}

bool Solucionador::Solucionar(Solucio &inicial) {
    trobarUnaSolucio(inicial);
    return encertat;
}

bool Solucionador::SolucionarOptim(Solucio &inicial) {
    trobarMillor(inicial);
    inicial=optima;
    return encertat;
}
