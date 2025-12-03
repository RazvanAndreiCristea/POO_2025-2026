#pragma once
#include "Paralelipiped.h"

class Cub : public Paralelipiped
{
    float latura;

protected:

    void afisare(std::ostream& out) const override;

public:

    Cub(const float& latura, const char* culoare);
    TipCorp getTipCorp() const override;
};