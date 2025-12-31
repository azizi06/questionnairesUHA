#include"./include/doctest.h"
#include"../src/include/questionnaire.h"
#include"../src/include/question.h"
#include"../src/include/questionTexte.h"
TEST_CASE("[questionnaire] questionnaire est créé correctement"){
    questionnaire quest{};
    SUBCASE("titre est créé correctement"){
        std::string strTitre{};
        REQUIRE_EQ(strTitre,quest.titre());
    }
    SUBCASE("vecteur de questions est créé correctement"){
        int taille{0};
        REQUIRE_EQ(taille,quest.taille());
    }
}

TEST_CASE("[questionnaire] methodes fonctionne correctement"){
    questionnaire quest{};
    std::string intitule{"c'est quoi la plus grande ville en france ?"};
    std::string reponse{"paris"};

    SUBCASE("questions sont ajoutées correctement"){
        auto q = std::make_unique<questionTexte>(intitule,reponse);
        quest.add(std::move(q));
        REQUIRE_EQ(intitule,quest.getQuestionNumero(0)->Intitule());
        REQUIRE_EQ(reponse,quest.getQuestionNumero(0)->getReponseCorrecte());


    }
    SUBCASE("le nombre des questions est retourné correctement"){
        int nbQuestion = 4;
        std::string intitule{""};
        auto q1 = std::make_unique<questionTexte>(intitule,reponse);
        auto q2 = std::make_unique<questionTexte>(intitule,reponse);
        auto q3 = std::make_unique<questionTexte>(intitule,reponse);
        auto q4 = std::make_unique<questionTexte>(intitule,reponse);

        quest.add(std::move(q1));
        quest.add(std::move(q2));
        quest.add(std::move(q3));
        quest.add(std::move(q4));

        REQUIRE_EQ(nbQuestion,quest.taille());
    }
    SUBCASE("le titre est defini correctement"){
        std::string titre{"questionnaire geographique"};
        quest.setTitre(titre);
        REQUIRE_EQ(titre,quest.titre());
    }
}
