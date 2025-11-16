#pragma once
#include "Dop.h"
#include "Produs.h"
#include "Recipient.h"

class Sticla : public Recipient, public Produs
{
    Dop dop;

public:

    Sticla();
    Sticla(const float& volum, const char* material, const double& pret, const char* producator, const Dop& dop);
    Sticla(const Sticla& sticla);
    Sticla& operator=(const Sticla& sticla);

    bool operator>(const Sticla& sticla) const;

    friend std::ostream& operator<<(std::ostream& out, const Sticla& sticla);
};