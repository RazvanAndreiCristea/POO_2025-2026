#pragma once
#include "CorpGeometric.h"

class Sfera : public CorpGeometric
{
    float raza;
    char* culoare;

protected:

    void afisare(std::ostream& out) const override;

public:

    Sfera(const float& raza, const char* culoare);
    ~Sfera();

    float getVolum() const override;
    float getAriaBazei() const override;
    float getAriaTotala() const override;
    float getAriaLaterala() const override;

    char* getCuloare() const override;
    TipCorp getTipCorp() const override;
};