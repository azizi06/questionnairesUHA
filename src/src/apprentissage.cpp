#include "apprentissage.h"
#include <conio.h>

apprentissage::apprentissage(const questionnaire& questionnaire)
     : d_questionnaire(questionnaire)
{}

void apprentissage::apprendre() const {

    for (const auto& q : d_questionnaire){

        d_affichage.nettoyer();
        d_affichage.afficherTitre("Mode Apprentissage");

        d_affichage.afficherQuestion(q->Intitule());
        d_affichage.afficherReponse(q->getReponseCorrecte());

        d_affichage.afficherMessage("Appuyez sur une touche pour continuer...");
        getch();
    }
}



