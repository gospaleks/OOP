#pragma once
#include <fstream>
#include <iostream>

class IzlozbeniPosetioci
{
private:
	int brOdr;
	int brSkol;
	int brDece;
public:
	IzlozbeniPosetioci();
	IzlozbeniPosetioci(int brO, int brS, int brD);
	~IzlozbeniPosetioci();

	friend std::ostream& operator<<(std::ostream& izlaz, IzlozbeniPosetioci& r);
	friend std::istream& operator>>(std::istream& ulaz, IzlozbeniPosetioci& r);
	int operator+(int x);
	bool operator<(IzlozbeniPosetioci& r);
};

