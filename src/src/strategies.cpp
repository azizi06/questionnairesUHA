
#include "../include/strategies.h" // Adapte le chemin selon tes dossiers
#include <algorithm> // Pour std::shuffle
#include <random>    // Pour le générateur aléatoire
#include <ctime>     // Pour initialiser l'aléatoire

// ==========================================
// 1. IMPLEMENTATION TEST
// ==========================================
void StrategieTest::init(int nombreQuestions) {
    d_courant = 0;
    d_total = nombreQuestions;
}

bool StrategieTest::aDesQuestions() const {
    // Tant que l'index courant est inférieur au total, il reste des questions
    return d_courant < d_total;
}

int StrategieTest::questionSuivante() {
    // On renvoie l'index actuel et on prépare le suivant (+1)
    return d_courant++;
}

void StrategieTest::soumettreReponse(int indiceQuestion, bool bonneReponse) {
    // En mode Test, on s'en fiche si c'est juste ou faux, on avance quand même.
    // Donc rien à faire ici.
}

bool StrategieTest::peutAfficherCorrection(int indiceQuestion) const {
    // En mode Test, on ne montre JAMAIS la réponse.
    return false;
}

// ==========================================
// 2. IMPLEMENTATION SECONDE CHANCE
// ==========================================
void StrategieSecondeChance::init(int nombreQuestions) {
    d_courant = 0;
    d_total = nombreQuestions;
    d_deuxiemeEssai = false;
    d_afficherCorrection = false;
}

bool StrategieSecondeChance::aDesQuestions() const {
    return d_courant < d_total;
}

int StrategieSecondeChance::questionSuivante() {
    // On renvoie simplement l'index courant.
    // Si on a raté, d_courant n'aura pas changé, donc on reposera la même question.
    return d_courant;
}

void StrategieSecondeChance::soumettreReponse(int indiceQuestion, bool bonneReponse) {
    d_afficherCorrection = false; // Reset

    if (bonneReponse) {
        // C'est juste : on passe à la suivante, on n'est plus en "deuxième essai"
        d_courant++;
        d_deuxiemeEssai = false;
    } else {
        // C'est faux
        if (!d_deuxiemeEssai) {
            // C'était le premier coup -> On active le mode "deuxième essai"
            // On NE change PAS d_courant pour que la question soit reposée.
            d_deuxiemeEssai = true;
        } else {
            // C'était déjà le deuxième coup -> Tant pis, on passe à la suivante
            d_courant++;
            d_deuxiemeEssai = false;
            d_afficherCorrection = true; // Là on a le droit de voir la réponse
        }
    }
}

bool StrategieSecondeChance::peutAfficherCorrection(int indiceQuestion) const {
    return d_afficherCorrection;
}

// ==========================================
// 3. IMPLEMENTATION ADAPTATIVE
// ==========================================
void StrategieAdaptative::init(int nombreQuestions) {
    d_fileQuestions.clear();

    // 1. On remplit la liste avec 0, 1, 2... jusqu'à la fin
    for (int i = 0; i < nombreQuestions; ++i) {
        d_fileQuestions.push_back(i);
    }

    // 2. On mélange aléatoirement la liste
    std::srand(std::time(0));
    std::random_shuffle(d_fileQuestions.begin(), d_fileQuestions.end());
}

bool StrategieAdaptative::aDesQuestions() const {
    return !d_fileQuestions.empty();
}

int StrategieAdaptative::questionSuivante() {
    // On regarde la première question de la liste
    int question = d_fileQuestions.front();
    return question;
}

void StrategieAdaptative::soumettreReponse(int indiceQuestion, bool bonneReponse) {
    // On retire la question qu'on vient de poser (elle est au début)
    d_fileQuestions.erase(d_fileQuestions.begin());

    if (!bonneReponse) {
        // Si c'est faux, on la remet TOUT A LA FIN de la liste
        d_fileQuestions.push_back(indiceQuestion);
    }
    // Si c'est juste, elle est déjà supprimée, donc on ne la revoit plus.
}

bool StrategieAdaptative::peutAfficherCorrection(int indiceQuestion) const {
    // En adaptatif, comme on va revoir la question plus tard,
    // il vaut mieux ne pas donner la réponse tout de suite.
    return false;
}
