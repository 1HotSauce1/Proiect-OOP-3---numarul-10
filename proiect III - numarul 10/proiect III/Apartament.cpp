#include "pch.h"
#include "Apartament.h"
#include <string>

Apartament& Apartament::operator = (const Apartament &X)
{
	client.clear();
	client.assign(X.client);
	suprafata = X.suprafata;
	discount = X.discount;
	etaj = X.etaj;

	return *this;
}

float Apartament::calcul_chirie()
{
	float auxS = suprafata * pretM;
	return auxS - (auxS * discount / 10);
}

istream & operator >> (istream &in, Apartament &X)
{
	cout << "Numele: ";
	getline(in, X.client);

	cout << "Suprafata: ";
	in >> X.suprafata;

	cout << "Pret pe m^2: ";
	in >> X.pretM;

	cout << "Discount: ";
	in >> X.discount;

	cout << "Etaj: ";
	in >> X.etaj;

	return in;
}

void Apartament::afisare()
{
	cout << endl;
	cout << "Numele clientului: " << client << endl;
	cout << "Suprafata: " << suprafata << " m^2" << endl;
	cout << "Discount: " << discount << '%' << endl;
	cout << "Etajul: " << etaj << endl;
	cout << "Chiria este: " << calcul_chirie() << " lei" << endl;
}


