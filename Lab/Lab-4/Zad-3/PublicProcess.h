#pragma once
#include "Process.h"
class PublicProcess : public Process
{
private:
	char* creatorName;
public:
	PublicProcess();
	PublicProcess(char* ccreatorName, int ssifra);
	virtual ~PublicProcess();
	virtual void start(char* userName);
	virtual void stop();
	virtual void prikazi();
};

