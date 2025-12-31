#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <string>

class affichage {
public:
    void clearCMD() const;

    void dessinerCadre() const; // C'est �a le "dessin" demand�
    void placerCurseurSaisie() const; // Pour savoir o� �crire

    void afficherTitre(const std::string& titre) const;
    void afficherQuestion(const std::string& intitule) const;
    void afficherReponse(const std::string& reponse) const;
    void afficherMessage(const std::string& message) const;
};

#endif
