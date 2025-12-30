#include "../include/apprentissage.h"
#include <conio.h>

apprentissage::apprentissage(const questionnaire& questionnaire)
    : d_questionnaire(questionnaire)
{}

void apprentissage::apprendre() const {

    for (int i = 0; i < d_questionnaire.taille(); i++) {

        const question* q = d_questionnaire.getQuestionNumero(i);

        d_affichage.clearCMD();
        d_affichage.afficherTitre("Vous etes dans le mode apprentissage");
        d_affichage.afficherQuestion(q->Intitule());
        d_affichage.afficherReponse(q->getReponseCorrecte());
        d_affichage.afficherMessage("Appuyez sur une touche pour voir la prochaine");

        getch();
    }
}
