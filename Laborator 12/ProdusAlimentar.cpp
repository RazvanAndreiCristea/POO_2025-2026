#include "ProdusAlimentar.h"

void ProdusAlimentar::afisare(std::ostream& out) const
{
    out << "Pretul de baza al produsului alimentar este: " << pret << " ron\n";
    out << "Numarul de calorii al produsului alimentar este: " << calorii << '\n';
    out << "Denumirea producatorului este: ";

    if (producator == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << producator << '\n';
    }
}

ProdusAlimentar::ProdusAlimentar(const double& pret, const double& calorii, const char* producator)
{
    this->pret = pret;
    this->calorii = calorii;
    this->producator = copiazaString(producator);
}

ProdusAlimentar::~ProdusAlimentar()
{
    delete[] producator;
    producator = nullptr;
}

double ProdusAlimentar::getPret() const
{
    return pret;
}

std::ostream& operator<<(std::ostream& out, const ProdusAlimentar* const& produsAlimentar)
{
    produsAlimentar->afisare(out);
    return out;
}