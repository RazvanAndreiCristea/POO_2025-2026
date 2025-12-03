#include "ConCircular.h"

void Con::afisare(std::ostream& out) const
{
    out << "Valoarea razei conului este: " << raza << " cm\n";
    out << "Valoarea inaltimii conului este: " << inaltime << " cm\n";
    out << "Valoarea generatoarei conului este: " << generatoare << " cm\n";
    out << "Culoarea conului este: ";

    if (culoare == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << culoare << '\n';
    }
}

Con::Con(const float& raza, const float& inaltime, const float& generatoare, const char* culoare)
{
    this->raza = raza;
    this->inaltime = inaltime;
    this->generatoare = generatoare;
    this->culoare = copiazaString(culoare);
}

Con::~Con()
{
    if (culoare != nullptr)
    {
        delete[] culoare;
        culoare = nullptr;
    }
}

float Con::getVolum() const
{
    return M_PI * pow(raza, 2) * inaltime / 3;
}

float Con::getAriaBazei() const
{
    return M_PI * pow(raza, 2);
}

float Con::getAriaTotala() const
{
    return M_PI * raza * (raza + generatoare);
}

float Con::getAriaLaterala() const
{
    return M_PI * raza * generatoare;
}

char* Con::getCuloare() const
{
    return culoare;
}

TipCorp Con::getTipCorp() const
{
    return TipCorp::kCON;
}