#include "Paragraf2.h"
#include <fstream>
#include <string.h>
using namespace std;
void Paragraf2::prikazi(ostream& izlaz)
{
	for (int i = strlen(p)-1; i >= 0; i--)
	{
		izlaz << p[i];
	}
	// izlaz << endl;
}
