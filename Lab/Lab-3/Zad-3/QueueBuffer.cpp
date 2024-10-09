#include "QueueBuffer.h"

QueueBuffer::QueueBuffer(void)
{
}

QueueBuffer::~QueueBuffer(void)
{
}

void QueueBuffer::push(int element)
{
	if (brElemenata < kapacitet) {
		for (int i = 0; i <= brElemenata; i++)
		{
			if (niz[i] == nullptr)
			{
				niz[i] = new int;
				*niz[i] = element;
				brElemenata++;
				break;
			}
		}
	}
	
}

void QueueBuffer::pop()
{
	if (brElemenata > 0)
	{
		if (brElemenata == 1)
		{
			int i = 0;
			while (niz[i++] == nullptr);
			delete niz[i];
		}
		else
		{
			int brojac = 0;
			int i;
			for (i = 0; i < kapacitet; ++i)
			{
				if (niz[i] != nullptr)
				{
					brojac++;
				}
				if (brojac == brElemenata - 1)
					break;
			}
			
			delete niz[i];
			niz[i] = nullptr;
		}
		brElemenata--;
	}
}
