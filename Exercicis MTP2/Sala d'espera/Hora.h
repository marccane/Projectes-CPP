#ifndef HORA_H
#define HORA_H
#include <string>

class Hora
{
    public:
        Hora();
        void Llegir();
        bool Esmesantiga(Hora);
        void Reiniciar_hora();
        void Mostrar() const;
        int MinutsDiferencia(Hora) const;

    private:
        int hores, minuts;
        bool Esvalida();
};

#endif // HORA_H
