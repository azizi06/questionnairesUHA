#include "../include/apprentissage.h"


apprentissage::apprentissage(const questionnaire* questionnaire,affichageInterface* a): d_questionnaire(questionnaire),d_affichage{a}{
}

void apprentissage::apprendre()  {
    for (int i = 0; i < d_questionnaire->taille(); i++) {

        const question* q = d_questionnaire->getQuestionNumero(i);

        d_affichage->clearCMD();
        d_affichage->afficherTitre("Vous etes dans le mode apprentissage");
        d_affichage->afficherQuestion(q->Intitule());
        d_affichage->afficherReponse(q->getReponseCorrecte());
        d_affichage->afficherMessage("Appuyez sur une touche pour voir la prochaine");

        d_affichage->attendreTouche(); //remplace getch()
    }
}
