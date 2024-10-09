#pragma once
#include "RobaKes.h"
class RobaRate :
    public RobaKes
{
private:
    int svotaplacena, brojrata, brojdana, brojplacenih;
    float placenodosad;
public:
    RobaRate();
    RobaRate(int kkod, int ssifra, int ddan, int ccena, int popust, int ssvota, int brata, int bdana, int bplacenih);
    int getsvotaplacena() { return svotaplacena; }
    int getbrojrata() { return brojrata; }
    int getbrojdana() { return brojdana; }
    int getbrojplacenih() { return brojplacenih; }
    float getplacenodosad() { return placenodosad; }
    void prikazi();
};

