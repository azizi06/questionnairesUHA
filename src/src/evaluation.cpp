#include "../include/evaluation.h"
#include <iostream>

evaluation::evaluation(const questionnaire* q, strategieEvaluation* s)
    : d_questionnaire(q),
      d_strategie(s),
      d_nombreEssais(0),
      d_nombreBonnesReponses(0),
      d_indiceQuestionCourante(-1)
{
}

void evaluation::commencer() {
    if (!d_questionnaire || !d_strategie) {
        std::cout << "Erreur : �valuation mal initialis�e.\n";
        return;
    }

    d_strategie->init(d_questionnaire->taille());
    questionSuivante();
}

bool evaluation::aDesQuestions() const {
    return d_strategie->aDesQuestions();
}

const question* evaluation::questionCourante() const {
    if (d_indiceQuestionCourante < 0) {
        return nullptr;
    }
    return d_questionnaire->getQuestionNumero(d_indiceQuestionCourante);
}


bool evaluation::repondre(const std::string& reponseUtilisateur) {
    const question* q = questionCourante();


    d_nombreEssais++;

    bool correcte = q->estBonneReponse(reponseUtilisateur);

    if (correcte) {
        d_nombreBonnesReponses++;
    }

    d_strategie->soumettreReponse(d_indiceQuestionCourante, correcte);
    return correcte;
}

bool evaluation::peutAfficherCorrection() const {
    return d_strategie->peutAfficherCorrection(d_indiceQuestionCourante);
}

void evaluation::questionSuivante() {
    if (d_strategie->aDesQuestions()) {
        d_indiceQuestionCourante = d_strategie->questionSuivante();
    }
}

void evaluation::afficherResultats() const {
    std::cout << "\n=== R�sultats ===\n";
    std::cout << "Questions : " << d_questionnaire->taille() << "\n";
    std::cout << "Essais    : " << d_nombreEssais << "\n";
    std::cout << "Bonnes    : " << d_nombreBonnesReponses << "\n";
}
