#include "Entitet.h"
#include "Osa.h"
#include "Pcela.h"
#include "Polje.h"
using namespace std;

void main() {

	ifstream ulaz("polje.txt");
	if (ulaz.good()) 
	{
		Polje p;
		p.ucitaj(ulaz);
		p.prikazi();
		p.sviDobro();
		cout << endl <<"svi dobro" << endl;
		p.prikazi();
		p.sviLose();
		cout << endl << "svi lose" << endl;
		p.prikazi();
		p.sviLose();
		p.prikazi();
		p.sviDobro();
		p.prikazi();
	}
}