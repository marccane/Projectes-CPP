#ifndef LLISTAORDENTERS_H
#define LLISTAORDENTERS_H
class LlistaOrdEnters{
//falten algunes pres i posts!
//cal acabar d'implementar alguns mètodes!
public:
LlistaOrdEnters();
 LlistaOrdEnters(const LlistaOrdEnters &o);
 ~LlistaOrdEnters();
LlistaOrdEnters &operator=(const LlistaOrdEnters &o);
bool existeix(int e) const;
bool buida() const;
void llistar() const;
void inserir(int e);
void esborrar(int e);
private:
struct Node {
 int dada;
 Node *seg;
};
Node *a_inici;
 void copiar(const LlistaOrdEnters &o);
 void alliberar();
};
#endif
