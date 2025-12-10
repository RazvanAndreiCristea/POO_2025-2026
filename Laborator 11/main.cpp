#include <numeric>
#include <algorithm>
#include "FileManager.h"

int main()
{
	// Cerinta 3

	std::map<Departament, std::list<Angajat>> companie = FileManager::colectareDate("date\\departamente.csv", "date\\angajati.csv"); // pt a putea rula pe Windows
	/*std::map<Departament, std::list<Angajat>> companie = FileManager::colectareDate("./date/departamente.csv", "./date/angajati.csv"); // pt a putea rula pe Linux*/

	if (companie.empty())
	{
		std::cout << "Datele companiei nu au putut fi colectate.\n";
		return 0;
	}

	for (const auto& pereche : companie)
	{
		std::cout << pereche.first << '\n';

		for (const Angajat& angajat : pereche.second)
		{
			std::cout << angajat << '\n';
		}

		std::cout << "----------------------------------------------\n\n";
	}

	// Cerinta 4

	auto perecheMinMax = std::minmax_element(companie.begin(), companie.end(),
		[](const std::pair<Departament, std::list<Angajat>>& a, const std::pair<Departament, std::list<Angajat>>& b)
		{
			return a.second.size() < b.second.size();
		});

	if (perecheMinMax.first == companie.end() || perecheMinMax.second == companie.end())
	{
		std::cout << "Nu s-au putut determina departamentele cu numar minim si maxim de angajati.\n";
		return 0;
	}

	std::map<Departament, std::list<Angajat>>::iterator itMin = perecheMinMax.first;
	std::map<Departament, std::list<Angajat>>::iterator itMax = perecheMinMax.second;

	std::cout << "Denumirea departamentului cu cel mai mic numar de angajati este: "
		<< itMin->first.getDenumire() << '\n';

	std::cout << "Numarul de angajati din departament este: " << itMin->second.size() << '\n';

	std::cout << "\nDenumirea departamentului cu cel mai mare numar de angajati este: "
		<< itMax->first.getDenumire() << '\n';

	std::cout << "Numarul de angajati din departament este: " << itMax->second.size() << '\n';

	// Cerinta 5

	int numarAngajati = 0;
	double sumaSalarii = 0;

	for (const auto& pereche : companie)
	{
		sumaSalarii += std::accumulate(pereche.second.begin(), pereche.second.end(), 0.0,
			[](double suma, const Angajat& angajat)
			{
				return suma + angajat.getSalariuDeBaza();
			});

		numarAngajati += (int)pereche.second.size();
	}

	double salariuMediu = numarAngajati != 0 ? sumaSalarii / numarAngajati : 0.0;
	std::cout << "\nSalariul mediu de baza din companie este: " << salariuMediu << " euro\n";

	// Cerinta 6

	for (auto& pereche : companie)
	{
		pereche.second.sort(
			[](const Angajat& a, const Angajat& b)
			{
				return a > b;
			});
	}

	for (const auto& pereche : companie)
	{
		std::cout << pereche.first << '\n';

		for (const Angajat& angajat : pereche.second)
		{
			std::cout << angajat << '\n';
		}

		std::cout << "----------------------------------------------\n\n";
	}

	// Cerinta 7

	std::vector<Angajat> angajatiTop;

	for (const auto& pereche : companie)
	{
		if (!pereche.second.empty())
		{
			auto itMax = std::max_element(pereche.second.begin(), pereche.second.end(),
				[](const Angajat& a, const Angajat& b)
				{
					return a.getSalariuComplet() < b.getSalariuComplet();
				});

			if (itMax != pereche.second.end())
			{
				angajatiTop.push_back(*itMax);
			}
		}
	}

	std::cout << "Angajatii cu cel mai mare salariu complet din fiecare departament sunt afisati mai jos\n\n";

	std::sort(angajatiTop.begin(), angajatiTop.end(),
		[](const Angajat& a, const Angajat& b)
		{
			return a.getSalariuComplet() > b.getSalariuComplet();
		});

	for (const Angajat& angajat : angajatiTop)
	{
		std::cout << angajat << '\n';
	}

	// Cerinta 8

	auto itDepartamentIT = std::find_if(companie.begin(), companie.end(),
		[](const std::pair<Departament, std::list<Angajat>>& pereche)
		{
			return pereche.first.getDenumire() == "IT";
		});

	if (itDepartamentIT != companie.end())
	{
		std::list<Angajat> programatori = itDepartamentIT->second;

		programatori.remove_if(
			[](const Angajat& angajat)
			{
				return angajat.getFunctie() != "Programator";
			});

		programatori.sort(
			[](const Angajat& a, const Angajat& b)
			{
				return a.getSalariuDeBaza() > b.getSalariuDeBaza();
			});

		int count = 0;
		std::vector<Angajat> top3Programatori;

		for (const Angajat& angajat : programatori)
		{
			if (count >= 3)
			{
				break;
			}

			count++;
			top3Programatori.push_back(angajat);
		}

		std::sort(top3Programatori.begin(), top3Programatori.end(),
			[](const Angajat& a, const Angajat& b)
			{
				return a.getNumeComplet() < b.getNumeComplet();
			});

		std::cout << "Top 3 programatori din departamentul IT\n\n";

		for (const Angajat& angajat : top3Programatori)
		{
			std::cout << angajat << '\n';
		}
	}

	return 0;
}