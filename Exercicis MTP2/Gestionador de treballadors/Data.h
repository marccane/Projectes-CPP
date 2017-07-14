#ifndef DATA_H
#define DATA_H

class Data {
// Descripci�: guarda el dia, mes i any d�una data
// Invariant: dia/mes/any �s una data correcta
public:
// CONSTRUCTORS
Data();
//Pre: --; Post: �s la data xx/xx/xxxx
// CONSULTORS
void mostrar() const;
//Pre: --; Post: mostra la data actual en format dia/mes/any
bool esMesAntiga(Data d) const;
//Pre:--; Post: cert si d �s una data posterior a l�actual, fals altrament
// MODIFICADORS
void llegir();
//Pre:--; Post: llegeix dates dia/mes/any fins a llegir-ne una de correcte.
private:
int dia, mes, any;
//METODES DE CLASSE
bool esDataValida(int dia, int mes, int any);
};

#endif // DATA_H
