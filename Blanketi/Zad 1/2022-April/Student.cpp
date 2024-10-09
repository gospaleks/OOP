#include "Student.h"

Student::Student()
{
	brojInd = 0;
	bodoviLab = 0;
	bodoviUsmeni = 0;
}

Student::Student(int bbrojInde, int bbodoviLab, int bbodoviUsmeni)
{
	brojInd = bbrojInde;
	if (bbodoviLab > 20)
		bodoviLab = 20;
	else
		bodoviLab = bbodoviLab;
	if (bbodoviUsmeni > 40)
		bodoviUsmeni = 40;
	else
		bodoviUsmeni = bbodoviUsmeni;
}

Student::~Student()
{

}
