#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class Pod>
class Matrica
{
private:
	Pod** matrica;
	int n;
	int m;
public:
	Matrica() {
		ZauzmiProstor(12, 12);
	}
	
	Matrica(int nn, int mm) :n(nn), m(mm) {
		ZauzmiProstor(n, m);
	}

	~Matrica() {
		OslobodiMemoriju();
	}

	Matrica<Pod>& operator=(const Matrica<Pod>& desni) {
		if (this != &desni) {
			OslobodiMemoriju();
			ZauzmiProstor(desni.n, desni.m);
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					matrica[i][j] = desni.matrica[i][j];
		}
		return *this;
	}

	Pod GetElement(int x, int y) {
		if (x >= 0 && x < n && y >= 0 && y < m)
			return matrica[x][y];
		return matrica[0][0];		// ako se lose unese vrati prvi element
	}

	void SetElement(int x, int y, Pod newValue) {
		if (x >= 0 && x < n && y >= 0 && y < m)
			matrica[x][y] = newValue;
	}

	friend istream& operator>>(istream& ulaz, Matrica<Pod>& mat) {
		for (int i = 0; i < mat.n; i++)
			for (int j = 0; j < mat.m; j++)
				ulaz >> mat.matrica[i][j];

		return ulaz;
	}
	
	friend ostream& operator<<(ostream& izlaz, Matrica<Pod>& mat) {
		for (int i = 0; i < mat.n; i++)
		{
			for (int j = 0; j < mat.m; j++)
				izlaz << mat.matrica[i][j] << " ";
			izlaz << endl;
		}
		return izlaz;
	}

	int GetN() { return n; }
	int GetM() { return m; }

	Matrica<Pod> operator*(Matrica<Pod>& desni) {
		if (this->m == desni.n)
		{
			Matrica<Pod>* rez = new Matrica<Pod>(this->n, desni.m);
			for (int i = 0; i < rez->n; i++)
			{
				for (int j = 0; j < rez->m; j++)
				{
					rez->matrica[i][j] = (*new Pod());
					for (int l = 0; l < m; l++)
						rez->matrica[i][j] = rez->matrica[i][j] + (matrica[i][l] * desni.matrica[l][j]);
				}
			}
			return *rez;
		}
		return *(new Matrica<Pod>());
	}

	void ZauzmiProstor(int nn, int mm) {
		n = nn;
		m = mm;
		matrica = new Pod * [nn];
		for (int i = 0; i < nn; ++i)
			matrica[i] = new Pod[mm];
	}

	void OslobodiMemoriju() {
		if (matrica != nullptr) {
			for (int i = 0; i < n; ++i)
				delete[] matrica[i];
			delete [] matrica;
		}
	}
};

