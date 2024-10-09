#include "PublicProcess.h"
#include <string.h>
#include <iostream>
using namespace std;
PublicProcess::PublicProcess()
	:Process() {
	tip = 0;
	creatorName = nullptr;
}

PublicProcess::PublicProcess(char* ccreatorName, int ssifra)
	:Process(ssifra, 0) {
	creatorName = new char[strlen(ccreatorName) + 1];
	strcpy(creatorName, ccreatorName);
}

PublicProcess::~PublicProcess()
{
	if (creatorName != nullptr)
		delete[] creatorName;
}

void PublicProcess::start(char* userName)
{
	if (strcmp(userName, creatorName) != 0)
	{
		delete[] creatorName;
		creatorName = new char[strlen(userName) + 1];
		strcpy(creatorName, userName);
		
	}
	stanje = 1;
}

void PublicProcess::stop()
{
	stanje = 2;
}

void PublicProcess::prikazi()
{
	cout <<  "PUBLIC - " << creatorName << ": ";
	Process::prikazi();
}


