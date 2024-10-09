#pragma once
class Process
{
protected:
	int sifra;
	int stanje;
	int tip;
public:
	Process();
	virtual ~Process();
	Process(int ssifra, int ttip);
	inline int vratiSifru() {
		return sifra;
	}
	inline int vratiStanje() {
		return stanje;
	}
	inline int vratiTip() {
		return tip;
	}
	virtual void prikazi();
	virtual void start(char* parametar) = 0;
	virtual void stop() = 0;
};

