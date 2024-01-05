#pragma once
#include <string.h>
#include <fstream>
#include <iostream>

template <class T>
class Prodavnica
{
private:
	char* naziv;
	T* spisak;
	int brojPolica;
	int maxEl;
	int top;
	
	void ZauzmiMem(const char* _naziv, int _brPolica);
public:
	Prodavnica();
	Prodavnica(const char* _naziv, int _brPolica);
	~Prodavnica();

	void Dodaj(T& proizvod);
	void Prodaj(int poz);
	float SrednjaVrednost();

	void UpisiUFajl(const char* imeFajla);
	void CitajIzFajla(const char* imeFajla);

	void StampajNaEkran();
};

template<class T>
inline void Prodavnica<T>::ZauzmiMem(const char* _naziv, int _brPolica)
{
	maxEl = _brPolica * 5;
	naziv = new char[strlen(_naziv) + 1];
	strcpy(naziv, _naziv);
	spisak = new T[maxEl];
}

template<class T>
inline Prodavnica<T>::Prodavnica()
{
	naziv = nullptr;
	spisak = nullptr;
	brojPolica = 0;
	maxEl = 0;
	top = 0;
}


template<class T>
inline Prodavnica<T>::Prodavnica(const char* _naziv, int _brPolica)
{
	top = 0;
	brojPolica = _brPolica;
	ZauzmiMem(_naziv, _brPolica);
}

template<class T>
inline Prodavnica<T>::~Prodavnica()
{
	if (naziv != nullptr)
		delete[] naziv;
	if (spisak != nullptr)
		delete[] spisak;
}

template<class T>
inline void Prodavnica<T>::Dodaj(T& proizvod)
{
	if (top == maxEl)
		throw "Nema vise mesta u prodavnici.";
	else {
		spisak[top++] = proizvod;
	}
}

template<class T>
inline void Prodavnica<T>::Prodaj(int poz)
{
	if (poz < 0 || poz >= top)
		throw "Prozivod sa takvim rednim brojem ne postoji.";
	else {
		for (int j = poz; j < top; ++j)
			spisak[j] = spisak[j + 1];
		top--;
		spisak[top] = T();
	}
}

template<class T>
inline float Prodavnica<T>::SrednjaVrednost()
{
	float rez = 0;
	for (int i = 0; i < top; ++i)
		rez = spisak[i] + rez;		// napravi odgovarajuci operator
	return (rez / top);
}

template<class T>
inline void Prodavnica<T>::UpisiUFajl(const char* imeFajla)
{
	std::ofstream izlaz(imeFajla);
	if (!izlaz.good())
		throw "Neuspesno upisivanje u fajl.";
	else {
		izlaz << naziv << std::endl;
		izlaz << brojPolica << std::endl;
		izlaz << top << std::endl;
		for (int i = 0; i < top; ++i)
			izlaz << spisak[i] << std::endl;
		izlaz.close();
	}
}

template<class T>
inline void Prodavnica<T>::CitajIzFajla(const char* imeFajla)
{
	std::ifstream ulaz(imeFajla);
	if (!ulaz.good())
		throw "Neuspesno citanje iz fajla.";
	else {
		char tmpNaziv[100];
		ulaz >> tmpNaziv;
		ulaz >> brojPolica;
		ulaz >> top;
		ZauzmiMem(tmpNaziv, brojPolica);
		for (int i = 0; i < top; ++i)
			ulaz >> spisak[i];				// napravi operator za >>
	}
}

template<class T>
inline void Prodavnica<T>::StampajNaEkran()
{
	for (int i = 0; i < top; ++i)
		std::cout << spisak[i] << std::endl;
}
