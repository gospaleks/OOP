#include "Paragraf1.h"
#include <fstream>
#include <string.h>
using namespace std;
void Paragraf1::prikazi(ostream& izlaz)
{
	for (int i = 0; i < strlen(p); ++i)
	{
		if (p[i] >= 'a' && p[i] <= 'z')
			izlaz << (char)(p[i] - 32);
		else if (p[i] >= 'A' && p[i] <= 'Z')
			izlaz << (char)(p[i] + 32);
		else izlaz << p[i];
	}
	// izlaz << endl;
}
