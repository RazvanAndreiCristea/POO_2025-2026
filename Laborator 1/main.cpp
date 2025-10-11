#include "SortingHelper.h"

int main()
{
    int nrElemente = 10;
    int vector[10] = { -1, -8, 2, 0, 10, 4, 7, 9, 3, 5 };

    afisareVector(vector, nrElemente);
    sortareVector(vector, nrElemente);
    afisareVector(vector, nrElemente);

    return 0;
}