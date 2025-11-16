#include "Sticla.h"

Sticla::Sticla() : Recipient(), Produs()
{

}

Sticla::Sticla(const float& volum, const char* material, const double& pret, const char* producator, const Dop& dop) : Recipient(volum, material), Produs(pret, producator)
{
    this->dop = dop;
}

Sticla::Sticla(const Sticla& sticla) : Recipient(sticla), Produs(sticla), dop(sticla.dop)
{

}

Sticla& Sticla::operator=(const Sticla& sticla)
{
    if (this == &sticla)
    {
        return *this;
    }

    Produs::operator=(sticla);
    Recipient::operator=(sticla);

    dop = sticla.dop.esteInvalid() ? Dop() : sticla.dop;

    return *this;
}

bool Sticla::operator>(const Sticla& sticla) const
{
    return dop.getDiametru() > sticla.dop.getDiametru();
}

std::ostream& operator<<(std::ostream& out, const Sticla& sticla)
{
    if (sticla.dop.esteInvalid())
    {
        out << "Sticla nu are dop\n";
    }
    else
    {
        out << sticla.dop;
    }

    out << (Produs&)sticla;
    out << (Recipient&)sticla;

    return out;
}