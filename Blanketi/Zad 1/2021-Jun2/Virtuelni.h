#pragma once
#include "Posetilac.h"
#include <iostream>
#include <fstream>
using namespace std;

class Virtuelni :
    public Posetilac
{
private:
    char* korisnicno_ime;
    int cena, b_sati, b_komentara;
public:
    Virtuelni();
    Virtuelni(int bt, char* ime, char* prezime, char* k_ime, int br_sati, int br_komentara);
    void prikazi(ostream& izlaz);
};

