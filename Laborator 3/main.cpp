#include "Gradina.h"

int main()
{
    Gradina g1;
    Gradina g2(250000.0f, 4);
    Gradina g3(500000.0f, 6000.0, 4);

    std::cout << "Pretul gradinii este: " << g1.getPret() << " euro\n";
    std::cout << "Suprafata gradinii este: " << g1.getSuprafata() << " ha\n";
    std::cout << "Numarul de gradinari este: " << g1.getNumarGradinari() << "\n\n";

    std::cout << "Pretul gradinii este: " << g2.getPret() << " euro\n";
    std::cout << "Suprafata gradinii este: " << g2.getSuprafata() << " ha\n";
    std::cout << "Numarul de gradinari este: " << g2.getNumarGradinari() << "\n\n";

    std::cout << "Pretul gradinii este: " << g3.getPret() << " euro\n";
    std::cout << "Suprafata gradinii este: " << g3.getSuprafata() << " ha\n";
    std::cout << "Numarul de gradinari este: " << g3.getNumarGradinari() << "\n\n";

    g1.setPret(100000.0f);
    g1.setSuprafata(2000.0);
    g1.setNumarGradinari(1);

    std::cout << "Pretul gradinii este: " << g1.getPret() << " euro\n";
    std::cout << "Suprafata gradinii este: " << g1.getSuprafata() << " ha\n";
    std::cout << "Numarul de gradinari este: " << g1.getNumarGradinari() << '\n';

    return 0;
}