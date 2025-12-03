#pragma once
#define _USE_MATH_DEFINES // necesara pentru a putea utiliza constantele matematice

#include <cmath>
#include <iostream>
#include "StringHelper.h"

enum TipCorp { kCUB, kCILINDRU, kCON, kSFERA, kTETRAEDRU_REGULAT, kPARALELIPIPED };

class CorpGeometric
{
protected:

    virtual void afisare(std::ostream& out) const = 0;

public:

    virtual ~CorpGeometric() = 0;

    virtual float getVolum() const = 0;
    virtual float getAriaBazei() const = 0;
    virtual float getAriaTotala() const = 0;
    virtual float getAriaLaterala() const = 0;

    virtual char* getCuloare() const = 0;
    virtual TipCorp getTipCorp() const = 0;

    bool operator>(const CorpGeometric& corpGeometric) const;
    friend std::ostream& operator<<(std::ostream& out, const CorpGeometric* const& corpGeometric);
};