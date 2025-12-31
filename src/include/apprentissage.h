#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H

#include "questionnaire.h"
#include "affichage.h"


class apprentissage {
public:
    apprentissage(const questionnaire& questionnaire);
    void apprendre() const;

private:
    const questionnaire& d_questionnaire;
    affichage d_affichage;
};

#endif
