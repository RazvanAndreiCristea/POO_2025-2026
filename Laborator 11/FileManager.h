#pragma once
#include <map>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "Angajat.h"
#include "Departament.h"

class FileManager
{
	static std::vector<Departament> colectareDepartamente(const std::string& fisierDep);
	static std::map<int, std::list<Angajat>> colectareAngajati(const std::string& fisierAng);
	static std::vector<std::string> split(const std::string& str, const char& delimitator);

public:

	static std::map<Departament, std::list<Angajat>> colectareDate(const std::string& fisierDep, const std::string& fisierAng);
};