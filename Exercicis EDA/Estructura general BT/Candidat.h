#ifndef CANDIDAT_H
#define CANDIDAT_H

class Candidat
{
    public:
        Candidat();
        int actual() const;
        bool esFi() const;
        void seguent();
        void mostrar() const;
    private:
        // inv: 0≤iCan≤3
        int iCan;
};

#endif // CANDIDAT_H
