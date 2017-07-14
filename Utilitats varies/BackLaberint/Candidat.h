#ifndef CANDIDAT_H
#define CANDIDAT_H

struct Posicio{
    Posicio(){};
    Posicio(int px, int py):x(px), y(py){};
    int x,y;
};

static const Posicio despl[]={Posicio(1,0),Posicio(0,1),Posicio(-1,0),Posicio(0,-1)};

class Candidat
{
    public:
        Candidat(Posicio);
        Posicio actual() const;
        bool esFi() const;
        void seguent();
        Posicio Get_anterior()const;
        void mostrar() const;
    private:
        // inv: 0≤iCan≤3
        int iCan;
        Posicio anterior;
};

#endif // CANDIDAT_H
