#pragma once
#include "CorpGeometric.h"

class Tetraedru : public CorpGeometric
{
    float latura;
    char* culoare;

protected:

    void afisare(std::ostream& out) const override;

public:

    Tetraedru(const float& latura, const char* culoare);
    ~Tetraedru();

    float getVolum() const override;
    float getAriaBazei() const override;
    float getAriaTotala() const override;
    float getAriaLaterala() const override;

    char* getCuloare() const override;
    TipCorp getTipCorp() const override;
};