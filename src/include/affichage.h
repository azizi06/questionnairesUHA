#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <string>

class Affichage
{
public:
    void nettoyer();
    void afficherTitre(const std::string& titre);
    void afficherQuestion(const std::string& intitule);
    void afficherReponse(const std::string& reponse);
    void afficherMessage(const std::string& msg);
};

#endif
