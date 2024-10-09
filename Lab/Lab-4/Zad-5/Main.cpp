#include "Workflow.h"
#include "Activity.h"
#include "State.h"
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

int main()
{
	Workflow* w = new Workflow(2018);
	
	srand(time(0));

	int i = 0, x = 1;
	while (i < 2018) {
		char nazivAkt[20] = "Aktivnost_";
		char nazivSt[20] = "Stanje_";
		
		char tmp[5];
		sprintf(tmp, "%d", x++);

		strcat(nazivAkt, tmp);
		strcat(nazivSt, tmp);
		
		int obavezna, prioritet;
		obavezna = rand() % 2;
		prioritet = rand() % 100 + 1;

		w->InsertAt(new Activity(nazivAkt, obavezna), i++);
		w->InsertAt(new State(nazivSt, prioritet), i++);
	}



	//proba copy constructora
	Workflow *w2 = new Workflow(*w);
	//cout << "W2 isti kao W1(upotreba copy constructora):\n";
	//cout << *w2 << endl;
	

	//isprobavanje RemoveAt f-je
	for (i = 0; i < 2018; ++i)
	{
		if (i % 10 == 0)
			w->RemoveAt(i);
		if (i % 31 == 0)
			w->RemoveAt(i);
	}
	cout << "W1 SA IZBRISANIM ELEMENTIMA:\n";
	cout << *w << endl;


	// proba f-je GetSpecificSteps()
	int N;
	Step** koraciAktivnosti = w->GetSpecificSteps((char*)"Activity", &N);
	Workflow* w3 = new Workflow(N, koraciAktivnosti);
	//cout << "U W3 SMESTA SAMO ACTIVITY:\n";
	//cout << *w3 << endl;


	delete w;
	delete w2;
	delete w3;
	return 0;
}