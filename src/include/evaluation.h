#ifndef EVALUATION_H
#define EVALUATION_H

#include "questionnaire.h"
#include "strategieEvaluation.h"

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
    void evaluer();
    bool aDesQuestions() const;

    const question* questionCourante() const;

    bool repondre(const std::string& reponseUtilisateur);

    bool peutAfficherCorrection() const;

    void questionSuivante();

    void afficherResultats() const;
};

#endif
