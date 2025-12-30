#include"doctest.h"
#include "../src/include/questionnaireDeserialisateurTexte.h"
#include <sstream>

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

    }
    SUBCASE("question numérique est lit correctement"){

    }
    SUBCASE("question choix multiple est lit correctement"){

    }
}
