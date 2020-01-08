#pragma once
#include "Locuinta.h"

class Apartament : public Locuinta
{
protected:
	unsigned etaj;
public:
	///////////// Constructori /////////////
	Apartament() : Locuinta(), etaj(NULL) {};
	Apartament(string c, float s, float d, float p, unsigned e) : Locuinta(c, s, d, p), etaj(e) {};
	Apartament(const Apartament &X) : Locuinta(X), etaj(X.etaj) {};

	///////////// Operatori si Functii ajutatoare /////////////
	Apartament& operator = (const Apartament &);
	friend istream & operator >> (istream &, Apartament &);
	void afisare();
	float calcul_chirie();


	///////////// Destructor /////////////
	virtual ~Apartament() {
		client.clear();
		suprafata = NULL;
		discount = NULL;
		pretM = NULL;
		etaj = NULL; 
	}
};

