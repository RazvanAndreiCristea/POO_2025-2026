#pragma once
#include <iostream>
#include "StringHelper.h"

class Vehicul
{
    char* marca;
    int anFabricare;

protected:

    virtual void afisare(std::ostream& out) const;

public:

    Vehicul(const char* marca, const int& anFabricare);
    virtual ~Vehicul();

    virtual double getImpozit() const = 0;
    friend std::ostream& operator<<(std::ostream& out, const Vehicul* const& vehicul);
};