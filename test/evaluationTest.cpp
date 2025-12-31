#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/evaluation.h"
#include "../include/strategies.h"


#include "../include/questionnaire.h"
#include "../include/questionTexte.h"

#include <memory>

TEST_CASE(" Classe Evaluation") {

    questionnaire q;
    q.add(std::make_unique<questionTexte>("Capitale de la France ?", "Paris"));
    q.add(std::make_unique<questionTexte>("2 + 2 ?", "4"));

    StrategieTest strat;
    strat.init(2);

    evaluation e(&q, &strat);
    e.commencer();


    SUBCASE("Scénario : Réponse Correcte") {
        // On vérifie D'ABORD que le pointeur n'est pas nul avec REQUIRE
        // Si c'est nul, on arrête, sinon le programme crasherait à la ligne suivante
        REQUIRE(e.questionCourante() != nullptr);

        REQUIRE(e.questionCourante()->Intitule() == "Capitale de la France ?");

        bool resultat = e.repondre("Paris");
        REQUIRE(resultat == true); // Si ça échoue, on arrête

        e.questionSuivante();

        REQUIRE(e.questionCourante() != nullptr);
        REQUIRE(e.questionCourante()->Intitule() == "2 + 2 ?");
    }

    SUBCASE("Scénario : Mauvaise Réponse") {
        bool resultat = e.repondre("Londres");
        REQUIRE(resultat == false);
    }

    SUBCASE("Scénario : Fin de partie") {
        e.repondre("Paris");
        e.questionSuivante();

        e.repondre("4");
        e.questionSuivante();

        // On exige qu'il n'y ait plus de questions
        REQUIRE(e.aDesQuestions() == false);
    }
}
