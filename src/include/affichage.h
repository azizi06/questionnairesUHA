#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <iostream>
#include <string>
#include "affichageInterface.h"

// en utilisant goto_xy pour le positionnement du curseur
class affichage : public affichageInterface {
public:
    affichage(std::ostream& ost = std::cout, std::istream& ist = std::cin);

    void clearCMD() const override;
    void afficherTitre(const std::string& titre) const override;
    void afficherQuestion(const std::string& intitule) const override;
    void afficherReponse(const std::string& reponse) const override;
    void afficherMessage(const std::string& message) const override;
    void attendreTouche() const override;
    void pause() const;
    void dessinerCadre() const;
    void placerCurseurSaisie() const;
    std::string entrer();
    void curseur(int x, int y);

private:
    std::ostream& d_ost;
    std::istream& d_ist;
};

#endif
