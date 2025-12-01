#pragma once
#include "Vehicul.h"

class Masina : public Vehicul
{
    char* culoare;
    int capacitateCilindrica;

protected:

    virtual void afisare(std::ostream& out) const override;

public:

    Masina(const char* marca, const int& anFabricare, const char* culoare, const int& capacitateCilindrica);
    ~Masina();

    double getImpozit() const override;
};