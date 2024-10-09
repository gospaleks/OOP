#pragma once
class Picture
{
private:
	int n, m;
	int** mat;
public:
	Picture();
	~Picture();
	Picture(int visina, int sirina);
	inline void vratiDim(int *nn, int*mm) {
		*nn = this->n;
		*mm = this->m;
	}
	void Brihtness(int s);
	void ucitaj();
	void ispisi();
	void resize(int newN, int newM);
};

