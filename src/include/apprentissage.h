#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H

#include "questionnaire.h"
#include "affichage.h"
#include "affichageInterface.h"

class apprentissage {
public:

    // Constructeur principal
    apprentissage(const questionnaire& questionnaire);

    // Constructeur pour les tests, permet l'injection de dépendance (Mock)
    apprentissage(const questionnaire& questionnaire, const affichageInterface& a);

    void apprendre() const;

private:
    const questionnaire& d_questionnaire;

    affichage d_affichageReel;

    // Ce que la classe utilise réellement (pointe vers le réel ou le Mock)
    const affichageInterface* d_affichage;
};

#endif
