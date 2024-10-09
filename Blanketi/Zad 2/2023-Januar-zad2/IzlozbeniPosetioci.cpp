#include "IzlozbeniPosetioci.h"

IzlozbeniPosetioci::IzlozbeniPosetioci()
{
	brOdr = brSkol = brDece = 0;
}

IzlozbeniPosetioci::IzlozbeniPosetioci(int brO, int brS, int brD)
	:brOdr(brO), brSkol(brS), brDece(brD) {
}

IzlozbeniPosetioci::~IzlozbeniPosetioci()
{
}

int IzlozbeniPosetioci::operator+(int x)
{
	return (brOdr + brDece + brSkol + x);
}

bool IzlozbeniPosetioci::operator<(IzlozbeniPosetioci& r)
{
	return ((this->brOdr + this->brSkol / 2) < (r.brOdr + r.brSkol / 2));
}

std::ostream& operator<<(std::ostream& izlaz, IzlozbeniPosetioci& r)
{
	return izlaz << r.brOdr << " " << r.brSkol << " " << r.brDece;
}

std::istream& operator>>(std::istream& ulaz, IzlozbeniPosetioci& r)
{
	return ulaz >> r.brOdr >> r.brSkol >> r.brDece;
}
