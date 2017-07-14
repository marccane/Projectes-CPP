#ifndef FRACCIO_H
#define FRACCIO_H

class Fraccio
{
    public:
        Fraccio();
        void LlegirFraccio(int);
        void SimplificarFraccio();
        void OperarFraccio(char operacio, Fraccio f1, Fraccio f2);
        void PosarSigne();
        void Mostrar() const;
    private:
        bool esdivisible(int a, int b);
        int numerador, denominador;
        char signe;
};

#endif // FRACCIO_H
