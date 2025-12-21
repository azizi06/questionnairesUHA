#include "../include/evaluation.h"


#include <iostream>

/*
 Constructeur :
 - une évaluation est toujours faite à partir d'un questionnaire
 - et utilise une stratégie d'évaluation
*/
Evaluation::Evaluation(Questionnaire* q, strategieEvaluation* s)
    : questionnaire(q),
      strategie(s),
      nombreEssais(0),
      nombreBonnesReponses(0),
      indiceQuestionCourante(-1)
{
}

/*
 Démarre l'évaluation.
 Initialise la stratégie avec le nombre de questions du questionnaire.
*/
void evaluation::commencer() {
    if (!questionnaire || !strategie) {
        std::cout << "Erreur : évaluation mal initialisée.\n";
        return;
    }

    strategie->init(questionnaire->taille());
    questionSuivante();
}

/*
 Indique s'il reste des questions à poser
*/
bool Evaluation::aDesQuestions() const {
    return strategie->aDesQuestions();
}

/*
 Retourne la question courante
*/
Question* Evaluation::questionCourante() const {
    if (indiceQuestionCourante < 0) {
        return nullptr;
    }
    return questionnaire->getQuestion(indiceQuestionCourante);
}

/*
 Soumettre la réponse de l'utilisateur
 - vérifie si la réponse est correcte
 - informe la stratégie
 - met à jour les compteurs
*/
bool Evaluation::repondre(const std::string& reponseUtilisateur) {
    Question* q = questionCourante();
    if (!q) {
        return false;
    }

    nombreEssais++;

    bool correcte = q->estBonneReponse(reponseUtilisateur);

    if (correcte) {
        nombreBonnesReponses++;
    }

    // informer la stratégie du résultat
    strategie->soumettreReponse(indiceQuestionCourante, correcte);

    return correcte;
}

/*
 Indique si la correction peut être affichée
 (dépend de la stratégie)
*/
bool Evaluation::peutAfficherCorrection() const {
    return strategie->peutAfficherCorrection(indiceQuestionCourante);
}

/*
 Passer à la question suivante
*/
void Evaluation::questionSuivante() {
    if (strategie->aDesQuestions()) {
        indiceQuestionCourante = strategie->questionSuivante();
    }
}

/*
 Affiche les résultats finaux de l'évaluation
*/
void Evaluation::afficherResultats() const {
    std::cout << "\n=== Résultats de l'évaluation ===\n";
    std::cout << "Nombre de questions : " << questionnaire->taille() << "\n";
    std::cout << "Nombre d'essais     : " << nombreEssais << "\n";
    std::cout << "Bonnes réponses     : " << nombreBonnesReponses << "\n";

    if (questionnaire->taille() > 0) {
        int score = (nombreBonnesReponses * 100) / questionnaire->taille();
        std::cout << "Score final         : " << score << " %\n";
    }
}
