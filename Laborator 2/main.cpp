#include "NrComplex.h"

int main()
{
    NrComplex z1;
    NrComplex z2;

    z1.real = -1; z1.imaginar = 2;
    z2.real = 9;  z2.imaginar = 6;

    afisareNumarComplex(adunareNumereComplexe(z1, z2));
    afisareNumarComplex(diferentaNumereComplexe(z1, z2));
    afisareNumarComplex(inmultireNumereComplexe(z1, z2));
    std::cout << "Modulul sumei este: " << getModulNrComplex(adunareNumereComplexe(z1, z2)) << "\n\n";

    int dimensiune = 5;
    NrComplex* numereComplexe = nullptr;

    alocareVector(numereComplexe, dimensiune);

    numereComplexe[0].real = 1;  numereComplexe[0].imaginar = 1;  // |z| = √2 ~ 1.41
    numereComplexe[1].real = 2;  numereComplexe[1].imaginar = -1; // |z| = √5 ~ 2.23
    numereComplexe[2].real = -3; numereComplexe[2].imaginar = 2;  // |z| = √13 ~ 3.60
    numereComplexe[3].real = 0;  numereComplexe[3].imaginar = 4;  // |z| = 4
    numereComplexe[4].real = 5;  numereComplexe[4].imaginar = -2; // |z| = √29 ~ 5.38

    afisareVector(numereComplexe, dimensiune);
    sortareVector(numereComplexe, dimensiune);

    std::cout << "============================= Dupa sortarea descrescatoare =============================\n\n";

    afisareVector(numereComplexe, dimensiune);
    eliberareVector(numereComplexe);

    return 0;
}