#pragma once
#include <cstring>
#include <iostream>
#pragma warning (disable : 4996)

class Floare
{
    float pret;
    char* culoare;
    char* denumire;

public:

    Floare();
    Floare(const float& pret, const char* culoare, const char* denumire);
    Floare(const Floare& floare);
    Floare& operator=(const Floare& floare);
    ~Floare();

    void afisare() const;

    const float getPret() const;
    const char* getCuloare() const;
    const char* getDenumire() const;

    void setPret(const float& pret);
    void setCuloare(const char* culoare);
    void setDenumire(const char* denumire);
};