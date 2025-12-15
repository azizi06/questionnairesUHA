#ifndef EVALUATION_TEST_H
#define EVALUATION_TEST_H

#include "strategieEvaluation.h"

/*
 Évaluation Test :
 - questions dans l'ordre
 - une seule tentative
 - pas d'affichage de la correction
*/
class evaluationTest : public strategieEvaluation {
public:
    evaluationTest();

    void init(int nombreQuestions) override;
    bool aDesQuestions() const override;
    int questionSuivante() override;
    void soumettreReponse(int indiceQuestion, bool bonneReponse) override;
    bool peutAfficherCorrection(int indiceQuestion) const override;
};

#endif

