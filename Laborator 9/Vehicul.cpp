#include "Vehicul.h"

void Vehicul::afisare(std::ostream& out) const
{
    out << "Anul fabricarii vehiculului este: " << anFabricare << '\n';
    out << "Marca vehiculului este: ";

    if (marca == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << marca << '\n';
    }
}

Vehicul::Vehicul(const char* marca, const int& anFabricare)
{
    this->anFabricare = anFabricare;
    this->marca = copiazaString(marca);
}

Vehicul::~Vehicul()
{
    if (marca != nullptr)
    {
        delete[] marca;
        marca = nullptr;
    }
}

std::ostream& operator<<(std::ostream& out, const Vehicul* const& vehicul)
{
    vehicul->afisare(out);
    return out;
}