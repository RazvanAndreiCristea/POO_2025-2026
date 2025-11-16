#include "Produs.h"

Produs::Produs()
{
    pret = 0.0;
    producator = nullptr;
}

Produs::Produs(const double& pret, const char* producator)
{
    this->pret = pret;
    this->producator = copiazaString(producator);
}

Produs::Produs(const Produs& produs)
{
    pret = produs.pret;
    producator = copiazaString(produs.producator);
}

Produs& Produs::operator=(const Produs& produs)
{
    if (this == &produs)
    {
        return *this;
    }

    if (producator != nullptr)
    {
        delete[] producator;
        producator = nullptr;
    }

    pret = produs.pret;
    producator = copiazaString(produs.producator);

    return *this;
}

Produs::~Produs()
{
    if (producator != nullptr)
    {
        delete[] producator;
        producator = nullptr;
    }
}

std::ostream& operator<<(std::ostream& out, const Produs& produs)
{
    out << "Pretul produsului este: " << produs.pret << " ron\n";
    out << "Producatorul produsului este: ";

    if (produs.producator == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << produs.producator << '\n';
    }

    return out;
}