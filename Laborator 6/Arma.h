#pragma once
#include <iostream>
#include "StringHelper.h"

class Arma
{
protected:

    double pret;
    char* material;

public:

    Arma();
    Arma(const double& pret, const char* material);
    Arma(const Arma& arma);
    Arma& operator=(const Arma& arma);
    ~Arma();

    double getPret() const;
    const char* getMaterial() const;

    friend std::ostream& operator<<(std::ostream& out, const Arma& arma);
};