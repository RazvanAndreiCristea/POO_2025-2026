#include "Angajat.h"

Angajat::Angajat() : id(0), idDepartament(0)
{
    varsta = 0;
    salariu = 0.0;
    comision = 0.0;
}

Angajat::Angajat(const int& id, const int& idDepartament, const int& varsta, const double& salariu, const double& comision,
    const std::string& nume, const std::string& prenume, const std::string& functie) : id(id), idDepartament(idDepartament)
{
    this->varsta = varsta;
    this->salariu = salariu;
    this->comision = comision;

    this->nume = nume;
    this->prenume = prenume;
    this->functie = functie;
}

Angajat& Angajat::operator=(const Angajat& angajat)
{
    if (this == &angajat)
    {
        return *this;
    }

    varsta = angajat.varsta;
    salariu = angajat.salariu;
    comision = angajat.comision;

    nume = angajat.nume;
    prenume = angajat.prenume;
    functie = angajat.functie;

    return *this;
}

const int Angajat::getIdDepartament() const
{
    return idDepartament;
}

const std::string Angajat::getFunctie() const
{
    return functie;
}

const std::string Angajat::getNumeComplet() const
{
    return nume + " " + prenume;
}

double Angajat::getSalariuDeBaza() const
{
    return salariu;
}

double Angajat::getSalariuComplet() const
{
    return salariu + salariu * comision;
}

bool Angajat::operator>(const Angajat& angajat) const
{
    return nume > angajat.nume;
}

std::ostream& operator<<(std::ostream& out, const Angajat& angajat)
{
    out << "Id-ul angajatului este: " << angajat.id << '\n';
    out << "Id-ul departamentului in care angajatul lucreaza este: " << angajat.idDepartament << '\n';
    out << "Numele complet al angajatului este: " << angajat.getNumeComplet() << '\n';
    out << "Salariul de baza al angajatului este: " << angajat.salariu << " euro\n";
    out << "Salariul cu bonusuri al angajatului este: " << angajat.getSalariuComplet() << " euro\n";
    out << "Functia ocupata de angajat in companie este: " << angajat.functie << '\n';

    return out;
}