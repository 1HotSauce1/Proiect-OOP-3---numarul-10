#include "pch.h"
#include "Casa.h"
#include <string>

void Casa::afisare()
{
	cout << endl;
	cout << "Numele clientului: " << client << endl;
	cout << "Suprafata casa: ";
	float s = 0;
	for (auto i : suprafataE)
		s += i;
	cout << s + suprafata << endl;  // adunam si suprafata parterului.
	cout << "Pret pe m^2 interior: " << pretM << " lei" << endl;

	cout << "Suprafata curte: " << suprafataC << endl;
	cout << "Pret pe m^2 curte: " << pretC << " lei" << endl;
	cout << "Suprafata totala: " << s + suprafataC + suprafata << endl;
	cout << "Discount: " << discount << '%' << endl;
	cout << "Chiria este :" << calcul_chirie() << " lei" << endl;
}

Casa& Casa::operator = (const Casa &X)
{
	client.clear();
	client.assign(X.client);

	suprafata = X.suprafata;
	discount = X.discount;
	suprafataC = X.suprafataC;
	numarEtaje = X.numarEtaje;
	pretC = X.pretC;

	suprafataE.clear();
	for (auto i : X.suprafataE)
		suprafataE.push_back(i);

	return *this;
}

float Casa::calcul_chirie()
{
	float auxS = 0, auxC = pretC * suprafataC;
	for (auto i : suprafataE)
		auxS += i;
	auxS += suprafata;
	auxS *= pretM;

	return auxS - auxS * discount / 10 + auxC;
}

istream & operator >> (istream &in, Casa &X)
{
	cout << "Numele: ";
	getline(in, X.client);

	cout << "Suprafata: ";
	in >> X.suprafata;

	cout << "Pret pe m^2: ";
	in >> X.pretM;

	cout << "Discount: ";
	in >> X.discount;

	cout << "Suprafata curte: ";
	in >> X.suprafataC;

	cout << "Pret pe m^2 curte: ";
	in >> X.pretC;

	cout << "Numar etaje: ";
	in >> X.numarEtaje;

	cout << "Suprafata pe etaje:\n";
	for (int i = 0; i < X.numarEtaje; i++)
	{
		float x;
		cout << "Etajul numarul " << i + 1 << ": ";
		in >> x;
		X.suprafataE.push_back(x);
	}

	return in;
}

