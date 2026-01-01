#include "./include/doctest.h"
#include "../src/include/questionTexte.h"
#include "../src/include/questionNumerique.h"
#include "../src/include/questionChoixMultiple.h"

// On regroupe tous les tests des questions ici
TEST_CASE("Tests unitaires des classes de questions") {

    //tEST pour les question text
    SUBCASE("Test de QuestionTexte") {
        questionTexte q{"Quelle est la capitale de la France ?", "Paris"};

        //Verifier si on accepte la bonne reponse
        REQUIRE(q.estBonneReponse("Paris") == true);

        // verifier si on refuse la mauvaise reponse
        REQUIRE(q.estBonneReponse("Lyon") == false);

        //verifie que notre methode renvoi exactement la meme chaine de caractere
        REQUIRE(q.getReponseCorrecte() == "Paris");
    }

    //Test pour les questions numerique
    SUBCASE("Test de QuestionNumerique") {
        // Question:5+5=10, entre 0 et 20
        questionNumerique Qnum{"Combien font 5 + 5 ?", 10, 0, 20};

        // Verif de la reponse juste
        REQUIRE(Qnum.estBonneReponse("10") == true);

        // Test de si utilisateur ecrit du text au lieu de chiffres
        // Ca ne doit pas planter le programme (grace au try-catch dans le .cpp)
        CHECK(Qnum.estBonneReponse("abc") == false);
    }

    // Test pour QCM
    SUBCASE("Test de QuestionChoixMultiple") {
        std::vector<std::string> options = {"Bleu","Rouge", "Vert"};
        // On dit que la bonne reponse est l'index 1 (Rouge)
        questionChoixMultiple qcm{"Quelle est la couleur du sang ?", options, 1};

        // On verifie que l'utilisateur doit taper "1" pour avoir juste
        REQUIRE(qcm.estBonneReponse("1") == true);

        // Verif que l'index 0 est faux
        REQUIRE(qcm.estBonneReponse("0") == false);
    }
}
