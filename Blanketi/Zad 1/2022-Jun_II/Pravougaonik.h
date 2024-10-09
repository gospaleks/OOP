#pragma once
#include "Figura.h"
#include <fstream>
using namespace std;

class Pravougaonik :
    public Figura
{
private:
    float visina, sirina;
public:
    Pravougaonik();
    Pravougaonik(float vvisina, float ssirina, float xx, float yy);
    float vratiP() { return (visina * sirina); }
    float vratiO() { return (2 * visina + 2 * sirina); }
    float getsirina() { return sirina; }
    float getvisina() { return visina; }
    void ispisi(ostream& izlaz);
    void upisi(istream& ulaz);
};

