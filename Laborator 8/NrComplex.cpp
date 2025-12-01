#include "NrComplex.h"

double NrComplex::getModul() const
{
    return sqrt(pow(real, 2) + pow(imaginar, 2));
}

NrComplex::NrComplex(const double& real /*= 0.0*/, const double& imaginar /*= 0.0*/)
{
    this->real = real;
    this->imaginar = imaginar;
}

bool NrComplex::operator>(const NrComplex& z) const
{
    return this->getModul() > z.getModul();
}

std::ostream& operator<<(std::ostream& out, const NrComplex& z)
{
    double real = z.real;
    double imaginar = z.imaginar;

    if (real == 0 && imaginar == 0)
    {
        out << "0";
        return out;
    }

    if (imaginar == 0)
    {
        out << real;
        return out;
    }

    if (real == 0)
    {
        if (imaginar == 1)
        {
            out << "i";
        }
        else if (imaginar == -1)
        {
            out << "-i";
        }
        else
        {
            out << imaginar << "i";
        }

        return out;
    }

    out << real;

    if (imaginar > 0)
    {
        out << " + ";
    }
    else
    {
        out << " - ";
    }

    double valoareAbsoluta = std::abs(imaginar);

    if (valoareAbsoluta == 1)
    {
        out << "i";
    }
    else
    {
        out << valoareAbsoluta << "i";
    }

    return out;
}