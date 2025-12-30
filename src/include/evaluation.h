#ifndef EVALUATION_H
#define EVALUATION_H

<<<<<<< HEAD

#include "questionnaire.h"
#include "StrategieEvaluation.h"


=======
#include <string>
#include "../include/evaluation.h"
#include "../include/strategieEvaluation.h"
#include"questionnaire.h"

/*
 Classe evaluation :
 - g�re le d�roulement d'une �valuation
 - utilise une strat�gie d'�valuation
 - calcule les r�sultats
*/
>>>>>>> feature/classes-questionaire

class evaluation {
private:
    questionnaire* d_questionnaire;
    strategieEvaluation* d_strategie;

    int d_nombreEssais;
    int d_nombreBonnesReponses;
    int d_indiceQuestionCourante;

public:
<<<<<<< HEAD


    evaluation(questionnaire* questionnaire, strategieEvaluation* stragie);


=======
    // Constructeur : une �valuation est faite � partir d'un questionnaire
    evaluation(questionnaire* q, strategieEvaluation* s);

    // D�marrer l'�valuation
>>>>>>> feature/classes-questionaire
    void commencer();

    // Indique s'il reste des questions
    bool aDesQuestions() const;

    // Retourne la question courante

    question* questionCourante() const;

<<<<<<< HEAD

    bool repondre(const std::string& reponseUtilisateur);


    bool peutAfficherCorrection() const;


    void questionSuivante();


=======
    // Soumettre la r�ponse de l'utilisateur
    bool repondre(const std::string& reponseUtilisateur);

    // Indique si on peut afficher la bonne r�ponse
    bool peutAfficherCorrection() const;

    // Passer � la question suivante
    void questionSuivante();

    // Afficher les r�sultats finaux
>>>>>>> feature/classes-questionaire
    void afficherResultats() const;
};

#endif
