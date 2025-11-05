#include "VectorHelper.h"

int main()
{
    Sabie sabie(99.99, "bronz", 85, "zimtata");

    std::cout << "Pretul sabiei este: " << sabie.getPret() << '\n';
    std::cout << "Tipul lamei este: " << sabie.getTipLama() << "\n\n";
    std::cout << sabie << '\n';

    int nrSabii = 5;
    Sabie* sabii = nullptr;

    alocareSabii(sabii, nrSabii);

    if (sabii == nullptr)
    {
        return 0;
    }

    sabii[0] = Sabie(149.99, "otel", 120, "dublu-taiata");
    sabii[1] = Sabie(599.99, "argint", 85, "zimtata");
    sabii[2] = Sabie(2449.99, "aur", 135, "curbata");
    sabii[3] = Sabie(79.99, "fier", 70, "simpla");
    sabii[4] = Sabie(199.99, "otel-damasc", 110, "katana");

    std::cout << "============================== Sabiile inainte de sortare ==============================\n\n";
    afisareSabii(sabii, nrSabii);
    std::cout << "============================== Sabiile dupa sortare ==============================\n\n";

    sortareSabii(sabii, nrSabii);
    afisareSabii(sabii, nrSabii);
    dezalocareSabii(sabii);

    return 0;
}