#include "pch.h"
#include "Gestiune.h"
#include "Apartament.h"
#include <string>
#include <set>

using namespace std;
// Gestiune Locuinta.

template<typename T>
Gestiune<T>::Gestiune(int l, int i, T* v) {
	length = l;
	index = i;

	delete vector;
	vector = new T[length];
	for (int i = 0; i < length; i++)
		vector[i] = v[i];
}

template<typename T>
Gestiune<T>::Gestiune(const Gestiune &X) {
	length = X.length;
	index = X.length;

	delete vector;
	vector = new T[length];
	for (int i = 0; i < length; i++)
		vector[i] = X.vector[i];
}

template<typename T>
Gestiune<T>& Gestiune<T>::operator += (const Locuinta* locuinta)
{
	length++;
	index++;
	vector = new T[length];
	vector[length - 1] = Locuinta;

	return *this;
}

template<typename T>
Gestiune<T>& Gestiune<T>::operator += (const T* generic)
{
	length++;
	index++;
	vector = new T[length];
	vector[length - 1] = generic;

	return *this;
}

template<typename T>
Gestiune<T>& Gestiune<T>::operator = (const Gestiune<T> &X)
{
	length = X.length;
	index = X.index;

	delete vector;
	vector = new T[length];
	for (int i = 0; i < length; i++)
		vector[i] = X.vector[i];

	return *this;
}

template<typename T>
ostream & operator << (ostream &out, Gestiune<T> &X)
{
	out << "Locuintele sunt: ";
	for (int i = 0; i < X.length; i++)
		out << X.vector[i] << ' ';
	out << endl;
	return out;
}

template<typename T>
istream & operator >> (istream &in, Gestiune<T> &X)
{
	cout << "Introduceti locuintele" << endl;

	for (int i = 0; i < X.length; i++)
	{
		string locuinta;
		cout << "Ce fel de locuinta?: ";
		getline(in, locuinta);

		if (locuinta.compare("Casa"))
		{
			Casa c;
			in >> c;
			X += c;
		}
		else
		{
			Apartament a;
			in >> a;
			X += a;
		}
	}
	return in;
}

// Gestiune Casa.

Gestiune<Casa>::Gestiune(int l, int i, pair<Casa, float>* v) {
	length = l;
	index = i;

	delete vector;
	vector = new pair<Casa, float>[length];
	for (int i = 0; i < length; i++)
		vector[i] = v[i];
}

Gestiune<Casa>::Gestiune(const Gestiune<Casa> &X) {
	length = X.length;
	index = X.length;

	delete vector;
	vector = new pair<Casa, float>[length];
	for (int i = 0; i < length; i++)
		vector[i] = X.vector[i];
}

float Gestiune<Casa>::chirieTotal()
{
	float chirie = 0.0f;
	for (int i = 0; i < length; i++)
		chirie += vector[i].second;

	return chirie;
}

Gestiune<Casa>& Gestiune<Casa>::operator += (Casa casa)
{
	length++;
	index++;

	float chirie = casa.calcul_chirie();
	pair<Casa , float> element;
	element = make_pair(casa, chirie);
	
	vector = new pair<Casa, float>[length];
	vector[length - 1] = element;

	return *this;
}

Gestiune<Casa>& Gestiune<Casa>::operator = (const Gestiune<Casa> &X)
{
	length = X.length;
	index = X.index;

	delete vector;
	vector = new pair<Casa, float>[length];
	for (int i = 0; i < length; i++)
		vector[i] = X.vector[i];

	return *this;
}
