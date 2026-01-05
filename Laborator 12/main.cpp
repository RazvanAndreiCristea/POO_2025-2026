#include "ProdusLactat.h"

int main()
{
    int nrAlimente = 10;
    ProdusAlimentar** alimente = new ProdusAlimentar * [nrAlimente];

    alimente[0] = new ProdusAmbalat(10.0, 250.0, "Napolact", "Plastic", 1.5);
    alimente[1] = new ProdusPasteurizat(8.0, 200.0, "Albalact", "HTST", 0.8);
    alimente[2] = new ProdusLactat(12.0, 300.0, "Danone", "Carton", 2.0, "UHT", 1.2, 4.5, 500.0);
    alimente[3] = new ProdusAmbalat(6.5, 180.0, "Olympus", "Folie", 1.0);
    alimente[4] = new ProdusPasteurizat(7.0, 220.0, "Covalact", "LTLT", 0.6);
    alimente[5] = new ProdusLactat(15.0, 350.0, "Solomonescu", "Plastic", 2.5, "UHT", 1.5, 6.0, 1000.0);
    alimente[6] = new ProdusAmbalat(5.0, 150.0, "Zuzu", "Punga", 0.7);
    alimente[7] = new ProdusPasteurizat(9.0, 270.0, "Muller", "HTST", 1.1);
    alimente[8] = new ProdusLactat(18.0, 400.0, "Camara Noastra", "Sticla", 3.0, "UHT", 2.0, 7.2, 750.0);
    alimente[9] = new ProdusAmbalat(4.5, 120.0, "Pilos", "Carton", 0.5);

    for (int i = 0; i < nrAlimente; i++)
    {
        std::cout << alimente[i] << "\n";
    }

    for (int i = 0; i < nrAlimente - 1; i++)
    {
        for (int j = i + 1; j < nrAlimente; j++)
        {
            if (alimente[i]->getPret() < alimente[j]->getPret())
            {
                ProdusAlimentar* aliment = alimente[i];
                alimente[i] = alimente[j];
                alimente[j] = aliment;
            }
        }
    }

    std::cout << "============================================= Dupa sortare ============================================\n\n";

    for (int i = 0; i < nrAlimente; i++)
    {
        std::cout << alimente[i] << "\n";
    }

    for (int i = 0; i < nrAlimente; i++)
    {
        delete alimente[i];
    }

    delete[] alimente;

    return 0;
}