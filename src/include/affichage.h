#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include<iostream>
#include <string>
#include "affichageInterface.h"

class affichage : public affichageInterface{
public:
    affichage(std::ostream& ost=std::cout,std::istream& ist=std::cin);
    void clearCMD() const override;

    void dessinerCadre() const; // C'est �a le "dessin" demand�
    void placerCurseurSaisie() const; // Pour savoir o� �crire

    void afficherTitre(const std::string& titre) const override;
    void afficherQuestion(const std::string& intitule) const override;
    void afficherReponse(const std::string& reponse) const override;
    void afficherMessage(const std::string& message) const override;
    void attendreTouche() const override;
    void pause() const;
    std::string entrer();
   void  curseur(int x,int y);
private :
    std::ostream& d_ost;
    std::istream &d_ist;

};

#endif
