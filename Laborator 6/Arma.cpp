#include "Arma.h"

Arma::Arma()
{
    pret = 0.0;
    material = nullptr;
}

Arma::Arma(const double& pret, const char* material)
{
    this->pret = pret;
    this->material = copiazaString(material);
}

Arma::Arma(const Arma& arma)
{
    pret = arma.pret;
    material = copiazaString(arma.material);
}

Arma& Arma::operator=(const Arma& arma)
{
    if (this == &arma)
    {
        return *this;
    }

    if (material != nullptr)
    {
        delete[] material;
        material = nullptr;
    }

    pret = arma.pret;
    material = copiazaString(arma.material);

    return *this;
}

Arma::~Arma()
{
    if (material != nullptr)
    {
        delete[] material;
        material = nullptr;
    }
}

double Arma::getPret() const
{
    return pret;
}

const char* Arma::getMaterial() const
{
    return material;
}

std::ostream& operator<<(std::ostream& out, const Arma& arma)
{
    out << "Pretul armei este: " << arma.pret << " euro\n";
    out << "Materialul din care este confectionata arma este: ";

    if (arma.material == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << arma.material << '\n';
    }

    return out;
}