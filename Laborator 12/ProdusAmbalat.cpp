#include "ProdusAmbalat.h"

void ProdusAmbalat::afisare(std::ostream& out) const
{
    ProdusAlimentar::afisare(out);
    afisareProprie(out);
    out << "Pretul total al produsului ambalat este: " << getPret() << " ron\n";
}

void ProdusAmbalat::afisareProprie(std::ostream& out) const
{
    out << "Costul de ambalare este: " << costAmbalare << " ron\n";
    out << "Tipul de ambalaj este: ";

    if (tipAmbalaj == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << tipAmbalaj << '\n';
    }
}

ProdusAmbalat::ProdusAmbalat(const double& pret, const double& calorii, const char* producator, const char* tipAmbalaj, const double& costAmbalare)
    : ProdusAlimentar(pret, calorii, producator)
{
    this->costAmbalare = costAmbalare;
    this->tipAmbalaj = copiazaString(tipAmbalaj);
}

ProdusAmbalat::~ProdusAmbalat()
{
    delete[] tipAmbalaj;
    tipAmbalaj = nullptr;
}

double ProdusAmbalat::getPret() const
{
    return ProdusAlimentar::getPret() + costAmbalare;
}