#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/strategies.h"

#include <vector>
#include <string>

TEST_CASE("1. Test des Stratégies") {

    SUBCASE("Stratégie TEST : Avance toujours") {
        StrategieTest strat;
        strat.init(2); // 2 questions simulées

        REQUIRE(strat.aDesQuestions() == true);
        REQUIRE(strat.questionSuivante() == 0);
        strat.soumettreReponse(0, false);
        REQUIRE(strat.questionSuivante() == 1);


        REQUIRE(strat.peutAfficherCorrection(0) == false);
    }

    SUBCASE("Stratégie SECONDE CHANCE : Logique de répétition") {
        StrategieSecondeChance strat;
        strat.init(5);

        // Premier essai raté sur la question 0
        REQUIRE(strat.questionSuivante() == 0);
        strat.soumettreReponse(0, false);

        // Doit redonner la question 0 (index ne bouge pas)
        REQUIRE(strat.questionSuivante() == 0);
        REQUIRE(strat.peutAfficherCorrection(0) == false);

        // Deuxième essai raté
        strat.soumettreReponse(0, false);


        REQUIRE(strat.questionSuivante() == 1);
        // On affiche la correction car on a raté 2 fois
        REQUIRE(strat.peutAfficherCorrection(0) == true);
    }

    SUBCASE("Stratégie ADAPTATIVE : Réinsertion") {
        StrategieAdaptative strat;
        strat.init(1);

        int id = strat.questionSuivante();

        strat.soumettreReponse(id, false);

        // Comme c'est raté, elle doit être toujours dispo (remise à la fin)
        REQUIRE(strat.aDesQuestions() == true);


        int id2 = strat.questionSuivante();
        strat.soumettreReponse(id2, true);


        REQUIRE(strat.aDesQuestions() == false);
    }
}
