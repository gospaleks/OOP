#include <iostream>
#include "OrderedBuffer.h"
#include "QueueBuffer.h"
#include <time.h>
using namespace std;

void main()
{
	Buffer* b2 = new Buffer(50);
	Buffer* b1 = new QueueBuffer(50);
	Buffer* b3 = new OrderedBuffer(50);
	// treba se doda za svaki al me mrzi
	srand(time(0));
	for (int i = 0; i < 2018; ++i) {
		b1->push(rand() % 20+1);
		b1->push(rand() % 20+1);
		b1->pop();

		if (i % 100 == 0) {
			b1->ispisi();
		}

		if (i % 10 == 0) {
			b1->clear();
		}
	}

}