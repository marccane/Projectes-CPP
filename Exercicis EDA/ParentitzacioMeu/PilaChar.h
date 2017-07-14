#pragma once


class PilaChar {
    // Descripcio: una pila d’Cartess
    public:
        // CONSTRUCTORS I DESTRUCTOR ----------------------------------
        // Pre: --; Post: pila buida
        PilaChar();
        // Pre: --; Post: aquesta pila es copia de la pila o
        PilaChar(const PilaChar& o);  // const. de copia
        // Pre: --; Post: memoria alliberada
        ~PilaChar();

        // CONSULTORS -------------------------------------------------
        // Pre: -- ; Post: retorna cert si la pila es buida; fals en c.c.
        bool buida() const;
        // Pre: pila no buida; Post: retorna el valor del cim de la pila
        char cim() const;


        // MODIFICADORS -----------------------------------------------
        // Pre: --; Post: ha afegit s a dalt de la pila
        void empila(char s);
        // Pre: pila no buida; Post: ha eliminat element de dalt de la pila
        void desempila();
        // Pre: -- ; Post: Les cartes de la pila girades

        // OPERADORS REDEFINITS ---------------------------------------
        // Pre: -- ; Post: aquesta pila es copia de la pila o
        PilaChar& operator=(const PilaChar& o);

		int a_x, a_y;
    private:
        struct Node {
            char valor;
            Node* seg;
        };
        // ATRIBUTS
        Node* a_cim; // punter al cim de la pila

        // METODES PRIVATS
        // Pre: pila buida; Post: aquesta pila es copia de o
        void copia(const PilaChar& o);
        // Pre: --; Post: memoria alliberada
        void allibera();
};
