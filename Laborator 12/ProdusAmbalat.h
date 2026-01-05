#pragma once
#include "ProdusAlimentar.h"

class ProdusAmbalat : virtual public ProdusAlimentar
{
    char* tipAmbalaj;
    double costAmbalare;

protected:

    void afisareProprie(std::ostream& out) const;
    void afisare(std::ostream& out) const override;

public:

    ProdusAmbalat(const double& pret, const double& calorii, const char* producator, const char* tipAmbalaj, const double& costAmbalare);
    ~ProdusAmbalat();

    double getPret() const override;
};