
#ifndef AFFICHAGEINTERFACE_H
#define AFFICHAGEINTERFACE_H

#include <string>

class affichageInterface {
public:
    virtual ~affichageInterface() = default;

    virtual void clearCMD() const = 0;
    virtual void afficherTitre(const std::string& titre) const = 0;
    virtual void afficherQuestion(const std::string& intitule) const = 0;
    virtual void afficherReponse(const std::string& reponse) const = 0;
    virtual void afficherMessage(const std::string& message) const = 0;

    //remplacer getch() dans apprentissage
    virtual void attendreTouche() const = 0;
};

#endif
