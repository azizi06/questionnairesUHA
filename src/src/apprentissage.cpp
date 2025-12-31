#include "../include/apprentissage.h"
#include "../include/questionnaireIterator.h"
#include <iostream>
#include <cstdlib> // Pour system("pause")

using namespace std;

apprentissage::apprentissage(const questionnaire& questionnaire)
    : d_questionnaire(questionnaire)
{}

void apprentissage::apprendre() const {
    questionnaireIterator iterateur{d_questionnaire};

    while (iterateur.hasNext()) {
        const question* q = iterateur.next();


        d_affichage.clearCMD();
        d_affichage.dessinerCadre();
        d_affichage.afficherTitre("MODE APPRENTISSAGE");


        d_affichage.afficherQuestion(q->Intitule());


        d_affichage.afficherReponse(q->getReponseCorrecte());

        d_affichage.afficherMessage("Appuyez sur une touche pour continuer...");

        system("pause");
    }
}
