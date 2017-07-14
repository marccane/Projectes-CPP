//Marc Cané Salamià
//u1939666
//Bingo permutatiu
#ifndef CONTENIDOR_H
#define CONTENIDOR_H
#include <string>
#include <vector>
#include <list>
using namespace std;

typedef vector<int> triplet;

/** \brief Representa un conjunt de permutacions d'un triplet
Conte una llista on emmagatzarem les diferents permutacions*/

class Contenidor
{
    public:
        /** @pre - @post El contenidor buit ha estat creat*/
        Contenidor();
        /** @pre - @post El triplet ha estat afegit al contenidor*/
        void Afegir(const triplet&);
        /** @pre - @post Retorna cert si existeix el triplet al contenidor*/
        bool Existeix(const triplet&);
        /** @pre - @post Retorna el tamany del contenidor*/
        int Tamany() const;

        //metodes de classe
        /** @pre - @post Retorna l'identificador del triplet original entrat*/
        static string Crear_Identificador(const triplet&);

    private:
        list<triplet> _cont; /**< Llista de triplets */
};

#endif // CONTENIDOR_H
