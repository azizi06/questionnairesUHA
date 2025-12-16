#include "QuestionChoixMultiple.h"
#include <stdexcept>

questionChoixMultiple::questionChoixMultiple(const std::string& intitule,const std::string& texte,const std::vector<std::string>& options,int correct)
    : question(intitule,texte), d_options{options}, d_bonneReponse{correct} {}

bool questionChoixMultiple::estBonneReponse(const std::string& reponse) const
{
    try {
        int valeur =std::stoi(reponse);
        return valeur ==d_bonneReponse;
    } catch (...) {return false;}
}

std::string questionChoixMultiple::getReponseCorrecte() const {
    return std::to_string(d_bonneReponse);
}
