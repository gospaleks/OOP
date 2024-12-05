#pragma once
#include "IspitniMaterijal.h"
class Zadatak :
    public IspitniMaterijal
{
private:
    int linije;

public:
    Zadatak();
    Zadatak(int oznaka, double tezina, int linije);
    Zadatak(const Zadatak& z);
    ~Zadatak();

    float vratiVreme(int vreme);

    void stampaj(ostream& izlaz);
};

