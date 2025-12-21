#include "../include/apprentissage.h"
#include <conio.h>
#include"../include/questionnaireIterator.h"


apprentissage::apprentissage(const questionnaire& questionnaire): d_questionnaire(questionnaire)
{}

void apprentissage::apprendre() const {

    questionnaireIterator iterateur{d_questionnaire};
      while (iterateur.hasNext()) { //Methode qui sera definie dans le code de Azizi
         const question* q = iterateur.next(); //Methode qui sera definie dans le code de Azizi

         d_affichage.clearCMD();
         d_affichage.afficherTitre("Vous etes dans le mode apprentissage");
         d_affichage.afficherQuestion(q->Intitule());
         d_affichage.afficherReponse(q->getReponseCorrecte());
         d_affichage.afficherMessage("Appuyez sur une touche pour voir la prochaine");
         getch(); }
}
