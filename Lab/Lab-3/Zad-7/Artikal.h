#pragma once
class Artikal
{
private:
	char* naziv;
	double cena;
public:
	Artikal();
	Artikal(char* naziv, double ccena);
	virtual ~Artikal();
	
	virtual void showDescription();
	double getPrice() { return cena; }
};

