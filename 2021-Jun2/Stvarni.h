#pragma once
#include "Posetilac.h"
#include <iostream>
#include <fstream>
using namespace std;

class Stvarni : public Posetilac
{
private:
    char* radni_status;
    int b_odgovora, popust;
public:
    Stvarni();
    Stvarni(int bt, char* ime, char* prezime, char* radni_status, int br_odgovora, int popust);
    void prikazi(ostream& izlaz);
};

