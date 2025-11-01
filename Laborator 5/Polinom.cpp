#include "Polinom.h"

bool Polinom::esteInvalid() const
{
    return nrCoeficienti <= 0 || coeficienti == nullptr;
}

int Polinom::getNrMinimCoeficienti(const Polinom& p) const
{
    return (this->nrCoeficienti <= p.nrCoeficienti) ? this->nrCoeficienti : p.nrCoeficienti;
}

int Polinom::getNrMaximCoeficienti(const Polinom& p) const
{
    return (this->nrCoeficienti >= p.nrCoeficienti) ? this->nrCoeficienti : p.nrCoeficienti;
}

Polinom::Polinom(const int& nrCoeficienti /*= 0*/, const int* const& coeficienti /*= nullptr*/)
{
    if (nrCoeficienti <= 0 || coeficienti == nullptr)
    {
        this->nrCoeficienti = 0;
        this->coeficienti = nullptr;
        return;
    }

    this->nrCoeficienti = nrCoeficienti;

    for (int i = nrCoeficienti - 1; i >= 0; i--)
    {
        if (coeficienti[i] != 0)
        {
            break;
        }

        this->nrCoeficienti--;
    }

    if (this->nrCoeficienti == 0)
    {
        this->coeficienti = nullptr;
        return;
    }

    this->coeficienti = new int[this->nrCoeficienti];

    for (int i = 0; i < this->nrCoeficienti; i++)
    {
        this->coeficienti[i] = coeficienti[i];
    }
}

Polinom::Polinom(const Polinom& polinom)
{
    if (polinom.esteInvalid())
    {
        nrCoeficienti = 0;
        coeficienti = nullptr;
        return;
    }

    nrCoeficienti = polinom.nrCoeficienti;
    coeficienti = new int[nrCoeficienti];

    for (int i = 0; i < polinom.nrCoeficienti; i++)
    {
        coeficienti[i] = polinom.coeficienti[i];
    }
}

Polinom& Polinom::operator=(const Polinom& polinom)
{
    if (this == &polinom)
    {
        return *this;
    }

    if (polinom.esteInvalid())
    {
        nrCoeficienti = 0;
        coeficienti = nullptr;
        return *this;
    }

    if (coeficienti != nullptr)
    {
        delete[] coeficienti;
        coeficienti = nullptr;
    }

    nrCoeficienti = polinom.nrCoeficienti;
    coeficienti = new int[nrCoeficienti];

    for (int i = 0; i < polinom.nrCoeficienti; i++)
    {
        coeficienti[i] = polinom.coeficienti[i];
    }

    return *this;
}

Polinom::~Polinom()
{
    nrCoeficienti = 0;

    if (coeficienti != nullptr)
    {
        delete[] coeficienti;
        coeficienti = nullptr;
    }
}

const int Polinom::getGrad() const
{
    return nrCoeficienti - 1;
}

int& Polinom::operator[](const int& index)
{
    if (esteInvalid() || index < 0 || index >= nrCoeficienti)
    {
        std::cerr << "Index out of bounds\n\n";
        exit(1);
    }

    return coeficienti[index];
}

const int& Polinom::operator[](const int& index) const
{
    if (esteInvalid() || index < 0 || index >= nrCoeficienti)
    {
        std::cerr << "Index out of bounds\n\n";
        exit(1);
    }

    return coeficienti[index];
}

Polinom* Polinom::operator->()
{
    return this;
}

Polinom Polinom::operator-() const
{
    if (esteInvalid())
    {
        return Polinom();
    }

    Polinom opus = *this;

    for (int i = 0; i < nrCoeficienti; i++)
    {
        opus[i] *= -1;
    }

    return opus;
}

Polinom& Polinom::operator++()
{
    if (esteInvalid())
    {
        return *this;
    }

    coeficienti[0]++;
    return *this;
}

Polinom& Polinom::operator--()
{
    if (esteInvalid())
    {
        return *this;
    }

    coeficienti[0]--;
    return *this;
}

Polinom Polinom::operator++(int)
{
    if (esteInvalid())
    {
        return *this;
    }

    Polinom copie = *this;
    coeficienti[0]++;
    return copie;
}

Polinom Polinom::operator--(int)
{
    if (esteInvalid())
    {
        return *this;
    }

    Polinom copie = *this;
    coeficienti[0]--;
    return copie;
}

Polinom Polinom::operator+(const Polinom& polinom) const
{
    if (this->esteInvalid() || polinom.esteInvalid())
    {
        return Polinom();
    }

    int nrMinCoef = getNrMinimCoeficienti(polinom);
    int nrMaxCoef = getNrMaximCoeficienti(polinom);

    int* coefSuma = new int[nrMaxCoef] {0};

    for (int i = 0; i < nrMinCoef; i++)
    {
        coefSuma[i] = coeficienti[i] + polinom.coeficienti[i];
    }

    if (nrCoeficienti > polinom.nrCoeficienti)
    {
        for (int i = nrMinCoef; i < nrMaxCoef; i++)
        {
            coefSuma[i] = coeficienti[i];
        }
    }
    else
    {
        for (int i = nrMinCoef; i < nrMaxCoef; i++)
        {
            coefSuma[i] = polinom.coeficienti[i];
        }
    }

    Polinom rezultat(nrMaxCoef, coefSuma);
    delete[] coefSuma;
    return rezultat;
}

