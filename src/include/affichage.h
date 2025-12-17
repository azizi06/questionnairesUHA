#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <string>

class Affichage{
public:
    void clearCMD();
    void afficherTitre(const std::string& titre);
    void afficherQuestion(const std::string& intitule);
    void afficherReponse(const std::string& reponse);
    void afficherMessage(const std::string& message);
};

#endif
 /*
  On ne veut pas mélanger affichage et logique, donc on cree une classe chargé de l’affichage console
  qui isole l’utilisation de goto_xy
 */
