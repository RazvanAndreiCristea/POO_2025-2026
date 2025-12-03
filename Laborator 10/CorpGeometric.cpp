#include "CorpGeometric.h"

CorpGeometric::~CorpGeometric() { }

bool CorpGeometric::operator>(const CorpGeometric& corpGeometric) const
{
    return this->getTipCorp() > corpGeometric.getTipCorp();
}

std::ostream& operator<<(std::ostream& out, const CorpGeometric* const& corpGeometric)
{
    corpGeometric->afisare(out);
    return out;
}