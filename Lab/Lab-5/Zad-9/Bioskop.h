#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
template <class Tip, int n, int m>
class Bioskop
{
private:
	Tip** mat;
public:
	Bioskop()
	{
		mat = new Tip * [n];
		for (int i = 0; i < n; i++)
			mat[i] = new Tip[m];
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				mat[i][j] = *(new Tip());
	}

	~Bioskop()
	{
		if(mat != nullptr)
		{
			for (int i = 0; i < n; i++)
				if (mat[i] != nullptr)
					delete[] mat[i];
			delete[] mat;
		}
	}

	float prosekGodina()
	{
		float prosek = 0;
		int br = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (mat[i][j].getPrisutan())
				{
					br++;
					prosek += mat[i][j].getStarost();
				}
		return prosek / br;
	}

	float prosekOcene()
	{
		float prosek = 0;
		int br = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (mat[i][j].getPrisutan())
				{
					br++;
					prosek += mat[i][j].getOcena();
				}
		return prosek / br;
	}

	Tip& operator()(int i, int j) { return mat[i][j]; }

	void ispis() {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << mat[i][j] << "\t";
			cout << endl;
		}
	}

};
