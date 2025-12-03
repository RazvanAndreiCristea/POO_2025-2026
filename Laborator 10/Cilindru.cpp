#include "Cilindru.h"

void Cilindru::afisare(std::ostream& out) const
{
    out << "Valoarea razei cilindrului este: " << raza << " cm\n";
    out << "Valoarea generatoarei cilindrului este: " << generatoare << " cm\n";
    out << "Culoarea cilindrului este: ";

    if (culoare == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << culoare << '\n';
    }
}

Cilindru::Cilindru(const float& raza, const float& generatoare, const char* culoare)
{
    this->raza = raza;
    this->generatoare = generatoare;
    this->culoare = copiazaString(culoare);
}

Cilindru::~Cilindru()
{
    if (culoare != nullptr)
    {
        delete[] culoare;
        culoare = nullptr;
    }
}

float Cilindru::getVolum() const
{
    return M_PI * pow(raza, 2) * generatoare;
}

float Cilindru::getAriaBazei() const
{
    return M_PI * pow(raza, 2);
}

float Cilindru::getAriaTotala() const
{
    return 2 * M_PI * raza * (raza + generatoare);
}

float Cilindru::getAriaLaterala() const
{
    return 2 * M_PI * raza * generatoare;
}

char* Cilindru::getCuloare() const
{
    return culoare;
}

TipCorp Cilindru::getTipCorp() const
{
    return TipCorp::kCILINDRU;
}