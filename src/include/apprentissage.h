#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H

#include "questionnaire.h"
#include "affichage.h"
#include "affichageInterface.h"

class apprentissage {
public:

    // Constructeur principal

    // Constructeur pour les tests, permet l'injection de dépendance (Mock)
    apprentissage(const questionnaire* questionnaire,affichageInterface* a);
    void apprendre() ;

private:
    const questionnaire* d_questionnaire;

    // Ce que la classe utilise réellement (pointe vers le réel ou le Mock)
    affichageInterface* d_affichage;
};

#endif
