#include "Sabie.h"

Sabie::Sabie() : Arma()
{
    lungime = 0;
    tipLama = nullptr;
}

Sabie::Sabie(const double& pret, const char* material, const int& lungime, const char* tipLama) : Arma(pret, material)
{
    this->lungime = lungime;
    this->tipLama = copiazaString(tipLama);
}

Sabie::Sabie(const Sabie& sabie) : Arma(sabie)
{
    lungime = sabie.lungime;
    tipLama = copiazaString(sabie.tipLama);
}

Sabie& Sabie::operator=(const Sabie& sabie)
{
    if (this == &sabie)
    {
        return *this;
    }

    (Arma&)(*this) = sabie;

    if (tipLama != nullptr)
    {
        delete[] tipLama;
        tipLama = nullptr;
    }

    lungime = sabie.lungime;
    tipLama = copiazaString(sabie.tipLama);

    return *this;
}

Sabie::~Sabie()
{
    if (tipLama != nullptr)
    {
        delete[] tipLama;
        tipLama = nullptr;
    }
}

int Sabie::getLungime() const
{
    return lungime;
}

const char* Sabie::getTipLama() const
{
    return tipLama;
}

bool Sabie::operator<(const Sabie& sabie) const
{
    return lungime < sabie.lungime;
}

std::ostream& operator<<(std::ostream& out, const Sabie& sabie)
{
    out << (Arma&)sabie;

    out << "Lungimea sabiei este: " << sabie.lungime << " cm\n";
    out << "Tipul lamei este: ";

    if (sabie.tipLama == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << sabie.tipLama << '\n';
    }

    return out;
}