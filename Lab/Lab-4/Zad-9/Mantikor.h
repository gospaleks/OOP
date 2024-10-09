#pragma once
#include "Protivnik.h"
#include <fstream>
using namespace std;
class Mantikor :
    public Protivnik
{
private:
    double I, K, O, U;
public:
    Mantikor() : Protivnik((char*)"mantikor", 0, 0) { I = K = O = U = 0; }
    Mantikor(double ii, double kk, double oo, double uu);
    virtual ~Mantikor();
    virtual void output(ostream& izlaz);
};

