#pragma once
#include "Process.h"
class ProcessQueue
{
private:
	int brTrAkt;
	int brTrCek;
	int maxEl;
	Process** nizAktivni;
	Process** nizCekanje;
public:
	ProcessQueue();
	ProcessQueue(int mmaxEl);
	~ProcessQueue();
	void dodajProces(Process* p, int ako);
	void izbaci();
	void startuj(char* username, char* code);
	void stopiraj();
	void ispisi();
};

