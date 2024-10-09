#include "CommandHistory.h"
#include "Draw.h"
#include "Save.h"
#include "Print.h"
#include <iostream>

#define MAXSIZE 2019

CommandHistory::CommandHistory()
{
	vektor = new Command * [MAXSIZE];
	trBr = 0;
}

CommandHistory::~CommandHistory()
{
	for (int i = 0; i < trBr; ++i)
		delete vektor[i];
	delete[] vektor;
}

void CommandHistory::undo()
{
	if (trBr > 0)
	{
		trBr--;
		delete vektor[trBr];
	}
}

void CommandHistory::create(int x, char * vvalue)
{
	if (trBr == MAXSIZE) {
		delete vektor[0];
		for (int i = 0; i < trBr-1; ++i)
			vektor[i] = vektor[i + 1];
		trBr--;
	}

	if (x == 1)
		vektor[trBr++] = new Draw(vvalue);
	else if (x == 2)
		vektor[trBr++] = new Save(vvalue);
	else if (x == 3)
		vektor[trBr++] = new Draw(vvalue);
}

void CommandHistory::execute()
{
	if (trBr > 0) {
		vektor[trBr - 1]->execute();
	}
}

void CommandHistory::showHistory()
{
	std::cout << "-----------------------\n";
	for (int i = 0; i < trBr; ++i)
		vektor[i]->execute();
	std::cout << "-----------------------\n";
}