Polinom Polinom::operator-(const Polinom& polinom) const
{
    if (this->esteInvalid() || polinom.esteInvalid())
    {
        return Polinom();
    }

    int nrMinCoef = getNrMinimCoeficienti(polinom);
    int nrMaxCoef = getNrMaximCoeficienti(polinom);

    int* coefDiferenta = new int[nrMaxCoef] {0};

    for (int i = 0; i < nrMinCoef; i++)
    {
        coefDiferenta[i] = coeficienti[i] - polinom.coeficienti[i];
    }

    if (nrCoeficienti > polinom.nrCoeficienti)
    {
        for (int i = nrMinCoef; i < nrMaxCoef; i++)
        {
            coefDiferenta[i] = coeficienti[i];
        }
    }
    else
    {
        for (int i = nrMinCoef; i < nrMaxCoef; i++)
        {
            coefDiferenta[i] = -polinom.coeficienti[i];
        }
    }

    Polinom rezultat(nrMaxCoef, coefDiferenta);
    delete[] coefDiferenta;
    return rezultat;
}

Polinom Polinom::operator*(const Polinom& polinom) const
{
    if (this->esteInvalid() || polinom.esteInvalid())
    {
        return Polinom();
    }

    int g1 = nrCoeficienti - 1;
    int g2 = polinom.nrCoeficienti - 1;
    int dimRez = g1 + g2 + 1;

    int* coefProdus = new int[dimRez] {0};

    for (int i = 0; i < nrCoeficienti; i++)
    {
        for (int j = 0; j < polinom.nrCoeficienti; j++)
        {
            coefProdus[i + j] += coeficienti[i] * polinom.coeficienti[j];
        }
    }

    Polinom rezultat(dimRez, coefProdus);
    delete[] coefProdus;
    return rezultat;
}

bool Polinom::operator==(const Polinom& polinom) const
{
    if (this->esteInvalid() || polinom.esteInvalid() ||
        this->nrCoeficienti != polinom.nrCoeficienti)
    {
        return false;
    }

    for (int i = 0; i < nrCoeficienti; i++)
    {
        if ((*this)[i] != polinom[i])
        {
            return false;
        }
    }

    return true;
}

bool Polinom::operator!=(const Polinom& polinom) const
{
    return !(*this == polinom); // Negam rezultatul intors de operatorul ==, in loc sa duplicam codul
}

Polinom operator+(const Polinom& polinom, const int& scalar)
{
    if (polinom.esteInvalid())
    {
        return Polinom();
    }

    Polinom rezultat = polinom;
    rezultat[0] += scalar;
    return rezultat;
}

Polinom operator+(const int& scalar, const Polinom& polinom)
{
    return polinom + scalar; // folosim operatorul de mai sus pentru ca adunarea e comutativa iar implementarea ar fi fost aceeasi
}

Polinom operator-(const Polinom& polinom, const int& scalar)
{
    if (polinom.esteInvalid())
    {
        return Polinom();
    }

    Polinom rezultat = polinom;
    rezultat[0] -= scalar;
    return rezultat;
}

Polinom operator-(const int& scalar, const Polinom& polinom)
{
    if (polinom.esteInvalid())
    {
        return Polinom();
    }

    Polinom rezultat = polinom;

    for (int i = 0; i < polinom.nrCoeficienti; i++)
    {
        rezultat[i] = -rezultat[i];
    }

    rezultat[0] += scalar;

    return rezultat;
}

Polinom operator*(const Polinom& polinom, const int& scalar)
{
    if (polinom.esteInvalid())
    {
        return Polinom();
    }

    Polinom rezultat = polinom;

    for (int i = 0; i < polinom.nrCoeficienti; i++)
    {
        rezultat[i] *= scalar;
    }

    return rezultat;
}

Polinom operator*(const int& scalar, const Polinom& polinom)
{
    return polinom * scalar; // folosim operatorul de mai sus pentru ca inmultirea e comutativa iar implementarea ar fi fost aceeasi
}

std::ostream& operator<<(std::ostream& out, const Polinom& p)
{
    if (p.esteInvalid())
    {
        out << "Polinom invalid";
        return out;
    }

    bool primulTermen = true;

    for (int i = p.nrCoeficienti - 1; i >= 0; i--)
    {
        int coeficient = p.coeficienti[i];

        if (coeficient == 0)
        {
            continue;
        }

        if (primulTermen) // pt termenul dominant daca valoarea coeficientului e negativa vom afisa semnul minus in fata
        {
            if (coeficient < 0)
            {
                out << "-";
            }

            primulTermen = false;
        }
        else
        {
            out << (coeficient > 0 ? " + " : " - "); // pt ceilalti coeficienti vom pune semnele corespunzatoare
        }

        int absCoeficient = std::abs(coeficient); // facem modulul coeficientului pentru a putea afisa corect pe ecran

        if (i == 0)
        {
            out << absCoeficient; // termenul liber
        }
        else if (absCoeficient != 1)
        {
            out << absCoeficient << "X";
        }
        else
        {
            out << "X"; // ca sa evitam situatia cand coefiecientul e 1 in modul vom scrie doar X
        }

        if (i > 1) // doar pentru termenii cu grad >= 2 vom pune exponentul corespunzator
        {
            out << "^" << i;
        }
    }

    if (primulTermen) // daca toti coeficientii sunt 0 atunci avem polinomul nul
    {
        out << "0";
    }

    return out;
}