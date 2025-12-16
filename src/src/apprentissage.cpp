#include "apprentissage.h"
#include <conio.h>

apprentissage::apprentissage(const questionnaire& questionnaire)
     : d_questionnaire(questionnaire)
{}

void apprentissage::apprendre() const {

    for (const auto& q : d_questionnaire){

        d_affichage.clearCMD();
        d_affichage.afficherTitre("Vous etes dans le mode apprentissage");

        d_affichage.afficherQuestion(q->Intitule());
        d_affichage.afficherReponse(q->getReponseCorrecte());

        d_affichage.afficherMessage("Appuyez sur une touche pour voir la prochaine");
        getch();
    }
}



