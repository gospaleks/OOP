#pragma once
class Buffer
{
protected:
	int kapacitet;
	int brElemenata;
	int** niz;
public:
	Buffer();
	Buffer(int k);
	~Buffer();
	virtual void push(int k);
	virtual void pop();
	void testPop(int poz);
	virtual void clear();
	void obrisiMemoriju();
	void zauzmiMemoriju(int k);
	void ispisi();
	void ispisiBafer();
};

