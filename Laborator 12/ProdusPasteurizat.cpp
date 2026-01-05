#include "ProdusPasteurizat.h"

void ProdusPasteurizat::afisare(std::ostream& out) const
{
    ProdusAlimentar::afisare(out);
    afisareProprie(out);
    out << "Pretul total al produsului pasteurizat este: " << getPret() << " ron\n";
}

void ProdusPasteurizat::afisareProprie(std::ostream& out) const
{
    out << "Costul de pasteurizare este: " << costPasteurizare << " ron\n";
    out << "Tipul de pasteurizare este: ";

    if (tipPasteurizare == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << tipPasteurizare << '\n';
    }
}

ProdusPasteurizat::ProdusPasteurizat(const double& pret, const double& calorii, const char* producator, const char* tipPasteurizare, const double& costPasteurizare)
    : ProdusAlimentar(pret, calorii, producator)
{
    this->costPasteurizare = costPasteurizare;
    this->tipPasteurizare = copiazaString(tipPasteurizare);
}

ProdusPasteurizat::~ProdusPasteurizat()
{
    delete[] tipPasteurizare;
    tipPasteurizare = nullptr;
}

double ProdusPasteurizat::getPret() const
{
    return ProdusAlimentar::getPret() + costPasteurizare;
}