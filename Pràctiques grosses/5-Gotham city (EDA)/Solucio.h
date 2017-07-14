//Marc Cané Salamià
//u1939666
//Practica Algoritmica
#ifndef Solucio_H
#define Solucio_H
#include "Candidat.h"
#include "GrafVMap.h"
#include <vector>

using namespace std;

/** \brief  Conte informació necessaria per trobar solucions al problema*/
class Solucio
{
    public:
        Solucio();
        /** @pre  n>0
        @post Solucio preparada per resoldre un problema de mida*/
        Solucio(char* nomfitxer, int max_dist, float max_atemp, const string &p_origen, const string &p_desti);
        Candidat inicialitzarCandidats() const;
        /** @pre  cert
        @post retorna cert si el Candidat es pot afegir a la solució*/
        bool acceptable(const Candidat &iCan) const;
        /** @pre  iCan és acceptable
        @post afegeix iCan a la Solucio*/
        void anotar(const Candidat &iCan);
        /** @pre  iCan és el darrer Candidat anotat
        @post es treu iCan de la Solucio (darrer Candidat anotat)*/
        void desanotar(const Candidat &iCan);
        /** @pre  cert
        @post retorna cert si la solució ja és completa*/
        bool completa() const;
        /** @pre cert
        @post la solucio es mostra pel canal estandar*/
        void mostrar() const;
        /** @pre cert
        @post retorna el numero de vertex*/
        int Get_nvertex() const;
        /** @pre optima conté la solucio optima
        @post retorna cert si la solucio es millor que la optima*/
        bool esMillor(Solucio &optima) const;
        /** @pre cert
        @post L'estructura per usar el vorac ha estat inicialitzada*/
        void Inicialitzar_vorac();
        /** @pre cert
        @post iCan ha estat afegit a la solucio*/
        void Afegir_Candidat(Candidat iCan);
        /** @pre cert
        @post iCan conte l'aresta mes prometedora*/
        void Buscar_Prometedor(Candidat &iCan) const;

    private:
        void copia(const Solucio &o);

        vector<int> solucio;
        vector<bool> visitats;
        GrafVMap graf, vorac;
        int nvertex, maxdist, distact, origen, desti;
        float prob_at, max_prob;
};

#endif // Solucio_H
