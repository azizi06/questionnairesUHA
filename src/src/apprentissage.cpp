#include "apprentissage.h"
#include <conio.h>

apprentissage::apprentissage(const questionaire& questionaire): d_questionaire(questionaire)
{}

void apprentissage::apprendre() const {

    questionairIeIterator iterateur{d_questionaire};
    while (iterateur.hasNext()) {
        const question& q = iterateur.next();

        d_affichage.nettoyerCMD();
        d_affichage.afficherTitre("Vous etes dans le mode apprentissage");

        d_affichage.afficherQuestion(q.Intitule());
        d_affichage.afficherReponse(q.getReponseCorrecte());

        d_affichage.afficherMessage("Appuyez sur une touche pour voir la prochaine");
        getch(); }
}
