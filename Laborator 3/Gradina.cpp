#include "Gradina.h"

Gradina::Gradina()
{
    pret = 0.0f;
    suprafata = 0.0;
    numarGradinari = 0;
}

Gradina::Gradina(const float& pret, const int& numarGradinari)
{
    suprafata = 100.0;
    this->pret = pret;
    this->numarGradinari = numarGradinari;
}

Gradina::Gradina(const float& pret, const double& suprafata, const int& numarGradinari)
{
    this->pret = pret;
    this->suprafata = suprafata;
    this->numarGradinari = numarGradinari;
}

const float Gradina::getPret() const
{
    return pret;
}

const double Gradina::getSuprafata() const
{
    return suprafata;
}

const int Gradina::getNumarGradinari() const
{
    return numarGradinari;
}

void Gradina::setPret(const float& pret)
{
    if (pret <= 0.0f)
    {
        return;
    }

    this->pret = pret;
}

void Gradina::setSuprafata(const double& suprafata)
{
    if (suprafata <= 0.0)
    {
        return;
    }

    this->suprafata = suprafata;
}

void Gradina::setNumarGradinari(const int& numarGradinari)
{
    if (numarGradinari < 0)
    {
        return;
    }

    this->numarGradinari = numarGradinari;
}