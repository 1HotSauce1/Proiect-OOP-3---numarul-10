#pragma once
#include <iostream>

using namespace std;

class Locuinta
{
protected:
	string client;
	float suprafata, discount, pretM;
public:
	///////////// Constructori /////////////
	Locuinta() : client(""), suprafata(NULL), discount(NULL), pretM(NULL) {};
	Locuinta(string c, float s, float d, float p) : client(c), suprafata(s), discount(d), pretM(p) {};
	Locuinta(const Locuinta &x) : client(x.client), suprafata(x.suprafata), discount(x.discount), pretM(x.pretM) {};

	///////////// Operatori si Functia de afisare /////////////
	//Locuinta operator = (const Locuinta &);
	friend istream & operator >> (istream &, Locuinta &);
	virtual void afisare();
	virtual float calcul_chirie() = 0;

	///////////// Destructor /////////////
	virtual ~Locuinta() {
		client.clear();
		suprafata = NULL;
		discount = NULL;
		pretM = NULL;
	}
};

