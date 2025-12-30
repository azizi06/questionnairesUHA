
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Inclusions de TES classes

#include "strategies.h"
#include "questionnaire.h"
#include "question.h"
#include "evaluation.h"
#include <vector>
#include <string>


TEST_CASE("1. Test des Stratégies ") {

    SUBCASE("Stratégie TEST : Avance toujours") {
        StrategieTest strat;
        strat.init(2); // 2 questions simulées

        CHECK(strat.aDesQuestions() == true);
        CHECK(strat.questionSuivante() == 0); // Q1

        strat.soumettreReponse(0, false); // Faux
        CHECK(strat.questionSuivante() == 1); // Passe quand même à Q2

        CHECK(strat.peutAfficherCorrection(0) == false); // Jamais de correction
    }

    SUBCASE("Stratégie SECONDE CHANCE : Logique de répétition") {
        StrategieSecondeChance strat;
        strat.init(5);

        // Premier essai raté sur la question 0
        CHECK(strat.questionSuivante() == 0);
        strat.soumettreReponse(0, false);

        // Doit redonner la question 0 (index ne bouge pas)
        CHECK(strat.questionSuivante() == 0);
        CHECK(strat.peutAfficherCorrection(0) == false); // Pas d'aide au 2eme essai

        // Deuxième essai raté
        strat.soumettreReponse(0, false);

        // Là on avance à la question 1
        CHECK(strat.questionSuivante() == 1);
        CHECK(strat.peutAfficherCorrection(0) == true); // On affiche la correction
    }

    SUBCASE("Stratégie ADAPTATIVE : Réinsertion") {
        StrategieAdaptative strat;
        strat.init(1); // 1 seule question pour tester la boucle

        int id = strat.questionSuivante();

        // On se trompe
        strat.soumettreReponse(id, false);

        // Comme c'est raté, elle doit être toujours dispo (remise à la fin)
        CHECK(strat.aDesQuestions() == true);

        // On la réussit
        int id2 = strat.questionSuivante();
        strat.soumettreReponse(id2, true);

        // Maintenant c'est fini
        CHECK(strat.aDesQuestions() == false);
    }
}
