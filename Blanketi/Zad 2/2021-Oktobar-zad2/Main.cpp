#include <iostream>
#include "Skup.h"
#include "Student.h"

int main() {
	
	//int
	try {
		Skup<int> s1(5);
		for (int i = 0; i < 5; i++)
			s1.dodaj(i);

		cout << s1 << endl;

		s1.obrisi(2);

		cout << s1 << endl;

		Skup<int> s2(4);
		for (int i = 5; i < 9; i++)
			s2.dodaj(i);

		cout << s2 << endl;

		Skup<int> s3(2);

		s3 = s1 + s2;

		cout << s3 << endl;
	}
	catch(const char* poruka) {
		cout << poruka << endl;
	}

	//Student
	try {
		Skup<Student> s4(5);
		
		s4.dodaj(*(new Student("jovan","bogdanovic","juga",8.5)));
		
		s4.dodaj(*(new Student ("vojin", "jevtovic", "srki", 6.4)));

		cout << s4 << endl;

		s4.obrisi(1);

		cout << s4 << endl;

		Skup<Student> s5(5);
		
		s5.dodaj(*(new Student ("joca", "bogda", "juga", 8.5)));
		
		s5.dodaj(*(new Student ("voki", "jevta", "srki", 6.4)));

		cout << s5 << endl;

		Skup<Student> s6= s4 + s5;

		cout << s6 << endl;
	}
	catch (const char* poruka) {
		cout << poruka <<endl;
	}
}