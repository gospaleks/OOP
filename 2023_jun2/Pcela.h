#pragma once
#include "Entitet.h"
#include "Polje.h"
#define pi 3.14159265359

class Polje;

class Pcela : public Entitet
{
public:
    Pcela(Polje* pp, int rr, int kk);
    void dobro();
    void lose();
};

