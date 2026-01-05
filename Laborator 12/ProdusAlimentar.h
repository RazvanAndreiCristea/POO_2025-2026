#pragma once
#include <iostream>
#include "StringHelper.h"

class ProdusAlimentar
{
    double pret;
    double calorii;
    char* producator;

protected:

    virtual void afisare(std::ostream& out) const;

public:

    ProdusAlimentar(const double& pret, const double& calorii, const char* producator);
    virtual ~ProdusAlimentar();

    virtual double getPret() const;
    friend std::ostream& operator<<(std::ostream& out, const ProdusAlimentar* const& produsAlimentar);
};