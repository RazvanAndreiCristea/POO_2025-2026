#pragma once
#include <cmath>
#include <iostream>

struct NrComplex
{
    double real;
    double imaginar;
};

NrComplex adunareNumereComplexe(const NrComplex& z1, const NrComplex& z2);

NrComplex diferentaNumereComplexe(const NrComplex& z1, const NrComplex& z2);

NrComplex inmultireNumereComplexe(const NrComplex& z1, const NrComplex& z2);

double getModulNrComplex(const NrComplex& z);

void afisareNumarComplex(const NrComplex& z);

void alocareVector(NrComplex*& vector, const int& dimensiune);

void sortareVector(NrComplex*& vector, const int& dimensiune);

void afisareVector(const NrComplex* const& vector, const int& dimensiune);

void eliberareVector(NrComplex*& vector);