#pragma once
#include "IspitniMaterijal.h"
class Lekcija :
    public IspitniMaterijal
{
private:
    double stranice;

public:
    Lekcija();
    Lekcija(int oznaka, double tezina, double stranice);
    Lekcija(const Lekcija& l);
    ~Lekcija();

    float vratiVreme(int vreme);

    void stampaj(ostream& izlaz);
};

