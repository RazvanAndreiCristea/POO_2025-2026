#pragma once
#include <string>
#include <iostream>

class Departament
{
    const int id;
    std::string denumire;

public:

    Departament();
    Departament(const int& id, const std::string& denumire);
    Departament& operator=(const Departament& departament);

    const std::string getDenumire() const;

    bool operator<(const Departament& departament) const;
    friend std::ostream& operator<<(std::ostream& out, const Departament& departament);
};