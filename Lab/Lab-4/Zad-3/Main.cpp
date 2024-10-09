#include <iostream>
#include <fstream>
#include "ProcessQueue.h"
#include "PublicProcess.h"
#include "PrivateProcess.h"
using namespace std;

int main()
{
	ifstream ulaz("ulaz.txt");
	if (ulaz.good()) {
	
		int brojProcesa;
		ulaz >> brojProcesa;

		ProcessQueue* pq = new ProcessQueue(10);

		for (int i = 0; i < brojProcesa; ++i) {

			int public_private;
			int uKojiNiz;
			char left[100];
			int right;
			ulaz >> public_private;
			ulaz.get();
			ulaz >> left >> right >> uKojiNiz;

			if (public_private == 1) {
				pq->dodajProces((new PublicProcess(left, right)), uKojiNiz);
			}
			else if (public_private == 0) {
				pq->dodajProces((new PrivateProcess(left, right)), uKojiNiz);
			}
		}


		pq->ispisi();
		cout << endl << endl;

		pq->startuj((char*)"user1", (char*)"kod2");
		pq->ispisi();
		cout << endl;
		
		pq->stopiraj();
		pq->ispisi();
		cout << endl;

		pq->izbaci();
		pq->ispisi();

		ulaz.close();
	}



	return 0;
}