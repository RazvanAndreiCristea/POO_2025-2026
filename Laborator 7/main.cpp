#include "VectorHelper.h"

int main()
{
    int nrSticle = 5;
    Sticla* sticle = new Sticla[nrSticle];

    sticle[0] = Sticla(0.5f, "metal", 5.5, "Dorna", Dop(25, "pluta"));
    sticle[1] = Sticla(1.5f, "sticla", 4.5, "Borsec", Dop(28, "plastic"));
    sticle[2] = Sticla(2.0f, "metal", 6.0, "Aqua Carpatica", Dop(32, "cauciuc"));
    sticle[3] = Sticla(5.5f, "plastic", 3.8, "Izvorul Minunilor", Dop(24, "silicon"));
    sticle[4] = Sticla(11.5f, "sticla", 15.2, "Zizin", Dop(30, "lemn"));

    VectorHelper::afisareSticle(sticle, nrSticle);
    VectorHelper::sortareSticle(sticle, nrSticle);

    std::cout << "===================================== Dupa sortarea sticlelor =====================================\n\n";

    VectorHelper::afisareSticle(sticle, nrSticle);
    delete[] sticle;
    return 0;
}