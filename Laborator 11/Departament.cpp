#include "Departament.h"

Departament::Departament() : id(0)
{

}

Departament::Departament(const int& id, const std::string& denumire) : id(id)
{
    this->denumire = denumire;
}

Departament& Departament::operator=(const Departament& departament)
{
    if (this == &departament)
    {
        return *this;
    }

    denumire = departament.denumire;
    return *this;
}

const std::string Departament::getDenumire() const
{
    return denumire;
}

bool Departament::operator<(const Departament& departament) const
{
    return denumire < departament.denumire;
}

std::ostream& operator<<(std::ostream& out, const Departament& departament)
{
    out << "Id-ul departamentului este: " << departament.id << '\n';
    out << "Denumirea departamentului este: " << departament.denumire << '\n';

    return out;
}