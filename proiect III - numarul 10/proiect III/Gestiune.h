#pragma once
#include "Casa.h"
#include <iostream>

using namespace std;

template<typename T>
class Gestiune
{
private:
	int length;  //lungimea vectorului.
	int index;   //numarul de locuinte de fiecare fel.
	T* vector;
public:
	Gestiune() : length(NULL), index(NULL), vector(nullptr) {};
	Gestiune(int, int, T*);
	Gestiune(const Gestiune &);

	Gestiune& operator += (const Locuinta*);
	Gestiune& operator += (const T*);
	Gestiune& operator = (const Gestiune &);
	friend ostream & operator << (ostream&, Gestiune &);
	friend istream & operator >> (istream&, Gestiune &);

	~Gestiune() {
		length = NULL;
		index = NULL;
		delete vector;
	}
};

// specializare pentru Casa.
template<>
class Gestiune<Casa>
{
private:
	int length;
	int index;
	pair<Casa, float> *vector;  // pentru fiecare casa avem o chirie de tip float.
public:
	Gestiune() : length(NULL), index(NULL), vector(nullptr) {};
	Gestiune(int, int, pair<Casa, float>*);
	Gestiune(const Gestiune<Casa> &);

	Gestiune& operator += (Casa);
	Gestiune<Casa>& operator = (const Gestiune<Casa> &);
	friend ostream & operator << (ostream&, Gestiune<Casa> &);
	friend istream & operator >> (istream&, Gestiune<Casa> &);

	~Gestiune() {
		length = NULL;
		index = NULL;
		delete vector;
	}
	float chirieTotal();
};