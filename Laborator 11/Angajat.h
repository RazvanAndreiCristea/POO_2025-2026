#pragma once
#include <string>
#include <iostream>

class Angajat
{
    int varsta;

    double salariu;
    double comision;

    std::string nume;
    std::string prenume;
    std::string functie;

    const int id;
    const int idDepartament;

public:

    Angajat();
    Angajat(const int& id, const int& idDepartament, const int& varsta, const double& salariu,
        const double& comision, const std::string& nume, const std::string& prenume, const std::string& functie);

    Angajat& operator=(const Angajat& angajat);

    const int getIdDepartament() const;
	const std::string getFunctie() const;
    const std::string getNumeComplet() const;

    double getSalariuDeBaza() const;
    double getSalariuComplet() const;

    bool operator>(const Angajat& angajat) const;
    friend std::ostream& operator<<(std::ostream& out, const Angajat& angajat);
};