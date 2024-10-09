#include "State.h"
#include <iomanip>
State::State()
	: Step(nullptr, (char*)"State") {
	prioritet = 0;
}

State::State(char* nnaziv, int p)
	: Step(nnaziv, (char*)"State"), prioritet(p) {
}

State::~State()
{
}

void State::Prikazi(ostream& izlaz)
{
	Step::Prikazi(izlaz);
	izlaz << setw(3) << GetSpecAttribute() << endl;
}

istream& operator>>(istream& ulaz, State& s)
{
	return ulaz >> s.prioritet;
}
