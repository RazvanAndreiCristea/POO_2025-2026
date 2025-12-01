#pragma once
#include <cmath>
#include <iostream>

class NrComplex
{
    double real;
    double imaginar;

    double getModul() const;

public:

    NrComplex(const double& real = 0.0, const double& imaginar = 0.0);

    bool operator>(const NrComplex& z) const;
    friend std::ostream& operator<<(std::ostream& out, const NrComplex& z);
};