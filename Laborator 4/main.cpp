#include "Floare.h"
#include "SortingHelper.h"

int main()
{
    Floare f1;
    Floare f2(5.5f, "rosie", "trandafir");

    f1.setPret(10.0f);
    f1.setCuloare("albastra");
    f1.setDenumire("hortensie");

    f1.afisare();
    f2.afisare();

    f1 = f2;
    f1.afisare();

    int nrFlori = 5;
    Floare* flori = new Floare[nrFlori];

    flori[0] = Floare(2.5f, "galbena", "lalea");
    flori[1] = Floare(4.5f, "roz", "crizantema");
    flori[2] = Floare(2.5f, "alb", "zambila");
    flori[3] = Floare(2.5f, "mov", "lavanda");
    flori[4] = Floare(2.5f, "rosu", "bujor");

    std::cout << "========================== Inainte de sortare ==========================\n\n";
    afisareFlori(flori, nrFlori);

    sortareFlori(flori, nrFlori);

    std::cout << "========================== Dupa sortare ==========================\n\n";
    afisareFlori(flori, nrFlori);

    delete[] flori;
    return 0;
}