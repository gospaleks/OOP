#include "OrderedBuffer.h"

void OrderedBuffer::clear()
{
	for (int i = 0; i < kapacitet; ++i)
		if (niz[i] != nullptr)
			*niz[i] = 0;
}

void OrderedBuffer::push(int element)
{
	if (brElemenata < kapacitet) {
		if (brElemenata == 0) {
			niz[0] = new int;
			*niz[0] = element;
			++brElemenata;
		}
		else {
			
			int brojac = 0;
			int i = 0;
			int zadnjiPrazan = -1;
			while (brojac <= brElemenata) {

				while (niz[i++] == nullptr) {
					zadnjiPrazan = i-1;
				};
				int j = i - 1;

				if (element <= *niz[j]) {

					// proveri da l desno ima mesta
					int ri = j;
					bool imaDesno = false;
					for (; ri < kapacitet && !imaDesno; ++ri)
						if (niz[ri] == nullptr)
							imaDesno = true;
					ri--;
					if (imaDesno) {
						niz[ri] = new int;
						for (int k = ri; k > j; --k)
							*niz[k] = *niz[k - 1];
						*niz[j] = element;
						++brElemenata;
						break;
					}
					else {
						niz[zadnjiPrazan] = new int;
						int k;
						for (k = zadnjiPrazan; k < j; ++k)
							*niz[k] = *niz[k + 1];
						*niz[j-1] = element;
						++brElemenata;
						break;
					}
				}
				else {
					
					bool svePrazna = 1;
					for (int k = j + 1; k < kapacitet && svePrazna; ++k)
						if (niz[k] != nullptr)
							svePrazna = 0;
					if (svePrazna && j+1 < kapacitet) {
						niz[j + 1] = new int;
						*niz[j + 1] = element;
						++brElemenata;
						break;
					}
					else if (j+1 == kapacitet) {
						niz[zadnjiPrazan] = new int;
						int k;
						for (k = zadnjiPrazan; k < j; ++k)
							*niz[k] = *niz[k + 1];
						*niz[j] = element;
						++brElemenata;
						break;
					}
					
				}

				++brojac;
			}
		}
	}
}

void OrderedBuffer::pop()
{
	int pola;
	if (brElemenata % 2 == 0)
		pola = brElemenata / 2;
	else 
		pola = brElemenata / 2+1;

	int brojac = 0;
	int i = 0;
	for (; i < kapacitet; ++i)
	{
		if (niz[i] != nullptr)
			++brojac;
		
		if (brojac == pola)
			break;
	}

	delete niz[i];
	niz[i] = nullptr;
	brElemenata--;

}
