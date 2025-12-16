#include "question.h"

question::question(const std::string& intitule, const std::string& texte)
    : d_intitule{intitule}, d_texte{texte} {}

std::string question::Intitule() const
{
    return d_intitule;
}

std::string question::Texte() const
{
    return d_texte;
}
>>>>>>> feature/classes-questions
