#pragma once
#include "Process.h"
class PrivateProcess : public Process
{
private:
	char* code;
public:
	PrivateProcess();
	PrivateProcess(char* ccode, int ssifra);
	virtual ~PrivateProcess();
	virtual void start(char* ccode);
	virtual void stop();
	virtual void prikazi();
};

