#pragma once
#include <iostream>
#include "StringHelper.h"

class Dop
{
    float diametru;
    char* material;

public:

    Dop();
    Dop(const float& diametru, const char* material);
    Dop(const Dop& dop);
    Dop& operator=(const Dop& dop);
    ~Dop();

    bool esteInvalid() const;
    float getDiametru() const;

    friend std::ostream& operator<<(std::ostream& out, const Dop& dop);
};