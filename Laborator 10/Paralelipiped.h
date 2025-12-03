#pragma once
#include "CorpGeometric.h"

class Paralelipiped : public CorpGeometric
{
    float latime;
    float lungime;
    float inaltime;
    char* culoare;

protected:

    void afisare(std::ostream& out) const override;

public:

    Paralelipiped(const float& latime, const float& lungime, const float& inaltime, const char* culoare);
    ~Paralelipiped();

    float getVolum() const override;
    float getAriaBazei() const override;
    float getAriaTotala() const override;
    float getAriaLaterala() const override;

    char* getCuloare() const override;
    TipCorp getTipCorp() const override;
};