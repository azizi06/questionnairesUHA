#include "question.h"

question::question(const std::string& intitule)

    : d_intitule{intitule} {}

std::string question::Intitule() const
{
    return d_intitule;
}

