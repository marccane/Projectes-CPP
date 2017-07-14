#ifndef JOC_H
#define JOC_H
#include "PilaCartes.h"
#include "Tauler.h"
#include "Carta.h"
#include "Baralla.h"

class Joc
{
    public:
        Joc(Baralla);
        //Pre: -- //Post: Mostra l'estat del joc
        void mostrar();
        //Pre: -- //Post: Comença el joc
        void Jugar();

    private:
        //METODES PRIVATS
        //CONSULTORS
        //Pre: -- //Post: Mostra el menú
        void MostrarMenu()const;
        //Pre: -- //Post: Demana la columna al jugador i la retorna
        int Demanar_columna()const;
        //Pre: -- //Post: Demana la fila i la columna de la carta que volguem moure
        void Demanar_origen(int &col, int &fila)const;
        //Pre: Una pila no buida //Post: Mostra la carta superior de la pila entrada
        void Mostrar_Cim_Pila(const PilaCartes &pila)const;
        //MODIFICADORS
        //Pre: Baralla amb almenys 28 cartes //Post: Posa les cartes que no cabien al tauler a la pila de la mà
        void emplenar_ma(Baralla);
        //Pre: -- //Post: Demana quina opcio volem fer al joc
        void TriarOpcio();
        //Pre: -- //Post: Posa a la columna col del tauler la carta car. Retorna cert si es mou amb èxit
        bool PosarAlTauler(Carta car, int col);
        //Pre: -- //Post: Retorna cert si s'ha guanyat la partida
        bool Partida_Guanyada();
        //Pre: -- //Post: Posa la carta car a la pila corresponent si és possible
        bool PosarALaPila(Carta car);

        //ATRIBUTS:
        int a_opcio;
        bool a_guanyada;
        PilaCartes a_ma, a_descartades, a_pals[4];
        Tauler a_tauler;
};

#endif // JOC_H
