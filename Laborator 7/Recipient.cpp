#include "Recipient.h"

Recipient::Recipient()
{
    volum = 0.0f;
    material = nullptr;
}

Recipient::Recipient(const float& volum, const char* material)
{
    this->volum = volum;
    this->material = copiazaString(material);
}

Recipient::Recipient(const Recipient& recipient)
{
    volum = recipient.volum;
    material = copiazaString(recipient.material);
}

Recipient& Recipient::operator=(const Recipient& recipient)
{
    if (this == &recipient)
    {
        return *this;
    }

    if (material != nullptr)
    {
        delete[] material;
        material = nullptr;
    }

    volum = recipient.volum;
    material = copiazaString(recipient.material);

    return *this;
}

Recipient::~Recipient()
{
    if (material != nullptr)
    {
        delete[] material;
        material = nullptr;
    }
}

std::ostream& operator<<(std::ostream& out, const Recipient& recipient)
{
    out << "Volumul recipientului este: " << recipient.volum << " litri\n";
    out << "Materialul de confectionare al recipientului este: ";

    if (recipient.material == nullptr)
    {
        out << "N/A\n";
    }
    else
    {
        out << recipient.material << '\n';
    }

    return out;
}