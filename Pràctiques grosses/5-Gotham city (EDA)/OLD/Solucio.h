#ifndef Solucio_H
#define Solucio_H
#include "Candidat.h"
#include "GrafVMap.h"
#include <vector>

using namespace std;

class Solucio
{
    public:
        //Solucio(char*, int max_dist, int);
        Solucio(char* nomfitxer, int max_dist, float max_atemp, const string &p_origen, const string &p_desti);
        Candidat inicialitzarCandidats() const;
        bool acceptable(const Candidat &iCan) const;
        void anotar(const Candidat &iCan);
        void desanotar(const Candidat &iCan);
        bool completa() const;
        void mostrar();
        int Get_nvertex() const;

    private:
        Solucio & operator=(const Solucio &o);
        void copia(const Solucio &o){};

        //vector<Candidat> candidats;
        vector<int> solucio;
        vector<bool> visitats;
        GrafVMap graf;
        int nvertex, maxdist, distact, niv, origen, desti;
        float prob_at, prob_anterior, max_prob;
};

#endif // Solucio_H
