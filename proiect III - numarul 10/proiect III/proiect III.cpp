#include "pch.h"
#include <iostream>
#include "Gestiune.h"
#include "Apartament.h"
#include "Casa.h"
#include <set>

using namespace std;

void citireSet(set<pair<Locuinta *, int>> &X)
{
	int n;
	cout << "Numarul de locuinte: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int loc;
		cout << "Ce fel de locuinta 1 sau 2";
		cin >> loc;

		if (loc == 1)
		{
			Casa c;
			cin >> c;
			pair<Casa, int> element;
			element = make_pair(c, loc);
			//X.insert(element);
		}
		else
		{
			Apartament a;
			cin >> a;
			pair<Apartament, int> element;
			element = make_pair(a, loc);
			//X.insert(element);
		}
	}
}

int main()
{
	int tip; //1-Casa, 2-Apartament
	set<pair<Locuinta *, int>> AUX;
	citireSet(AUX);
}

