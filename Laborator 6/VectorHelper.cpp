#include "VectorHelper.h"

void alocareSabii(Sabie*& sabii, const int& nrSabii)
{
    if (nrSabii <= 0)
    {
        return;
    }

    sabii = new Sabie[nrSabii];
}

void dezalocareSabii(Sabie*& sabii)
{
    if (sabii == nullptr)
    {
        return;
    }

    delete[] sabii;
    sabii = nullptr;
}

void interschimbareSabii(Sabie& s1, Sabie& s2)
{
    Sabie aux = s1;
    s1 = s2;
    s2 = aux;
}

void sortareSabii(Sabie*& sabii, const int& nrSabii)
{
    if (sabii == nullptr || nrSabii <= 0)
    {
        return;
    }

    for (int i = 0; i < nrSabii - 1; i++)
    {
        for (int j = i + 1; j < nrSabii; j++)
        {
            if (sabii[i] < sabii[j])
            {
                interschimbareSabii(sabii[i], sabii[j]);
            }
        }
    }
}

void afisareSabii(const Sabie* const& sabii, const int& nrSabii)
{
    if (sabii == nullptr || nrSabii <= 0)
    {
        return;
    }

    for (int i = 0; i < nrSabii; i++)
    {
        std::cout << sabii[i] << '\n';
    }
}