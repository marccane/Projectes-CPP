#ifndef EX2017_H
#define EX2017_H
#include <map>

class ex2017
{
    public:
        ex2017();
        void llistarMaria() const;
        void mostrarOverbooking(const codi:assignatures & c) const;

    private:
        map<dni,alumne> alumnes;
        map<codi_assignatura, assignatura> assignatures;
        map<dni,map<codiassignatura, nota>> mat_alumnes;
};

#endif // EX2017_H
