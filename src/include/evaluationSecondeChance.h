
#ifndef EVALUATION_SECONDE_CHANCE_H
#define EVALUATION_SECONDE_CHANCE_H

#include "strategieEvaluation.h"

/*
 Évaluation Seconde Chance :
 - une question peut être reposée une fois
 - correction affichée après deux erreurs
*/
class evaluationSecondeChance : public strategieEvaluation {
public:
    evaluationSecondeChance();

    void init(int nombreQuestions) override;
    bool aDesQuestions() const override;
    int questionSuivante() override;
    void soumettreReponse(int indiceQuestion, bool bonneReponse) override;
    bool peutAfficherCorrection(int indiceQuestion) const override;
};

#endif
