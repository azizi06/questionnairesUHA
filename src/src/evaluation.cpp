

#include "../include/strategieEvaluation.h"

#include "../include/evaluation.h"



#include <iostream>

/*
 - une évaluation est toujours faite à partir d'un questionnaire
 - et utilise une stratégie d'évaluation
*/


evaluation::evaluation(questionnaire* questionnaire, strategieEvaluation* strategie)
    : d_questionnaire{questionaire},
      d_strategie{strategie},
      d_nombreEssais{0},
      d_nombreBonnesReponses{0},
      d_indiceQuestionCourante{-1}
{
}

/*
 Initialise la stratégie avec le nombre de questions du questionnaire.
*/

void evaluation::commencer() {

    if (!d_questionnaire || !d_strategie) {
        std::cout << "Erreur : évaluation mal initialisée.\n";
        return;
    }

    d_strategie->init(d_questionnaire->taille());
    questionSuivante();
}

/*
 Indique s'il reste des questions à poser
*/
bool evaluation::aDesQuestions() const {
    return d_strategie->aDesQuestions();
}


Question* evaluation::questionCourante() const {
    if (d_indiceQuestionCourante < 0) {
        return nullptr;
    }
    return d_questionnaire->getQuestionNumero(indiceQuestionCourante);
}

/*
 Soumettre la réponse de l'utilisateur
 - vérifie si la réponse est correcte
 - informe la stratégie
 - met à jour les compteurs
*/
bool evaluation::repondre(const std::string& reponseUtilisateur) {
    question* question = questionCourante();
    if (!question) {
        return false;
    }

    d_nombreEssais++;

    bool correcte = question->estBonneReponse(reponseUtilisateur);

    if (correcte) {
        d_nombreBonnesReponses++;
    }

    // informer la stratégie du résultat
    d_strategie->soumettreReponse(indiceQuestionCourante, correcte);

    return correcte;
}

/*
 (dépend de la stratégie)
*/
bool evaluation::peutAfficherCorrection() const {
    return d_strategie->peutAfficherCorrection(indiceQuestionCourante);
}


void evaluation::questionSuivante() {
    if (d_strategie->aDesQuestions()) {
        d_indiceQuestionCourante = d_strategie->questionSuivante();
    }
}


void evaluation::afficherResultats() const {
    std::cout << "\n=== Résultats de l'évaluation ===\n";
    std::cout << "Nombre de questions : " << d_questionnaire->taille() << "\n";
    std::cout << "Nombre d'essais     : " << d_nombreEssais << "\n";
    std::cout << "Bonnes réponses     : " << d_nombreBonnesReponses << "\n";

    if (d_questionnaire->taille() > 0) {
        int score = (d_nombreBonnesReponses * 100) / d_questionnaire->taille();
        std::cout << "Score final         : " << score << " %\n";
    }
}
