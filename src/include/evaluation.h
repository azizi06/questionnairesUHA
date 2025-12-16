#ifndef EVALUATION_H
#define EVALUATION_H


#include "questionnaire.h"
#include "StrategieEvaluation.h"



class evaluation {
private:
    questionnaire* d_questionnaire;
    strategieEvaluation* d_strategie;

    int d_nombreEssais;
    int d_nombreBonnesReponses;
    int d_indiceQuestionCourante;

public:


    evaluation(questionnaire* questionnaire, strategieEvaluation* stragie);


    void commencer();

    // Indique s'il reste des questions
    bool aDesQuestions() const;

    // Retourne la question courante

    question* questionCourante() const;


    bool repondre(const std::string& reponseUtilisateur);


    bool peutAfficherCorrection() const;


    void questionSuivante();


    void afficherResultats() const;
};

#endif
