#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include<iostream>
#include <string>

class affichage {
public:
    affichage(std::ostream& ost=std::cout);
    void clearCMD() const;

    void dessinerCadre() const; // C'est �a le "dessin" demand�
    void placerCurseurSaisie() const; // Pour savoir o� �crire

    void afficherTitre(const std::string& titre) const;
    void afficherQuestion(const std::string& intitule) const;
    void afficherReponse(const std::string& reponse) const;
    void afficherMessage(const std::string& message) const;
    void pause();
private :
    std::ostream& d_ost;

};

#endif
