#include "Masina.h"
#include "Motocicleta.h"

int main()
{
    Vehicul* masina = new Masina("Dacia", 2025, "alba", 2000);
    Vehicul* motocicleta = new Motocicleta("Zundapp", 1922, "Germania", 1000);

    std::cout << masina;
    std::cout << "Impozitul total al masinii este de: " << masina->getImpozit() << " ron/an\n\n";

    std::cout << motocicleta;
    std::cout << "Impozitul total al motocicletei este de: " << motocicleta->getImpozit() << " ron/an\n";

    delete masina;
    delete motocicleta;
    return 0;
}