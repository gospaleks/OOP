#pragma once
class Displej
{
protected:
	int cifra;
public:
	Displej();
	Displej(int ccifra);
	virtual void set(int ccifra);
	void reset();
	virtual void inc();
	virtual void show();
};

