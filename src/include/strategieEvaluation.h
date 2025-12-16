#ifndef STRATEGIE_EVALUATION_H
#define STRATEGIE_EVALUATION_H

/*
 Classe abstraite StrategieEvaluation
 -----------------------------------
 Définit le comportement d'une stratégie d'évaluation.
 Les classes concrètes (test, seconde chance, adaptative)
 devront implémenter ces méthodes.
*/


class StrategieEvaluation {
public:
    virtual ~StrategieEvaluation() {}
=======
class strategieEvaluation {
public:
    virtual ~strategieEvaluation() {}
>>>>>>> b93cf47 ( ajout de la classe evaluationTest)

    // Initialiser la stratégie avec le nombre total de questions
    virtual void init(int nombreQuestions) = 0;

    // Indique s'il reste des questions à poser
    virtual bool aDesQuestions() const = 0;

    // Retourne l'indice de la prochaine question à poser
    virtual int questionSuivante() = 0;

    // Informe la stratégie du résultat de la réponse utilisateur
    virtual void soumettreReponse(int indiceQuestion, bool bonneReponse) = 0;

    // Indique si la correction peut être affichée
    virtual bool peutAfficherCorrection(int indiceQuestion) const = 0;
};

#endif

