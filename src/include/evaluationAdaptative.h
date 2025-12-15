
#ifndef EVALUATION_ADAPTATIVE_H
#define EVALUATION_ADAPTATIVE_H

#include "strategieEvaluation.h"

/*
 Évaluation Adaptative :
 - questions posées dans un ordre aléatoire
 - une question mal répondue est reposée à la fin
*/
class evaluationAdaptative : public strategieEvaluation {
public:
    evaluationAdaptative();

    void init(int nombreQuestions) override;
    bool aDesQuestions() const override;
    int questionSuivante() override;
    void soumettreReponse(int indiceQuestion, bool bonneReponse) override;
    bool peutAfficherCorrection(int indiceQuestion) const override;
};

#endif
