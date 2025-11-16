#pragma once
#include <iostream>
#include "StringHelper.h"

class Produs
{
    double pret;
    char* producator;

public:

    Produs();
    Produs(const double& pret, const char* producator);
    Produs(const Produs& produs);
    Produs& operator=(const Produs& produs);
    ~Produs();

    friend std::ostream& operator<<(std::ostream& out, const Produs& produs);
};