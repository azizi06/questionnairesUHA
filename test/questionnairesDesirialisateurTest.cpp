#include"doctest.h"
#include "../src/include/questionnaireDeserialisateurTexte.h"
#include <sstream>
#include <stdexcept>
TEST_CASE("[questionnaireDeserialisateurTexte] methodes de la classe fonctionne"){
    SUBCASE("lirestring() foctionne"){
        std::string input = "[Titre du questionnaire]";
        std::istringstream iss(input);
        questionnaireDeserialisateurTexte deserialisateur(iss);
        REQUIRE_EQ(deserialisateur.lireString() ,"Titre du questionnaire");
    }
    SUBCASE("lireString() - ligne vide") {
        std::string input = "";
        std::istringstream iss(input);
        questionnaireDeserialisateurTexte deserialisateur(iss);
        REQUIRE_EQ(deserialisateur.lireString(), "");
    }


}
TEST_CASE("questions sont lit correctement"){
    SUBCASE("question text est lit correctement"){
        std::string input = "{\n[Quelle est la capitale de la France?]\n[Paris]\n}\n";
        std::istringstream iss(input);
        questionnaireDeserialisateurTexte deserialisateur(iss);
        questionTexte q = deserialisateur.lireQuestionTexte();
        REQUIRE_EQ(q.Intitule(),"Quelle est la capitale de la France?");
        REQUIRE_EQ(q.getReponseCorrecte(),"Paris");

    }
    SUBCASE("question text est lit corrextement avec des espaces"){
        std::string input = "{\n[  Question avec des espaces  ]\n[  Réponse avec espaces  ]\n}\n";
        std::istringstream iss(input);
        questionnaireDeserialisateurTexte deserialisateur(iss);
        questionTexte q = deserialisateur.lireQuestionTexte();
        REQUIRE_EQ(q.Intitule(),"  Question avec des espaces  ");
        REQUIRE_EQ(q.getReponseCorrecte(),"  Réponse avec espaces  ");
    }
    SUBCASE("question numérique est lit correctement"){
        std::string input = "{\n[c'est quoi la temperature moyenne de mois decembre en france?]\n[12]\n[10]\n[14]\n}\n";
        std::istringstream iss(input);
        questionnaireDeserialisateurTexte deserialisateur(iss);
        questionNumerique q = deserialisateur.lireQuestionNumerique();

        REQUIRE_EQ(q.Intitule(),"c'est quoi la temperature moyenne de mois decembre en france?");
        REQUIRE_EQ(q.getReponseCorrecte(), "12");
    }
    SUBCASE("question choix multiple est lit correctement"){

    }
}
