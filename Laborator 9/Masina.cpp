#include "Masina.h"

void Masina::afisare(std::ostream& out) const
{
    Vehicul::afisare(out);

    out << "Capacitatea cilindrica a motorului masinii este: " << capacitateCilindrica << " cm^3\n";
    out << "Culoarea masinii este: ";

    if (culoare == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << culoare << '\n';
    }
}

Masina::Masina(const char* marca, const int& anFabricare, const char* culoare, const int& capacitateCilindrica) : Vehicul(marca, anFabricare)
{
    this->culoare = copiazaString(culoare);
    this->capacitateCilindrica = capacitateCilindrica;
}

Masina::~Masina()
{
    if (culoare != nullptr)
    {
        delete[] culoare;
        culoare = nullptr;
    }
}

double Masina::getImpozit() const
{
    return (double)capacitateCilindrica / 200 * 19;
}