#include "FileSystemElement.h"
#include<string.h>
FileSystemElement::FileSystemElement()
{
	ime = nullptr;
	ext = nullptr;
	rod = nullptr;
}

FileSystemElement::FileSystemElement(char* iime, char* eext)
{
	ime = new char[strlen(iime) + 1];
	strcpy(ime, iime);
	ext = new char[strlen(eext) + 1];
	strcpy(ext, eext);
	rod = nullptr;
}

FileSystemElement::~FileSystemElement()
{
	if (ime != nullptr)
		delete[] ime;
	if (ext != nullptr)
		delete[] ext;
}

void FileSystemElement::postaviRod(FileSystemElement* r)
{
	rod = r;
}



