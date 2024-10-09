#include "String.h"

String::String()
{
	max = 0;
	niz = nullptr;
}

String::String(int max)
{
	this->max = max;
	niz = new char[max];
}

void String::input()
{
	for (int i = 0; i < max; i++)
		cin >> niz[i];
}

void String::output()
{
	cout << niz;
}

int String::podstring(char* p)
{
	bool nadjen = false;
	int i = 0;
	int j;
	int ind = 0;
	while (i < max && nadjen == false)
	{
		j = 0;
		while (j < strlen(p) && niz[i+j] == p[j])
		{
			j++;
		}
		if (j == strlen(p)) {
			nadjen = true;
			ind = i;
		}
		++i;
	}
	if (nadjen = true)
		return ind;
	else
		return -1;
}

