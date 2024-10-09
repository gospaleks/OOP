#pragma once
class FileSystemElement
{
protected:
	char* ime;
	char* ext;
	FileSystemElement* rod;
public:
	FileSystemElement();
	FileSystemElement(char* iime, char* eext);
	virtual ~FileSystemElement();
	void postaviRod(FileSystemElement* r);
	virtual char* vratiPunoIme() = 0;
	virtual void PrintList() = 0;
	virtual bool daLiJeFajl() = 0;
};

