#pragma once
#include<iostream>
using namespace std;

template <class t>
class Lista
{
private:
	int trDuzina;
	t* niz;
	int brtr;
public:
	Lista();
	Lista(int trDuzina);
	~Lista();
	void dodaj(t element);
	void obrisi(int indeks);
	
	Lista<t> operator+(Lista<t>& element);
	Lista<t>& operator=(const Lista<t>& desni);

	void zauzmiMem(int novaDuzina);
	void oslobodimem();
	void kopiraj(t* tempNiz, int staraDuzina);

	friend ostream& operator<<(ostream& izlaz, Lista<t>& l) {
		for (int i = 0; i < l.brtr; i++)
			izlaz << l.niz[i] << endl;
		return izlaz;
	}
};

template<class t>
inline Lista<t>::Lista()
{
	zauzmiMem(5);
}

template<class t>
inline Lista<t>::Lista(int trDuzina)
{
	zauzmiMem(trDuzina);

}

template<class t>
inline Lista<t>::~Lista()
{
	oslobodimem();
}

template<class t>
inline void Lista<t>::dodaj(t element)
{
	if (brtr < trDuzina)
		niz[brtr++] = element;
	else {
		t* temp = new t[trDuzina*2];
		for (int i = 0; i < trDuzina; i++)
			temp[i] = niz[i];
		
		oslobodimem();
		niz = temp;
		trDuzina *= 2;
		niz[brtr++] = element;
	}
}

template<class t>
inline void Lista<t>::obrisi(int indeks)
{
	for (int i = 0; i < brtr; i++)
		if (niz[i] == indeks) {				
			for (int j = i; j < brtr - 1; j++)
				niz[j] = niz[j + 1];
			niz[--brtr] = t();
			i--;
		}
}

template<class t>
inline Lista<t> Lista<t>::operator+(Lista<t>& element)
{
	Lista temp(this->trDuzina + element.trDuzina);

	for (int i = 0; i < this->brtr; i++)
		temp.dodaj(this->niz[i]);

	for (int i = 0; i < element.brtr; i++)
		temp.dodaj(element.niz[i]);

	return temp;

	//drugacije treba ali sam ja uradio obicnu uniju
}

template<class t>
inline Lista<t>& Lista<t>::operator=(const Lista<t>& desni)
{
	if (this != &desni) {
		this->oslobodimem();
		this->zauzmiMem(desni.trDuzina);
		this->kopiraj(desni.niz, desni.brtr);
	}
	return *this;
}

template<class t>
inline void Lista<t>::zauzmiMem(int novaDuzina)
{
	brtr = 0;
	trDuzina = novaDuzina;
	niz = new t[trDuzina];
	for (int i = 0; i < trDuzina; i++)
		niz[i] = t();
}

template<class t>
inline void Lista<t>::oslobodimem()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class t>
inline void Lista<t>::kopiraj(t* tempNiz, int staraDuzina)
{
	for (int i = 0; i < staraDuzina; i++)
		dodaj(tempNiz[i]);
}