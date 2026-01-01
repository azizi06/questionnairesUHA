
#include "./include/doctest.h"

#include "../src/include/evaluation.h"
#include "../src/include/strategies.h"
#include "../src/include/questionnaire.h"
#include "../src/include/questionTexte.h"

#include <memory>

TEST_CASE(" Classe Evaluation") {

    questionnaire q;
    q.add(std::make_unique<questionTexte>("Capitale de la France ?", "Paris"));
    q.add(std::make_unique<questionTexte>("2 + 2 ?", "4"));

    StrategieTest strat;
    strat.init(2);

    evaluation e(&q, &strat);
    e.commencer();


    SUBCASE("Scnario : Rponse Correcte") {
        // On v�rifie D'ABORD que le pointeur n'est pas nul avec REQUIRE
        // Si c'est nul, on arr�te, sinon le programme crasherait � la ligne suivante
        REQUIRE(e.questionCourante() != nullptr);

        REQUIRE(e.questionCourante()->Intitule() == "Capitale de la France ?");

        bool resultat = e.repondre("Paris");
        REQUIRE(resultat == true); // Si �a �choue, on arr�te

        e.questionSuivante();

        REQUIRE(e.questionCourante() != nullptr);
        REQUIRE(e.questionCourante()->Intitule() == "2 + 2 ?");
    }

    SUBCASE("Scnario : Mauvaise Rponse") {
        bool resultat = e.repondre("Londres");
        REQUIRE(resultat == false);
    }

    SUBCASE("Scnario : Fin de partie") {
        e.repondre("Paris");
        e.questionSuivante();

        e.repondre("4");
        e.questionSuivante();

        // On exige qu'il n'y ait plus de questions
        REQUIRE(e.aDesQuestions() == false);
    }
}
