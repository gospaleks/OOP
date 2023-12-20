#include "Osa.h"
#include "Polje.h"
#include<iostream>
using namespace std;

Osa::Osa(Polje* pp, int rr, int kk) 
	: Entitet('o', 80, pp, rr, kk) {
}

void Osa::dobro()
{
	energija += 25;
}

void Osa::lose()
{
	for (int i = r - 1; i <= r + 1; i++)
		for (int j = k - 1; j <= k + 1; j++)
			if (t->daLiPripada(i, j) && !(i == r && j == k))
				if (t->vratiIJ(i,j) != nullptr)
					t->vratiIJ(i, j)->smanji(45);
}
