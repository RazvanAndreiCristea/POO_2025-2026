#include "FileManager.h"

std::vector<std::string> FileManager::split(const std::string& str, const char& delimitator)
{
	std::string item;
	std::stringstream ss(str);
	std::vector<std::string> parti;

	while (std::getline(ss, item, delimitator))
	{
		parti.push_back(item);
	}

	return parti;
}

std::vector<Departament> FileManager::colectareDepartamente(const std::string& fisierDep)
{
	std::vector<Departament> departamente;

	std::ifstream fin(fisierDep);

	if (!fin.is_open())
	{
		std::cerr << "Eroare: nu s-a putut deschide fisierul departamentelor: " << fisierDep << '\n';
		return departamente;
	}

	std::string linie;
	std::getline(fin, linie); // ignoram header-ul

	while (std::getline(fin, linie))
	{
		if (linie.empty())
		{
			continue;
		}

		std::vector<std::string> parti = split(linie, ',');

		int id = std::stoi(parti.at(0));
		std::string denumire = parti.at(1);

		departamente.push_back(Departament(id, denumire));
	}

	return departamente;
}

std::map<int, std::list<Angajat>> FileManager::colectareAngajati(const std::string& fisierAng)
{
	std::map<int, std::list<Angajat>> angajati;

	std::ifstream fin(fisierAng);

	if (!fin.is_open())
	{
		std::cerr << "Eroare: nu s-a putut deschide fisierul angajatilor: " << fisierAng << '\n';
		return angajati;
	}

	std::string linie;
	std::getline(fin, linie); // ignoram header-ul

	while (std::getline(fin, linie))
	{
		if (linie.empty())
		{
			continue;
		}

		std::vector<std::string> parti = split(linie, ',');

		int id = std::stoi(parti.at(0));
		int idDepartament = std::stoi(parti.at(1));
		int varsta = std::stoi(parti.at(2));

		double salariu = std::stod(parti.at(3));
		double comision = std::stod(parti.at(4));

		std::string nume = parti.at(5);
		std::string prenume = parti.at(6);
		std::string functie = parti.at(7);

		Angajat angajat(id, idDepartament, varsta, salariu, comision, nume, prenume, functie);
		angajati[idDepartament].push_back(angajat);
	}

	return angajati;
}

std::map<Departament, std::list<Angajat>> FileManager::colectareDate(const std::string& fisierDep, const std::string& fisierAng)
{
	std::vector<Departament> departamente = colectareDepartamente(fisierDep);
	std::map<int, std::list<Angajat>> angajati = colectareAngajati(fisierAng);

	std::map<Departament, std::list<Angajat>> companie;

	for (int i = 0; i < departamente.size(); i++)
	{
		companie.insert(std::make_pair(departamente.at(i), angajati.at(i + 1)));
	}

	return companie;
}