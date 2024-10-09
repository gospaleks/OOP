#pragma once
#include <fstream>
using namespace std;
class Image
{
private:
	int n;
	int** mat;
	char* lokacija;
public:
	Image();
	Image(int duzina);
	~Image();
	Image(const Image& mat);
	inline int vratiDimenziju()
	{
		return n;
	}
	void invertuj();
	void ucitaj();
	void ispisi();
	void odsecanje(int novaDimenzija);
	void oslobodiMemoriju();
	void zauzmiMemoriju(int dimenzija);
	void kopiraj(const Image& img);
	Image& preklopi(Image& img2);
	void rotiraj();
	Image& operator=(const Image& img);
	friend istream& operator>>(istream& ulaz, Image& img);
	friend ostream& operator<<(ostream& izlaz, Image& img);
};

