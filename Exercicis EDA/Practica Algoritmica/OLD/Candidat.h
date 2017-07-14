#ifndef CANDIDAT_H
#define CANDIDAT_H

class Candidat
{
    public:
        Candidat(int);
        int actual() const;
        bool esFi() const;
        void seguent();
        void mostrar() const;
    private:
        // inv: 0≤iCan≤3
        int iCan, numvertex;
};

#endif // CANDIDAT_H
