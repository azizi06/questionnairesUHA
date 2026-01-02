#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H

#include "questionnaire.h"
#include "affichageInterface.h"

class apprentissage {
public:


    // L'affichage est injecté (réel ou mock), ce qui rend la classe testable
    apprentissage(const questionnaire* questionnaire,affichageInterface* a);
    void apprendre() ;

private:
    const questionnaire* d_questionnaire;
    affichageInterface* d_affichage;
};

#endif
