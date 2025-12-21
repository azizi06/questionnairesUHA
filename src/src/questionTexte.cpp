#include "../include/questionTexte.h"

questionTexte::questionTexte(const std::string& intitule,const std::string& reponse)
    : question(intitule), d_reponse{reponse} {}

bool questionTexte::estBonneReponse(const std::string& reponse) const
{
    return reponse ==d_reponse;
}

std::string questionTexte::getReponseCorrecte() const
{
    return d_reponse;
}
