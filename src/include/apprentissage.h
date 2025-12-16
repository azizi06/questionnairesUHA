#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H

#include "Questionnaire.h"
#include "Affichage.h"

class Apprentissage
{
private:
    const Questionnaire& d_questionnaire;
    Affichage d_affichage;

public:
    Apprentissage(const Questionnaire& questionnaire);
    void demarrer() const;
};

#endif
