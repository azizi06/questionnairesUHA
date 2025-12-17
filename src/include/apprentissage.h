#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H

#include "questionaire.h"
#include "questionairIeIterator.h"
#include "affichage.h"

class apprentissage {

public:
    apprentissage(const questionaire& questionaire);
    void apprendre() const;

private:
    const questionaire& d_questionaire; //on utilise le questionnaire mais on ne le modifie pas
    affichage d_affichage;

};

#endif
