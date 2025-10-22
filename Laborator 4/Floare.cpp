#include "Floare.h"

Floare::Floare()
{
    pret = 0.0f;
    culoare = nullptr;
    denumire = nullptr;
}

Floare::Floare(const float& pret, const char* culoare, const char* denumire)
{
    this->pret = pret;

    if (culoare != nullptr)
    {
        this->culoare = new char[strlen(culoare) + 1];
        strcpy(this->culoare, culoare);
    }
    else
    {
        this->culoare = nullptr;
    }

    if (denumire != nullptr)
    {
        this->denumire = new char[strlen(denumire) + 1];
        strcpy(this->denumire, denumire);
    }
    else
    {
        this->denumire = nullptr;
    }
}

Floare::Floare(const Floare& floare)
{
    pret = floare.pret;

    if (floare.culoare != nullptr)
    {
        culoare = new char[strlen(floare.culoare) + 1];
        strcpy(culoare, floare.culoare);
    }
    else
    {
        culoare = nullptr;
    }

    if (floare.denumire != nullptr)
    {
        denumire = new char[strlen(floare.denumire) + 1];
        strcpy(denumire, floare.denumire);
    }
    else
    {
        denumire = nullptr;
    }
}

Floare& Floare::operator=(const Floare& floare)
{
    if (this == &floare)
    {
        return *this;
    }

    if (denumire != nullptr)
    {
        delete[] denumire;
        denumire = nullptr;
    }

    if (culoare != nullptr)
    {
        delete[] culoare;
        culoare = nullptr;
    }

    pret = floare.pret;

    if (floare.culoare != nullptr)
    {
        culoare = new char[strlen(floare.culoare) + 1];
        strcpy(culoare, floare.culoare);
    }
    else
    {
        culoare = nullptr;
    }

    if (floare.denumire != nullptr)
    {
        denumire = new char[strlen(floare.denumire) + 1];
        strcpy(denumire, floare.denumire);
    }
    else
    {
        denumire = nullptr;
    }

    return *this;
}

Floare::~Floare()
{
    if (denumire != nullptr)
    {
        delete[] denumire;
        denumire = nullptr;
    }

    if (culoare != nullptr)
    {
        delete[] culoare;
        culoare = nullptr;
    }
}

void Floare::afisare() const
{
    std::cout << "Pretul florii este: " << pret << " euro\n";
    std::cout << "Denumirea florii este: ";

    if (denumire != nullptr)
    {
        std::cout << denumire << '\n';
    }
    else
    {
        std::cout << "N/A\n";
    }

    std::cout << "Culoarea florii este: ";

    if (culoare != nullptr)
    {
        std::cout << culoare << "\n\n";
    }
    else
    {
        std::cout << "N/A\n\n";
    }
}

const float Floare::getPret() const
{
    return pret;
}

const char* Floare::getCuloare() const
{
    return culoare;
}

const char* Floare::getDenumire() const
{
    return denumire;
}

void Floare::setPret(const float& pret)
{
    if (pret <= 0.0f)
    {
        return;
    }

    this->pret = pret;
}

void Floare::setCuloare(const char* culoare)
{
    if (culoare == nullptr)
    {
        return;
    }

    if (this->culoare != nullptr)
    {
        delete[] this->culoare;
        this->culoare = nullptr;
    }

    this->culoare = new char[strlen(culoare) + 1];
    strcpy(this->culoare, culoare);
}

void Floare::setDenumire(const char* denumire)
{
    if (denumire == nullptr)
    {
        return;
    }

    if (this->denumire != nullptr)
    {
        delete[] this->denumire;
        this->denumire = nullptr;
    }

    this->denumire = new char[strlen(denumire) + 1];
    strcpy(this->denumire, denumire);
}