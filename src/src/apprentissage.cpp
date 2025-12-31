#include "../include/apprentissage.h"
#include <iostream>
#include <cstdlib> // Pour system("pause")

using namespace std;

apprentissage::apprentissage(const questionnaire& questionnaire)
    : d_questionnaire(questionnaire)
{}

void apprentissage::apprendre() const {
    // On utilise une boucle simple de 0 à la taille du questionnaire
    for (int i = 0; i < d_questionnaire.taille(); ++i) {

        // On récupère la question numéro i
        const question* q = d_questionnaire.getQuestionNumero(i);

        // 1. Mise en page
        d_affichage.clearCMD();
        d_affichage.dessinerCadre();
        d_affichage.afficherTitre("MODE REVISION");

        // 2. Affichage
        if (q != nullptr) {
            d_affichage.afficherQuestion(q->Intitule());
            // On donne la réponse directement
            d_affichage.afficherReponse(q->getReponseCorrecte());
        }

        // 3. Pause
        d_affichage.afficherMessage("Appuyez sur une touche pour continuer...");

        // Pause propre (tu peux remettre getch() si tu preferes)
        // goto_xy(0, 18);
        system("pause");
    }
}
