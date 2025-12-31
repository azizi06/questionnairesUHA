#ifndef EVALUATION_H
#define EVALUATION_H

#include "../include/questionnaire.h"
#include "../include/strategieEvaluation.h"
#include "../include/affichage.h"

class evaluation {
private:
    const questionnaire* d_questionnaire;
    strategieEvaluation* d_strategie;

    int d_nombreEssais;
    int d_nombreBonnesReponses;
    int d_indiceQuestionCourante;

public:
    evaluation(const questionnaire* q, strategieEvaluation* s);

    void commencer();
    void evaluer(affichage ecran);
    bool aDesQuestions() const;

    const question* questionCourante() const;

    bool repondre(const std::string& reponseUtilisateur);

    bool peutAfficherCorrection() const;

    void questionSuivante();

    void afficherResultats() const;
};

#endif
