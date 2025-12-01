#include "Motocicleta.h"

void Motocicleta::afisare(std::ostream& out) const
{
    Vehicul::afisare(out);

    out << "Capacitatea cilindrica a motorului motocicletei este: " << capacitateCilindrica << " cm^3\n";
    out << "Tara de fabricare a motocicletei este: ";

    if (taraFabricare == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << taraFabricare << '\n';
    }
}

Motocicleta::Motocicleta(const char* marca, const int& anFabricare, const char* taraFabricare, const int& capacitateCilindrica) : Vehicul(marca, anFabricare)
{
    this->capacitateCilindrica = capacitateCilindrica;
    this->taraFabricare = copiazaString(taraFabricare);
}

Motocicleta::~Motocicleta()
{
    if (taraFabricare != nullptr)
    {
        delete[] taraFabricare;
        taraFabricare = nullptr;
    }
}

double Motocicleta::getImpozit() const
{
    return (double)capacitateCilindrica / 200 * 8;
}