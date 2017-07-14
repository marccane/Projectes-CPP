#include <string>
#ifndef PARAULA_H
#define PARAULA_H

using namespace std;

class Paraula
{
    public:
        Paraula();
        string GetParaula() const;
		void Mostrar() const;
        void Modificar(string);
        void incrementar_comptador();
        bool esdinteres(string*,int);
    private:
        void Arreglar();
        string par;
        int vegades;
};

#endif // PARAULA_H
