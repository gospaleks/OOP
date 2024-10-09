#pragma once
class RobaKes
{
protected:
	int kod, sifra, dan, cena, popust;
	float cenasapopustom;
	bool rate;
public:
	RobaKes();
	RobaKes(int kkod, int ssifra, int ddan, int ccena, int ppopust);
	int getkod() { return kod; }
	bool getrate() { return rate; }
	int getsifra() { return sifra; }
	int getdan() { return dan; }
	int getcena() { return cena; }
	int getpopust() { return popust; }
	float getcenasapopustom() { return cenasapopustom; }
	virtual int getsvotaplacena() { return 0; }
	virtual int getbrojrata() { return 0; }
	virtual int getbrojdana() { return 0; }
	virtual int getbrojplacenih() { return 0; }
	virtual float getplacenodosad() { return 0; }
	virtual void prikazi();
};

