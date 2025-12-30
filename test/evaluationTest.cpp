#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Tes classes
#include "../include/evaluation.h"
#include "../include/strategies.h"

// Les classes nécessaires pour remplir les données
#include "../include/questionnaire.h"
#include "../include/questionTexte.h" // <--- OBLIGATOIRE pour créer une question

#include <memory> // Pour std::make_unique

TEST_CASE("Test Unitaire : Evaluation (avec QuestionTexte)") {

    // 1. ARRANGE (Préparation)
    questionnaire q;

    // On est obligé d'utiliser QuestionTexte car Question est abstraite
    // Je suppose que le constructeur est (Intitulé, Réponse)
    q.add(std::make_unique<QuestionTexte>("Capitale de la France ?", "Paris"));
    q.add(std::make_unique<QuestionTexte>("Couleur du cheval blanc ?", "Blanc"));

    StrategieTest strat;
    strat.init(2);

    evaluation e(&q, &strat);
    e.commencer();

    // 2. ACT & ASSERT (Test)

    SUBCASE("Répondre Juste") {
        // La question est "Capitale de la France ?", la réponse attendue est "Paris"
        // C'est QuestionTexte qui va faire la comparaison
        bool resultat = e.repondre("Paris");

        CHECK(resultat == true);
    }

    SUBCASE("Répondre Faux") {
        bool resultat = e.repondre("Berlin");
        CHECK(resultat == false);
    }
}
