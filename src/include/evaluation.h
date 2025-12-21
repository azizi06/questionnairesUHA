#ifndef EVALUATION_H
#define EVALUATION_H

#include <string>
#include "../include/evaluation.h"
#include "../include/strategieEvaluation.h"
#include"questionaire.h"

/*
 Classe evaluation :
 - gère le déroulement d'une évaluation
 - utilise une stratégie d'évaluation
 - calcule les résultats
*/

class evaluation {
private:
    questionnaire* questionnaire;
    strategieEvaluation* strategie;

    int nombreEssais;
    int nombreBonnesReponses;
    int indiceQuestionCourante;

public:
    // Constructeur : une évaluation est faite à partir d'un questionnaire
    evaluation(questionnaire* q, strategieEvaluation* s);

    // Démarrer l'évaluation
    void commencer();

    // Indique s'il reste des questions
    bool aDesQuestions() const;

    // Retourne la question courante
    question* questionCourante() const;

    // Soumettre la réponse de l'utilisateur
    bool repondre(const std::string& reponseUtilisateur);

    // Indique si on peut afficher la bonne réponse
    bool peutAfficherCorrection() const;

    // Passer à la question suivante
    void questionSuivante();

    // Afficher les résultats finaux
    void afficherResultats() const;
};

#endif
