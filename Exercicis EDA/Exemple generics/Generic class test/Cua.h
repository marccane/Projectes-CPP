#ifndef CUA_H
#define CUA_H



template <class element>
class Cua {
public:
	// Cua() = 0; // no cal a la classe virtual
	virtual ~Cua() {} // cal fer una implementacio buida
	virtual void Encua(const element &e) = 0;
	virtual void Desencua()= 0;
	virtual element Primer() const = 0;
	virtual bool esBuida() const = 0;
	virtual bool esPlena() const = 0;
};

#endif // CUA_H
