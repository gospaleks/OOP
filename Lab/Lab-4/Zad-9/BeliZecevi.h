#pragma once
#include "Protivnik.h"
#include <fstream>
using namespace std;
class BeliZecevi :
    public Protivnik
{
private:
    double C, W;
public:
    BeliZecevi() : Protivnik((char*)"beliZec", 0, 0) { C = W = 0; }
    BeliZecevi(double cc, double ww);
    virtual ~BeliZecevi();
    virtual void output(ostream& izlaz);
};

