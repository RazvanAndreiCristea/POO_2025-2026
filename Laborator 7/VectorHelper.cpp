#include "VectorHelper.h"

void VectorHelper::interschimbareSticle(Sticla& s1, Sticla& s2)
{
    Sticla aux = s1;
    s1 = s2;
    s2 = aux;
}

void VectorHelper::sortareSticle(Sticla*& sticle, const int& nrSticle)
{
    if (sticle == nullptr || nrSticle <= 0)
    {
        return;
    }

    for (int i = 0; i < nrSticle - 1; i++)
    {
        for (int j = i + 1; j < nrSticle; j++)
        {
            if (sticle[i] > sticle[j])
            {
                interschimbareSticle(sticle[i], sticle[j]);
            }
        }
    }
}

void VectorHelper::afisareSticle(Sticla*& sticle, const int& nrSticle)
{
    if (sticle == nullptr || nrSticle <= 0)
    {
        return;
    }

    for (int i = 0; i < nrSticle; i++)
    {
        std::cout << sticle[i] << '\n';
    }
}