#include "Dop.h"

Dop::Dop()
{
    diametru = 0.0f;
    material = nullptr;
}

Dop::Dop(const float& diametru, const char* material)
{
    this->diametru = diametru;
    this->material = copiazaString(material);
}

Dop::Dop(const Dop& dop)
{
    diametru = dop.diametru;
    material = copiazaString(dop.material);
}

Dop& Dop::operator=(const Dop& dop)
{
    if (this == &dop)
    {
        return *this;
    }

    if (material != nullptr)
    {
        delete[] material;
        material = nullptr;
    }

    diametru = dop.diametru;
    material = copiazaString(dop.material);

    return *this;
}

Dop::~Dop()
{
    if (material != nullptr)
    {
        delete[] material;
        material = nullptr;
    }
}

bool Dop::esteInvalid() const
{
    return diametru <= 0.0f || material == nullptr;
}

float Dop::getDiametru() const
{
    return diametru;
}

std::ostream& operator<<(std::ostream& out, const Dop& dop)
{
    out << "Diametrul dopului este: " << dop.diametru << "mm\n";
    out << "Materialul de confectionare al dopului este: ";

    if (dop.material == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << dop.material << '\n';
    }

    return out;
}