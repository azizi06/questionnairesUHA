#include "QuestionTexte.h"

QuestionTexte::QuestionTexte(const std::string& i,
                             const std::string& t,
                             const std::string& r)
    : Question(i, t), reponse(r) {}

bool QuestionTexte::estBonneReponse(const std::string& r) const {
    return r == reponse;
}

std::string QuestionTexte::getReponseCorrecte() const {
    return reponse;
}
