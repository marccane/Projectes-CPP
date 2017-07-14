#ifndef POSICIO_H
#define POSICIO_H

class Posicio
{
    public:
        Posicio(int px=0, int py=0);
        Posicio operator+(const Posicio&);
        bool operator==(const Posicio&);
        int Getx() { return x; }
        int Gety() { return y; }
    private:
        int x, y;
};

#endif // POSICIO_H
