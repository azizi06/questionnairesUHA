#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <string>
#include "affichageInterface.h"

class affichage : public affichageInterface {
public:
    void clearCMD() const override;
    void afficherTitre(const std::string& titre) const override;
    void afficherQuestion(const std::string& intitule) const override;
    void afficherReponse(const std::string& reponse) const override;
    void afficherMessage(const std::string& message) const override;

    void attendreTouche() const override;


    void dessinerCadre() const;
    void placerCurseurSaisie() const;
};

#endif

/*
 On ne veut pas mélanger affichage et logique, donc on cree une classe chargé de l’affichage console
 qui isole l’utilisation de goto_xy
*/



