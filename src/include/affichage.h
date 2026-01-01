#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include<iostream>
#include <string>

class affichage {
public:
    affichage(std::ostream& ost=std::cout,std::istream& ist=std::cin);
    void clearCMD() const;

    void dessinerCadre() const;
    void placerCurseurSaisie() const;

    void afficherTitre(const std::string& titre) const;
    void afficherQuestion(const std::string& intitule) const;
    void afficherReponse(const std::string& reponse) const;
    void afficherMessage(const std::string& message) const;
    void pause();
    std::string entrer();
   void  curseur(int x,int y);

private :
    std::ostream& d_ost;
    std::istream &d_ist;

};

#endif

/*
 On ne veut pas mélanger affichage et logique, donc on cree une classe chargé de l’affichage console
 qui isole l’utilisation de goto_xy
*/



