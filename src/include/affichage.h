#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <string>

class affichage{
public:
    void clearCMD() const;
    void afficherTitre(const std::string& titre) const;
    void afficherQuestion(const std::string& intitule) const;
    void afficherReponse(const std::string& reponse) const;
    void afficherMessage(const std::string& message) const;
};

#endif
 /*
  On ne veut pas mélanger affichage et logique, donc on cree une classe chargé de l’affichage console
  qui isole l’utilisation de goto_xy
 */
