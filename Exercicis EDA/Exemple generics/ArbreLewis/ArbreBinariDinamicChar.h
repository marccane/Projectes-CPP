#include "ArbreBinariDinamic.h" // per "veure" la definici� gen�rica
class ArbreBinariDinamicChar : public ArbreBinariDinamic<char> {
public:
	ArbreBinariDinamicChar() : ArbreBinariDinamic<char>() {}
	ArbreBinariDinamicChar(ArbreBinariDinamicChar*a, ArbreBinariDinamicChar*b, const char &c) : ArbreBinariDinamic<char>(a, b,c) {}
};