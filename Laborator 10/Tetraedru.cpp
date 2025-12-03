#include "Tetraedru.h"

void Tetraedru::afisare(std::ostream& out) const
{
    out << "Lungimea muchiei tetraedrului este: " << latura << " cm\n";
    out << "Culoarea tetraedrului este: ";

    if (culoare == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << culoare << '\n';
    }
}

Tetraedru::Tetraedru(const float& latura, const char* culoare)
{
    this->latura = latura;
    this->culoare = copiazaString(culoare);
}

Tetraedru::~Tetraedru()
{
    if (culoare != nullptr)
    {
        delete[] culoare;
        culoare = nullptr;
    }
}

float Tetraedru::getVolum() const
{
    return pow(latura, 3) * sqrt(2) / 12;
}

float Tetraedru::getAriaBazei() const
{
    return pow(latura, 2) * sqrt(3) / 4;
}

float Tetraedru::getAriaTotala() const
{
    return pow(latura, 2) * sqrt(3);
}

float Tetraedru::getAriaLaterala() const
{
    return 3 * pow(latura, 2) * sqrt(3) / 4;
}

char* Tetraedru::getCuloare() const
{
    return culoare;
}

TipCorp Tetraedru::getTipCorp() const
{
    return TipCorp::kTETRAEDRU_REGULAT;
}