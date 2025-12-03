#include "VectorHelper.h"

void interschimbareCorpuri(CorpGeometric*& c1, CorpGeometric*& c2)
{
    if (c1 == nullptr || c2 == nullptr)
    {
        return;
    }

    CorpGeometric* aux = c1;
    c1 = c2;
    c2 = aux;
}

void sortareCorpuri(CorpGeometric**& corpuri, const int& nrCorpuri)
{
    if (corpuri == nullptr || nrCorpuri <= 0)
    {
        return;
    }

    for (int i = 0; i < nrCorpuri - 1; i++)
    {
        for (int j = i + 1; j < nrCorpuri; j++)
        {
            if (*corpuri[i] > *corpuri[j])
            {
                interschimbareCorpuri(corpuri[i], corpuri[j]);
            }
        }
    }
}

void afisareCorpuri(const CorpGeometric* const* const& corpuri, const int& nrCorpuri)
{
    if (corpuri == nullptr || nrCorpuri <= 0)
    {
        return;
    }

    for (int i = 0; i < nrCorpuri; i++)
    {
        std::cout << corpuri[i];

        std::cout << "Corpul geometric are volumul egal cu: " << corpuri[i]->getVolum() << " cm^3\n";
        std::cout << "Corpul geometric are aria bazei egala cu: " << corpuri[i]->getAriaBazei() << " cm^2\n";
        std::cout << "Corpul geometric are aria laterala egala cu: " << corpuri[i]->getAriaLaterala() << " cm^2\n";
        std::cout << "Corpul geometric are aria totala egala cu: " << corpuri[i]->getAriaTotala() << " cm^2\n\n";
    }
}