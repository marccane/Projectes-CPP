#ifndef LLISTALLIBRES_H
#define LLISTALLIBRES_H
#include "Llibre.h"

class LlistaLlibres{
    public:
        LlistaLlibres();
         LlistaLlibres(const LlistaLlibres &o);
         ~LlistaLlibres();
        LlistaLlibres &operator=(const LlistaLlibres &o);
        bool existeix(Llibre e) const;
        bool buida() const;
        void llistar() const;
        void inserir(Llibre e);
        void esborrar(Llibre e);
        void Mostrar_mes_venuts();
        void Actualitzar_llibres();
        void Actualitzar_Setmana_Llibres(Llibre);
        void Eliminar_novenuts();
    private:
        struct Node {
             Llibre dada;
             Node *seg;
        };
        Node *a_inici;
        void copiar(const LlistaLlibres &o);
        void alliberar();


};
#endif


/*!
Classe LlistaLlibres, operacions (interfície):
Constructor per defecte.
crea una llista buida (només inicialitza punters)
buida
retorna cert si la llista és buida; fals en c.c.
Un mètode per mostrar tots els llibres
fa un recorregut i mostra els llibres (títol, autor, nombre vendes de 4 setmanes).
Un mètode que mostra el llibre més venut
troba les vendes màximes i ens mostra tots els llibres que les han assolit.
Un mètode que actualitza els elements per a una nova setmana
actualitza de manera convenient les vendes dels llibres per una nova setmana, invocant el
mètode de Llibre
actualitza (const Llibre& e)
ha actualitzat les vendes de e si ja existia o ha inserit e a la llista si no existia
Un mètode que elimina els llibres no venuts
fa un recorregut i va eliminant tots aquells llibres que no han estat venuts en les 4 últimes
setmanes
A més, cal tenir (ja que la llista és dinàmica):
constructor de còpia.
operador d’assignació.
destructor
*/
