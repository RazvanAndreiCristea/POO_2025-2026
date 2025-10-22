#include "SortingHelper.h"

void interschimbareFlori(Floare& f1, Floare& f2)
{
    Floare aux = f1;
    f1 = f2;
    f2 = aux;
}

void sortareFlori(Floare*& flori, const int& nrFlori)
{
    if (flori == nullptr || nrFlori <= 0)
    {
        return;
    }

    for (int i = 0; i < nrFlori - 1; i++)
    {
        for (int j = i + 1; j < nrFlori; j++)
        {
            if (strcmp(flori[i].getDenumire(), flori[j].getDenumire()) > 0)
            {
                interschimbareFlori(flori[i], flori[j]);
            }
        }
    }
}

void afisareFlori(const Floare* const& flori, const int& nrFlori)
{
    if (flori == nullptr || nrFlori <= 0)
    {
        return;
    }

    for (int i = 0; i < nrFlori; i++)
    {
        flori[i].afisare();
    }
}