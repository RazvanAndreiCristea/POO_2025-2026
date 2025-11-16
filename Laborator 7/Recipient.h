#pragma once
#include <iostream>
#include "StringHelper.h"

class Recipient
{
    float volum;
    char* material;

public:

    Recipient();
    Recipient(const float& volum, const char* material);
    Recipient(const Recipient& recipient);
    Recipient& operator=(const Recipient& recipient);
    ~Recipient();

    friend std::ostream& operator<<(std::ostream& out, const Recipient& recipient);
};