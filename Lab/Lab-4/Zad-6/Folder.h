#pragma once
#include "FileSystemElement.h"
class Folder : public FileSystemElement
{
private:
	int brTrEl;
	FileSystemElement* niz[2018];
public:
	Folder();
	Folder(char* iime);
	virtual ~Folder();
	virtual char* vratiPunoIme();
	virtual void PrintList();
	void dodaj(FileSystemElement* podEl);
	void ukloni(int index);
	virtual bool daLiJeFajl() { return false; }
};

