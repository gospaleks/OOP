#pragma once
class Command
{
private:
	char* title;
	char* value;
protected:
	char* getTitle() { return title; }
	char* getValue() { return value; }
public:
	Command();
	Command(char* t, char* v);
	virtual ~Command();
	virtual void execute();
};

