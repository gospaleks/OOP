#include <iostream>
#include "Student.h"
#include "Skup.h"
using namespace std;

void main()
{

	
	
	try {
		Skup<int> skupInt(10);
		//int x1 = 1, x2 = 2, x3 = 3;
		//skupInt.dodaj(x1);
		//skupInt.dodaj(x2);
		//skupInt.dodaj(x3);

		//cout << skupInt;
		//skupInt.sortiraj(2);
		//cout << skupInt;

		//Skup<int> skupInt1(10);
		//skupInt1.dodaj(x2);
		//skupInt1.dodaj(x3);
		//Skup<int> skupInt2;
		//skupInt2 = (skupInt * skupInt1); // ovo je presek
		//cout << skupInt2;
		//
		//cin >> skupStudent;

		//cout << skupStudent;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}

	try
	{
		Skup<Student> skupStudent(10);
		Student* s1 = new Student("1234", "Pera", "Peric", 7.4);
		Student* s2 = new Student("1243", "Mira", "Miric", 8.4);
		Student* s3 = new Student("6734", "Jova", "Jovic", 6.4);
		Student* s4 = new Student("1214", "nzm", "nzmic", 9.4);
		skupStudent.dodaj(*s1);
		skupStudent.dodaj(*s2);
		skupStudent.dodaj(*s3);
		skupStudent.dodaj(*s4);

		cout << skupStudent;
		/*skupStudent.sortiraj(1);
		cout << skupStudent;*/
		Skup<Student> SkupStudent1(10);
		SkupStudent1.dodaj(*s1);
		SkupStudent1.dodaj(*s3);
		Skup<Student> SkupStudent2(10);
		SkupStudent2 = skupStudent * SkupStudent1;
		cout << SkupStudent2;

	}
	catch (const char* s)
	{
		cout << s << endl;
	}
}