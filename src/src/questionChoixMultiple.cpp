#include "../include/questionChoixMultiple.h"
#include <stdexcept>

questionChoixMultiple::questionChoixMultiple(const std::string& intitule,const std::vector<std::string>& options,int correct)
    : question(intitule), d_options{options}, d_bonneReponse{correct} {}

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
std::vector<std::string> questionChoixMultiple::options(){
    return d_options;
}
std::string questionChoixMultiple::Intitule() const  {
    std::string result = question::Intitule() + "\n  ";
    for (int i = 0; i < d_options.size(); ++i) {
        result += std::to_string(i + 1) + ". " + d_options[i] + " , ";
    }
    
    return result;
}