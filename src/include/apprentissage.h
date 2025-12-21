#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H

#include "questionnaire.h"
#include "questionairIeIterator.h"
#include "affichage.h"

class apprentissage {

public:
    apprentissage(const questionnaire& questionnaire);
    void apprendre() const;

private:
    const questionnaire& d_questionnaire; //on utilise le questionnaire mais on ne le modifie pas
    affichage d_affichage;

};

#endif
