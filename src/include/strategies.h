
#ifndef STRATEGIES_H
#define STRATEGIES_H

#include "strategieEvaluation.h"
#include <vector>

// --- 1. Stratégie Test (Classique) ---
// Pose les questions dans l'ordre, une seule fois, pas de correction affichée.
class StrategieTest : public strategieEvaluation {
private:
    int d_courant; // Numéro de la question actuelle
    int d_total;   // Nombre total de questions

public:
    void init(int nombreQuestions) override;
    bool aDesQuestions() const override;
    int questionSuivante() override;
    void soumettreReponse(int indiceQuestion, bool bonneReponse) override;
    bool peutAfficherCorrection(int indiceQuestion) const override;
};

// --- 2. Stratégie Seconde Chance ---
// Si on rate, on repose la même question une fois.
class StrategieSecondeChance : public strategieEvaluation {
private:
    int d_courant;
    int d_total;
    bool d_deuxiemeEssai;      // Est-ce qu'on est en train de retenter ?
    bool d_afficherCorrection; // Droit d'afficher la correction ?

public:
    void init(int nombreQuestions) override;
    bool aDesQuestions() const override;
    int questionSuivante() override;
    void soumettreReponse(int indiceQuestion, bool bonneReponse) override;
    bool peutAfficherCorrection(int indiceQuestion) const override;
};

// --- 3. Stratégie Adaptative ---
// Ordre aléatoire. Si on rate, la question retourne à la fin de la file.
class StrategieAdaptative : public strategieEvaluation {
private:
    std::vector<int> d_fileQuestions; // Liste des index des questions à poser

public:
    void init(int nombreQuestions) override;
    bool aDesQuestions() const override;
    int questionSuivante() override;
    void soumettreReponse(int indiceQuestion, bool bonneReponse) override;
    bool peutAfficherCorrection(int indiceQuestion) const override;
};

#endif
