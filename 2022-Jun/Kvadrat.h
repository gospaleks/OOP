#pragma once
#include "Figura.h"
#include <fstream>
using namespace std;

class Kvadrat :
    public Figura
{
private:
    float duzinaStranice;
public:
    Kvadrat();
    Kvadrat(float duzina, float x, float y);
    float vratiP() { return pow(duzinaStranice, 2); }
    float vratiO() { return (4 * duzinaStranice); }
    float getsirina() { return duzinaStranice; }
    float getvisina() { return duzinaStranice; }
    void ispisi(ostream& izlaz);
    void upisi(istream& ulaz);
};

