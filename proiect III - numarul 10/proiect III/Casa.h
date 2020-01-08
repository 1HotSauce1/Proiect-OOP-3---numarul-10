#pragma once
#include "Locuinta.h"
#include <vector>

class Casa : public Locuinta
{
protected:
	float suprafataC, numarEtaje, pretC;
	vector<float> suprafataE;
public:
	///////////// Constructori /////////////
	Casa() : Locuinta(), suprafataC(NULL), numarEtaje(NULL), suprafataE(numarEtaje, NULL), pretC(NULL) {};
	Casa(string c, float s, float d, float p, float sc, float ne, vector<float> se) : Locuinta(c, s, d, p), suprafataC(sc), numarEtaje(ne), suprafataE(se), pretC(NULL) {};
	Casa(const Casa &X) : Locuinta(X), suprafataC(X.suprafataC), numarEtaje(X.numarEtaje), suprafataE(X.suprafataE), pretC(X.pretC) {};

	///////////// Operatori si Functii ajutatoare /////////////
	Casa& operator = (const Casa &);
	friend istream & operator >> (istream &, Casa &);
	void afisare();
	float calcul_chirie();

	///////////// Destructor /////////////
	virtual ~Casa() {
		suprafataC = NULL;
		numarEtaje = NULL;
		pretC = NULL;
		client.clear();
		suprafata = NULL;
		discount = NULL;
		pretM = NULL;
		suprafataE.clear();
	}
};

