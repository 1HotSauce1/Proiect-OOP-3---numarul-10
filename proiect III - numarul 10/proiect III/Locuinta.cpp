#include "pch.h"
#include "Locuinta.h"
#include <string>

using namespace std;

/*Locuinta& Locuinta::operator = (const Locuinta &X)
{
	client.clear();
	client.assign(X.client);
	suprafata = X.suprafata;
	discount = X.discount;

	return *this;
}*/

istream & operator >> (istream &in, Locuinta &X)
{
	cout << "Numele: ";
	getline(in, X.client);

	cout << "Suprafata: ";
	in >> X.suprafata;

	cout << "Pret pe m^2: ";
	in >> X.pretM;

	cout << "Discount: ";
	in >> X.discount;

	return in;
}

void Locuinta::afisare()
{
	cout << endl;
	cout << "Numele clientului: " << client << endl;
	cout << "Suprafata: " << suprafata << " m^2" << endl;
	cout << "Pret pe m^2: " << pretM << " lei" << endl;
	cout << "Discount: " << discount << '%' << endl;
}

