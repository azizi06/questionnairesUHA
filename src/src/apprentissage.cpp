#include "Apprentissage.h"
#include <conio.h> // getch()

Apprentissage::Apprentissage(const Questionnaire& questionnaire)
    : d_questionnaire(questionnaire)
{
}

void Apprentissage::demarrer() const
{
    for (size_t i = 0; i < d_questionnaire.getNombreQuestions(); ++i)
    {
        d_affichage.nettoyer();
        d_affichage.afficherTitre("Mode Apprentissage");

        question* q = d_questionnaire.getQuestion(i);

        // Affichage de la question
        d_affichage.afficherQuestion(q->Intitule());
        d_affichage.afficherMessage(q->Texte());

        // Affichage de la réponse correcte
        d_affichage.afficherReponse(q->getReponseCorrecte());

        d_affichage.afficherMessage("Appuyez sur une touche pour continuer...");
        getch();
    }
}

