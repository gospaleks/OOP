#pragma once
#include "Novcanica.h"

class NovcanicaDinar : public Novcanica
{
public:
	NovcanicaDinar(int vrednost);
	~NovcanicaDinar();

	bool operator==(const Novcanica& n) const;

	void Prikazi(std::ostream& izlaz) const override;
	inline double ukupnaVrednost() const override { return vrednost * brojNovcanica; }
};

