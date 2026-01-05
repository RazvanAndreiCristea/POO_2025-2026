#include "ProdusLactat.h"

void ProdusLactat::afisare(std::ostream& out) const
{
    ProdusAlimentar::afisare(out);
    ProdusAmbalat::afisareProprie(out);
    ProdusPasteurizat::afisareProprie(out);

    out << "Pretul total al produsului lactat este: " << getPret() << " ron\n";
}

ProdusLactat::ProdusLactat(const double& pret, const double& calorii, const char* producator, const char* tipAmbalaj, const double& costAmbalare,
    const char* tipPasteurizare, const double& costPasteurizare, const double& pretLactat, const double& cantitate)
    : ProdusAlimentar(pret, calorii, producator),
    ProdusAmbalat(pret, calorii, producator, tipAmbalaj, costAmbalare),
    ProdusPasteurizat(pret, calorii, producator, tipPasteurizare, costPasteurizare)
{
    this->pret = pretLactat;
    this->cantitate = cantitate;
}

double ProdusLactat::getPret() const
{
    return pret * cantitate + ProdusAmbalat::getPret() + ProdusPasteurizat::getPret() - ProdusAlimentar::getPret();
}