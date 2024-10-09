#pragma once
class Minesweeper
{
private:
	bool** matrica;
	char* nazivPolja;
	int n;
	int m;
public:
	Minesweeper();
	Minesweeper(int n, int m);
	~Minesweeper();
	inline int vratiN() { return n; }
	inline int vratiM() { return m; }
	int vratiBrmina(int x, int y);
	void ucitajRaspored();
	void prikazi();
	void izbaci();
};

