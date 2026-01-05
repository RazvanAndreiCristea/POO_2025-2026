#pragma once
#include "ProdusAlimentar.h"

class ProdusPasteurizat : virtual public ProdusAlimentar
{
    char* tipPasteurizare;
    double costPasteurizare;

protected:

    void afisareProprie(std::ostream& out) const;
    void afisare(std::ostream& out) const override;

public:

    ProdusPasteurizat(const double& pret, const double& calorii, const char* producator, const char* tipPasteurizare, const double& costPasteurizare);
    ~ProdusPasteurizat();

    double getPret() const override;
};