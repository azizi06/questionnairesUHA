

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Inclusions de TES classes
#include "evaluation.h"
#include "strategies.h"
#include "questionnaire.h"
#include "question.h"
#include <vector>
#include <string>

TEST_CASE("2. Test de ta classe Evaluation") {
    // Préparation des fausses données (Mock)
    questionnaire qMock;
    qMock.ajouter("A"); // Réponse attendue "A" pour question 0
    qMock.ajouter("B"); // Réponse attendue "B" pour question 1

    StrategieTest stratTest; // On utilise ta stratégie simple

    // Ton objet Evaluation
    evaluation e(&qMock, &stratTest);

    // IMPORTANT : On doit lancer commencer() pour initialiser la stratégie
    e.commencer();

    SUBCASE("Scénario : Réponse Correcte") {
        // On est à la question 0, la réponse attendue est "A"
        bool resultat = e.repondre("A");

        CHECK(resultat == true);

        // On vérifie que ta classe a bien avancé
        e.questionSuivante();
        const question* prochaine = e.questionCourante();
        CHECK(prochaine != nullptr); // On est bien passé à la suite
    }

    SUBCASE("Scénario : Mauvaise Réponse") {
        // On envoie "Z" alors qu'il attend "A"
        bool resultat = e.repondre("Z");

        CHECK(resultat == false);
    }

    SUBCASE("Scénario : Fin du questionnaire") {
        e.repondre("A"); // Q0 OK
        e.questionSuivante();

        e.repondre("B"); // Q1 OK
        e.questionSuivante();

        CHECK(e.aDesQuestions() == false);
    }
}
