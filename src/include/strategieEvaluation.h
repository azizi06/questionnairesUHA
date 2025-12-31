#ifndef STRATEGIE_EVALUATION_H
#define STRATEGIE_EVALUATION_H

/*
 Classe abstraite strategieEvaluation
 Définit le comportement d'une stratégie d'évaluation.
 Les classes concrètes (test, seconde chance, adaptative)

*/


class strategieEvaluation {
public:
    virtual ~strategieEvaluation() {}


    // Initialiser la stratégie avec le nombre total de questions
    virtual void init(int nombreQuestions) = 0;

    // Indique s'il reste des questions à poser
    virtual bool aDesQuestions() const = 0;


    virtual int questionSuivante() = 0;


    virtual void soumettreReponse(int indiceQuestion, bool bonneReponse) = 0;

    virtual bool peutAfficherCorrection(int indiceQuestion) const = 0;
};

#endif

