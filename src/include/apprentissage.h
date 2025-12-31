#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H

#include "questionnaire.h"
#include "affichage.h"
#include "affichageInterface.h"

class apprentissage {
public:
    // Comme avant : tes amis gardent leur main inchangé
    apprentissage(const questionnaire& questionnaire);

    // Pour les tests : injection d’un affichage (mock)
    apprentissage(const questionnaire& questionnaire, const affichageInterface& a);

    void apprendre() const;

private:
    const questionnaire& d_questionnaire;

    // Affichage réel (existe toujours)
    affichage d_affichageReel;

    // Ce que la classe utilise vraiment (réel OU mock)
    const affichageInterface* d_affichage;
};

#endif
