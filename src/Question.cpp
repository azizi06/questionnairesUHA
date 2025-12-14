#include "Question.h"

Question::Question(const std::string& i, const std::string& t)
    : intitule(i), texte(t) {}

std::string Question::getIntitule() const {
    return intitule;
}

std::string Question::getTexte() const {
    return texte;
}
