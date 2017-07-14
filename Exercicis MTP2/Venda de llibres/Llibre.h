#ifndef LLIBRE_H
#define LLIBRE_H
#include <string>

class Llibre
{
    public:
        Llibre();
        void Llegir();
        void Mostrar();
        int Venuts_darrermes();
        bool Esfinal();
        void Actualitzar_setmana();
        bool operator==(Llibre b);
        bool operator<(Llibre b);
        bool operator<=(Llibre b);
        void Actualitzar_Setmana_Llibre(Llibre a);
        void Inserir(Llibre a);
    private:
        std::string nom, autor;
        int ventes_setmana[5];
        int Get_ventesultimasetmana() const;
};

#endif // LLIBRE_H

/*!
Classe Llibre, operacions (interfície):
Constructor per defecte
Un mètode per llegir llibre
cal llegir les dades d’un llibre
el títol i l’autor poden contenir espais (veure següent transparència)
Un mètode per mostrar llibre
es mostra la informació del llibre en el format especificat
Un mètode per calcular el exemplars venuts les darreres 4 setmanes
cal que retorni un enter que sigui la suma de les 4 darreres setmanes
Un mètode esFinal
per saber si correspon a la marca de fi de la seqüència; retorna booleà
Un mètode que ens actualitzi el llibre per a una nova setmana
cal reassignar els nombres de vendes de cadascuna de les setmanes
Atributs:
strings per títol i autor
quatre enters (pot ser una taula) per desar les vendes de les últimes setmanes
*/
