#pragma once
#include "Polje.h"
#include "Entitet.h"
#define pi 3.14159265359

class Polje;

class Osa : public Entitet
{
public:
    Osa(Polje* pp, int rr, int kk);
    void dobro();
    void lose();
};

