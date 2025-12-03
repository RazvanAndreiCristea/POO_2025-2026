#pragma once
#include "CorpGeometric.h"

class Cilindru : public CorpGeometric
{
    float raza;
    float generatoare;
    char* culoare;

protected:

    void afisare(std::ostream& out) const override;

public:

    Cilindru(const float& raza, const float& generatoare, const char* culoare);
    ~Cilindru();

    float getVolum() const override;
    float getAriaBazei() const override;
    float getAriaTotala() const override;
    float getAriaLaterala() const override;

    char* getCuloare() const override;
    TipCorp getTipCorp() const override;
};