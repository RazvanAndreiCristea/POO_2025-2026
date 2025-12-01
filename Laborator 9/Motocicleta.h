#pragma once
#include "Vehicul.h"

class Motocicleta : public Vehicul
{
    char* taraFabricare;
    int capacitateCilindrica;

protected:

    virtual void afisare(std::ostream& out) const override;

public:

    Motocicleta(const char* marca, const int& anFabricare, const char* taraFabricare, const int& capacitateCilindrica);
    ~Motocicleta();

    double getImpozit() const override;
};