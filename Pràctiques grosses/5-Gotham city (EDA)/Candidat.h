//Marc Cané Salamià
//u1939666
//Practica Algoritmica
#ifndef CANDIDAT_H
#define CANDIDAT_H

const int invalid=-1;

/** \brief  Conte les possibles solucions parcials d'un problema*/
class Candidat
{
    public:
        /** @pre  vert>0
        @post s’ha inicialitzat el candidat*/
        Candidat(int vert, int i=1);
        /** @pre  cert (error: no hi ha candidat)
        @post retorna el Candidat actual*/
        int actual() const;
        /** @pre cert
        @post retorna cert si ja no queden candidats*/
        bool esFi() const;
        /** @pre cert (error: no hi ha candidat)
        @post passa al següent candidat*/
        void seguent();
        /** @pre cert
        @post retorna cert si el candidat es valid*/
        bool esValid()const;
    private:
        // inv: 0≤iCan≤numvertex
        int iCan, numvertex;
};

#endif // CANDIDAT_H
