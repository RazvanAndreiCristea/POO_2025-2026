#include "Cub.h"

void Cub::afisare(std::ostream& out) const
{
    out << "Latura cubului este de: " << latura << " cm\n";
    out << "Culoarea cubului este: ";

    if (Paralelipiped::getCuloare() == nullptr) // se apeleaza direct getter-ul din superclasa
    {
        out << "N/A\n";
    }
    else
    {
        out << Paralelipiped::getCuloare() << '\n';
    }
}

Cub::Cub(const float& latura, const char* culoare) : Paralelipiped(latura, latura, latura, culoare)
{
    this->latura = latura;
}

TipCorp Cub::getTipCorp() const
{
    return TipCorp::kCUB;
}