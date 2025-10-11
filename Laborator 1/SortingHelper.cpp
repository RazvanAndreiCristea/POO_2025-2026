#include "SortingHelper.h"

void interschimbare(int* x, int* y)
{
    if (x == NULL || y == NULL)
    {
        return;
    }

    int aux = *x;
    *x = *y;
    *y = aux;
}

void sortareVector(int* vector, int dimensiune)
{
    if (vector == NULL || dimensiune <= 0)
    {
        return;
    }

    for (int i = 0; i < dimensiune - 1; i++)
    {
        for (int j = i + 1; j < dimensiune; j++)
        {
            if (vector[i] > vector[j])
            {
                interschimbare(&vector[i], &vector[j]);
            }
        }
    }
}

void afisareVector(int* vector, int dimensiune)
{
    if (vector == NULL || dimensiune <= 0)
    {
        return;
    }

    std::cout << "Elementele din vector sunt: ";

    for (int i = 0; i < dimensiune; i++)
    {
        std::cout << vector[i] << ' ';
    }

    std::cout << '\n';
}