#include "Activity.h"
#include <iomanip>
Activity::Activity()
	: Step(nullptr, (char*)"Activity") {
	obavezna = 0;
}

Activity::Activity(char* nnaziv, int o)
	: Step(nnaziv, (char*)"Activity"), obavezna(o) {
}

Activity::~Activity()
{
}

void Activity::Prikazi(ostream& izlaz)
{
	Step::Prikazi(izlaz);
	izlaz << setw(3) << GetSpecAttribute() << endl;
}

istream& operator>>(istream& ulaz, Activity& a)
{
	return ulaz >> a.obavezna;
}
