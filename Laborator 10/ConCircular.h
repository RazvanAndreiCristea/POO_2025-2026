#pragma once
#include "CorpGeometric.h"

class Con : public CorpGeometric
{
    float raza;
    float inaltime;
    float generatoare;
    char* culoare;

protected:

    void afisare(std::ostream& out) const override;

public:

    Con(const float& raza, const float& inaltime, const float& generatoare, const char* culoare);
    ~Con();

    float getVolum() const override;
    float getAriaBazei() const override;
    float getAriaTotala() const override;
    float getAriaLaterala() const override;

    char* getCuloare() const override;
    TipCorp getTipCorp() const override;
};