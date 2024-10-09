#pragma once
#include "FileSystemElement.h"
class File :  public FileSystemElement
{

public:
	File();
	File(char* iime, char* eext);
	virtual ~File();
	virtual char* vratiPunoIme();
	virtual void PrintList();
	virtual bool daLiJeFajl() { return true; }
};

