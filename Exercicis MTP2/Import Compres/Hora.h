#ifndef HORA_H
#define HORA_H

class Hora
{
    public:
        Hora();
        void Llegir();
        bool Esmesantiga(Hora);
        void Reiniciar_hora();
        void Mostrar();
    private:
        int hores, minuts;
        bool Esvalida();
};

#endif // HORA_H
