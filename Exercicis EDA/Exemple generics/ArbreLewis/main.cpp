#include <iostream>
#include "ArbreBinariDinamicChar.h"
#include "ArbreBinariDinamic.h"

using namespace std;

int main()
{
	//ArbreBinariDinamicChar stub, f(&stub,&stub,'f'), e(&stub,&f,'e'), c(&stub,&stub,'c'), d(&f,&e,'d'), b(&stub,&c,'b'), a(&b,&d,'a');
	ArbreBinariDinamicChar stub, d(&stub,&stub,'d'), e(&stub,&stub,'e'),c(&d,&e,'c'), b(&stub,&stub,'b'), a(&b,&c,'a');
	a.mostrar(&a);
}
