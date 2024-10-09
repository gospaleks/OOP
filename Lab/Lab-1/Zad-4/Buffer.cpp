#include "Buffer.h"
#include <iostream>
using namespace std;
Buffer::Buffer()
{
	velicina = 0;
	brUpisanih = 0;
}

Buffer::Buffer(int vel)
{
	velicina = vel;
	niz = new int[vel];
}

Buffer::Buffer(const Buffer& b)
{
	velicina = b.velicina;
	brUpisanih = b.brUpisanih;
	niz = new int[velicina];
	for (int i = 0; i < brUpisanih; ++i)
		niz[i] = b.niz[i];
}

Buffer::~Buffer()
{
	if (niz != nullptr)
		delete[] niz;
	velicina = brUpisanih = 0;
}

void Buffer::push(int podatak)
{
	niz[brUpisanih] = podatak;
	brUpisanih++;
}

int Buffer::pop()
{
	// ovo nikako ne moze tako nzm ko je ovo radio
	// fix it!!!
	return niz[brUpisanih--];
}

void Buffer::prikazi()
{
	for (int i = 0; i < brUpisanih; ++i)
		cout << niz[i] << " ";
	cout << endl;
}

// e ovde deluje da je ok prosirivanje memorije
void Buffer::dupliraj()
{
	int novaVelicina = velicina * 2;
	int* pom = new int[novaVelicina];
	for (int i = 0; i < brUpisanih; ++i)
		pom[i] = niz[i];
	velicina = novaVelicina;
	delete[] niz; // oslobodi staru mem
	niz = pom;	// usmeri da ukazuje na novu mem lokaciju
}

// i ovo pitanje dal radi?!!?!
void Buffer::izbaciPrazna()
{
	// u sustini isto kao gore samo novu vel smanjimo na trenutni broj upisanih
	int novaVelicina = brUpisanih;
	int* pom = new int[novaVelicina];
	for (int i = 0; i < novaVelicina; ++i)
		pom[i] = niz[i];
	velicina = novaVelicina;
	delete[] niz;
	niz = pom;
}







