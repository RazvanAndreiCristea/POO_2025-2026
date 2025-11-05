#pragma once
#include "Arma.h"

class Sabie : public Arma
{
    int lungime;
    char* tipLama;

public:

    Sabie();
    Sabie(const double& pret, const char* material, const int& lungime, const char* tipLama);
    Sabie(const Sabie& sabie);
    Sabie& operator=(const Sabie& sabie);
    ~Sabie();

    int getLungime() const;
    const char* getTipLama() const;

    bool operator<(const Sabie& sabie) const;
    friend std::ostream& operator<<(std::ostream& out, const Sabie& sabie);
};