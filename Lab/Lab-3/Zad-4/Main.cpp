#include <iostream>
#include "CommandHistory.h"
using namespace std;

int main()
{
	CommandHistory* chistory = new CommandHistory();

	chistory->create(1, (char*)"krug");
	chistory->create(2, (char*)"fajl.txt");
	chistory->create(1, (char*)"kvadrat");
	chistory->create(3, (char*)"printam");
	chistory->create(2, (char*)"notepad.txt");
	chistory->create(1, (char*)"NOVI"); // brise se prvi
	// chistory->showHistory();
	chistory->execute();
	chistory->undo();

	chistory->showHistory();

	chistory->undo();
	chistory->execute();
	delete chistory;

	return 0;
}