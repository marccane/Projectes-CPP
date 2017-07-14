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
Classe Llibre, operacions (interf�cie):
Constructor per defecte
Un m�tode per llegir llibre
cal llegir les dades d�un llibre
el t�tol i l�autor poden contenir espais (veure seg�ent transpar�ncia)
Un m�tode per mostrar llibre
es mostra la informaci� del llibre en el format especificat
Un m�tode per calcular el exemplars venuts les darreres 4 setmanes
cal que retorni un enter que sigui la suma de les 4 darreres setmanes
Un m�tode esFinal
per saber si correspon a la marca de fi de la seq��ncia; retorna boole�
Un m�tode que ens actualitzi el llibre per a una nova setmana
cal reassignar els nombres de vendes de cadascuna de les setmanes
Atributs:
strings per t�tol i autor
quatre enters (pot ser una taula) per desar les vendes de les �ltimes setmanes
*/
