#ifndef CARTA_H
#define CARTA_H

class Carta
{
    public:
        //CONSTRUCTOR
        Carta();
        //CONSULTORS
        //Pre: -- //Post: Mostra la carta si aquesta est� oberta o b� mostra dos asteriscs si �s tancada
        void mostrar()const;
        //Pre: -- //Post: Retorna cert si la carta es de color negre
        bool esnegra()const;
        //Pre: -- //Post: Retorna cert si la carta �s oberta
        bool esoberta()const;
        //Pre: -- //Post:Retorna el pal de la carta
        char Get_Pal()const;
        //Pre: -- //Post: Retorna cert si la carta entrada casa amb la actual(gran)
        bool Casen(Carta, bool espila=0)const;
        //Pre: -- //Post:Retorna cert si la carta �s rei
        bool EsRei()const;
        //Pre: -- //Post:Retorna cert si la carta t� el valor A
        bool EsA()const;
        //MODIFICADORS
         //Pre: -- //Post: La carta es modifica amb les dades entrades
        void Modificar(char valor, char pal);
        //Pre: -- //Post: Els elements intercanviats
        void Intercanviar(Carta &b);
        //Pre: -- //Post: Modifica la carta i passa a estar en l'estat que hem entrat
        void Set_obrir(bool obrir);
        //METODES DE CLASE
        //Pre: Un vector de chars de tamany 13 o superior //Post: Retorna el vector omplert amb els car�cters corresponents als valors
        static void CrearVectorValors(char vecvalors[]);
    private:
        char a_valor, a_pal;
        bool a_oberta;
};

#endif // CARTA_H
