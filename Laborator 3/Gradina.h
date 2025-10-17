#pragma once
#include <iostream>

class Gradina
{
    float pret;
    double suprafata;
    int numarGradinari;

public:

    Gradina();
    Gradina(const float& pret, const int& numarGradinari);
    Gradina(const float& pret, const double& suprafata, const int& numarGradinari);

    const float getPret() const;
    const double getSuprafata() const;
    const int getNumarGradinari() const;

    void setPret(const float& pret);
    void setSuprafata(const double& suprafata);
    void setNumarGradinari(const int& numarGradinari);
};