#include "Paralelipiped.h"

void Paralelipiped::afisare(std::ostream& out) const
{
    out << "Valoarea lungimii paralelipipedului este: " << lungime << " cm\n";
    out << "Valoarea latimii paralelipipedului este: " << lungime << " cm\n";
    out << "Valoarea inaltimii paralelipipedului este: " << lungime << " cm\n";
    out << "Culoarea paralelipipedului este: ";

    if (culoare == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << culoare << '\n';
    }
}

Paralelipiped::Paralelipiped(const float& latime, const float& lungime, const float& inaltime, const char* culoare)
{
    this->latime = latime;
    this->lungime = lungime;
    this->inaltime = inaltime;
    this->culoare = copiazaString(culoare);
}

Paralelipiped::~Paralelipiped()
{
    if (culoare != nullptr)
    {
        delete[] culoare;
        culoare = nullptr;
    }
}

float Paralelipiped::getVolum() const
{
    return lungime * latime * inaltime;
}

float Paralelipiped::getAriaBazei() const
{
    return lungime * latime;
}

float Paralelipiped::getAriaTotala() const
{
    return 2 * (lungime * latime + lungime * inaltime + latime * inaltime);
}

float Paralelipiped::getAriaLaterala() const
{
    return 2 * (lungime + latime) * inaltime;
}

char* Paralelipiped::getCuloare() const
{
    return culoare;
}

TipCorp Paralelipiped::getTipCorp() const
{
    return TipCorp::kPARALELIPIPED;
}