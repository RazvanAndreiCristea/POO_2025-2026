#include "Sfera.h"

void Sfera::afisare(std::ostream& out) const
{
    out << "Valoarea razei sferei este: " << raza << " cm\n";
    out << "Culoarea sferei este: ";

    if (culoare == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << culoare << '\n';
    }
}

Sfera::Sfera(const float& raza, const char* culoare)
{
    this->raza = raza;
    this->culoare = copiazaString(culoare);
}

Sfera::~Sfera()
{
    if (culoare != nullptr)
    {
        delete[] culoare;
        culoare = nullptr;
    }
}

float Sfera::getVolum() const
{
    return 4 * M_PI * pow(raza, 3) / 3;
}

float Sfera::getAriaBazei() const
{
    return 0.0f;
}

float Sfera::getAriaTotala() const
{
    return 4 * M_PI * pow(raza, 2);
}

float Sfera::getAriaLaterala() const
{
    return 0.0f;
}

char* Sfera::getCuloare() const
{
    return culoare;
}

TipCorp Sfera::getTipCorp() const
{
    return TipCorp::kSFERA;
}