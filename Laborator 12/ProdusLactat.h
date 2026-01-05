#pragma once
#include "ProdusAmbalat.h"
#include "ProdusPasteurizat.h"

class ProdusLactat : public ProdusAmbalat, public ProdusPasteurizat
{
    double pret; // per suta de grame
    double cantitate;

protected:

    void afisare(std::ostream& out) const override;

public:

    ProdusLactat(const double& pret, const double& calorii, const char* producator, const char* tipAmbalaj, const double& costAmbalare,
        const char* tipPasteurizare, const double& costPasteurizare, const double& pretLactat, const double& cantitate);

    double getPret() const override;
};