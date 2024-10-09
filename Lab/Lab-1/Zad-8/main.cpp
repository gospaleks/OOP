#include"String.h"

void main()
{
	String s(10);
	s.input();
	char pomocni[100];
	cin >> pomocni;
	if (s.podstring(pomocni) != -1)
		cout << "nadjen";
	else
		cout << "nije nije nadjes";
}