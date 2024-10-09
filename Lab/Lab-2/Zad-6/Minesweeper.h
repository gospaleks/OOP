#pragma once
#include <fstream>
using namespace std;
class Minesweeper
{
private:
	bool** matrica;
	char* nazivPolja;
	int n;
	int m;

	void oslobodiMemoriju();
	void zauzmiMemoriju(int nn, int mm);
	void kopiraj(Minesweeper& obj);
public:
	Minesweeper();
	Minesweeper(int n, int m);
	Minesweeper(Minesweeper& obj);
	~Minesweeper();
	inline int vratiN() { return n; }
	inline int vratiM() { return m; }
	int vratiBrmina(int x, int y);
	void ucitajRaspored();
	void prikazi();
	void izbaci();


	// ZA LAB2
	void rotDesno();
	void rotLevo();
	void rotGore();
	void rotDole();
	void zameniNtoPolje(int nn);
	friend istream& operator>>(istream& ulaz, Minesweeper& m);
	friend ostream& operator<<(ostream& izlaz , Minesweeper& m);
};

