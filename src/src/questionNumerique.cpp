#include "../include/questionNumerique.h"
#include <stdexcept>

questionNumerique::questionNumerique(const std::string& intitule,int reponse,int valeurMin,int valeurMax):
<<<<<<< HEAD
    question{intitule}, d_reponse{reponse}, d_valeurMin{valeurMin}, d_valeurMax{valeurMax} {}
=======
    question(intitule), d_reponse{reponse}, d_valeurMin{valeurMin}, d_valeurMax{valeurMax} {}
>>>>>>> origin/feature/classes-questions

bool questionNumerique::estBonneReponse(const std::string& reponse) const {
    try {
        int valeur = std::stoi(reponse);
        return valeur ==d_reponse;
    }
    catch (...) {
        //si c'est pas un nombre en retourn faux
        return false;
    }
}


std::string questionNumerique::getReponseCorrecte() const {
    return std::to_string(d_reponse);
}
