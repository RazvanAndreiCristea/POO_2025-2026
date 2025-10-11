#include "NrComplex.h"

NrComplex adunareNumereComplexe(const NrComplex& z1, const NrComplex& z2)
{
    NrComplex z;

    z.real = z1.real + z2.real;
    z.imaginar = z1.imaginar + z2.imaginar;

    return z;
}

NrComplex diferentaNumereComplexe(const NrComplex& z1, const NrComplex& z2)
{
    NrComplex z;

    z.real = z1.real - z2.real;
    z.imaginar = z1.imaginar - z2.imaginar;

    return z;
}

NrComplex inmultireNumereComplexe(const NrComplex& z1, const NrComplex& z2)
{
    NrComplex z;

    z.real = z1.real * z2.real - z1.imaginar * z2.imaginar;
    z.imaginar = z1.real * z2.imaginar + z2.real * z1.imaginar;

    return z;
}

double getModulNrComplex(const NrComplex& z)
{
    return sqrt(pow(z.real, 2) + pow(z.imaginar, 2));
}

void afisareNumarComplex(const NrComplex& z)
{
    std::cout << "Numarul complex este: " << z.real << " + " << z.imaginar << "j\n";
}

void alocareVector(NrComplex*& vector, const int& dimensiune)
{
    if (dimensiune <= 0)
    {
        return;
    }

    vector = new NrComplex[dimensiune];
}

void interschimbare(NrComplex& z1, NrComplex& z2)
{
    NrComplex aux = z1;
    z1 = z2;
    z2 = aux;
}

void sortareVector(NrComplex*& vector, const int& dimensiune)
{
    if (vector == nullptr || dimensiune <= 0)
    {
        return;
    }

    for (int i = 0; i < dimensiune - 1; i++)
    {
        for (int j = i + 1; j < dimensiune; j++)
        {
            if (getModulNrComplex(vector[i]) < getModulNrComplex(vector[j]))
            {
                interschimbare(vector[i], vector[j]);
            }
        }
    }
}

void afisareVector(const NrComplex* const& vector, const int& dimensiune)
{
    if (vector == nullptr || dimensiune <= 0)
    {
        return;
    }

    for (int i = 0; i < dimensiune; i++)
    {
        afisareNumarComplex(vector[i]);
    }

    std::cout << '\n';
}

void eliberareVector(NrComplex*& vector)
{
    if (vector == nullptr)
    {
        return;
    }

    delete[] vector;
    vector = nullptr;
}