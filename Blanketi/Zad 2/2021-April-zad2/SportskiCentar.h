#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class t>
class SportskiCentar
{
private:
	t* niz;		//sale
	int nmax;
	int brtr;
	void zauzmimem(int _nmax);
public:
	SportskiCentar();
	SportskiCentar(int _nmax);
	~SportskiCentar();
	void dodaj(t& element);
	void obrisi(int indeks);
	void izvestajprosek(const char* imefajla);		//doradjeno da radi upis u fajlove kao na 2.klk iste godine
	void izvestajnajvrednija(const char* imefajla);
	void izvestajnajmanjevredna(const char* imefajla);

	friend ostream& operator<<(ostream& izlaz, const SportskiCentar<t>& spc) {
		for (int i = 0; i < spc.brtr; i++)
			izlaz << spc.niz[i] << endl;				
		return izlaz;
	}
	
	friend istream& operator>>(istream& ulaz, SportskiCentar<t>& spc) {
		int n;
		ulaz >> n;
		spc.zauzmimem(n);
		for (int i = 0; i < n; i++) {
			t* el = new t();
			ulaz >> *el;
			spc.dodaj(*el);
		}
		return ulaz;
	}
};

template<class t>
inline void SportskiCentar<t>::zauzmimem(int _nmax)
{
	nmax = _nmax;
	brtr = 0;
	niz = new t[nmax];
}

template<class t>
inline SportskiCentar<t>::SportskiCentar()
{
	nmax = brtr = 0;
	niz = nullptr;
}

template<class t>
inline SportskiCentar<t>::SportskiCentar(int _nmax)
{
	zauzmimem(_nmax);
}

template<class t>
inline SportskiCentar<t>::~SportskiCentar()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class t>
inline void SportskiCentar<t>::dodaj(t& element)
{
	if (brtr == nmax)
		throw "nema vise slobodnih sala";
	else {
		int i = 0;
		while (i<brtr && niz[i] > element)
			++i;							
		for (int j = brtr; j > i; j--)
			niz[j] = niz[j - 1];
		niz[i] = element;
		brtr++;
	}
}

template<class t>
inline void SportskiCentar<t>::obrisi(int indeks)
{
	if (indeks <= 0 || indeks >= brtr)
		throw "nepostojeci indeks";
	else {
		for (int i = indeks; i < brtr - 1; i++)
			niz[i] = niz[i + 1];		
		brtr--;
	}
}

template<class t>
inline void SportskiCentar<t>::izvestajprosek(const char* imefajla)
{
	ofstream izlaz(imefajla);
	if (!izlaz.good())
		throw "problem sa otvaranje fajla za prosek";
	else {
		float aktivnost = 0;
		if (brtr == 0)
			izlaz << "0";
		else {
			for (int i = 0; i < brtr; i++)
				aktivnost = niz[i] + aktivnost;		
		}
		aktivnost /= brtr;
		izlaz << "prosecna aktivnost je: " << aktivnost << endl;
		izlaz.close();
	}
}

template<class t>
inline void SportskiCentar<t>::izvestajnajvrednija(const char* imefajla)
{
	ofstream izlaz(imefajla);
	if (!izlaz.good())
		throw "problem pri otvaranju fajla za min";
	else {
		if (brtr == 0)
			throw "nema aktivnosti";
		else
			izlaz << "najveca aktivnost je " << endl << niz[0];
	}
}

template<class t>
inline void SportskiCentar<t>::izvestajnajmanjevredna(const char* imefajla)
{
	ofstream izlaz(imefajla);
	if (!izlaz.good())
		throw "problem pri otvaranju fajla za min";
	else {
		if (brtr == 0)
			throw "nema aktivnosti";
		else
			izlaz << "najmanja aktivnost je " << endl << niz[brtr - 1];
	}
}
