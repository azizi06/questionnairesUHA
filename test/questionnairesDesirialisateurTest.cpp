#include"./include/doctest.h"
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
    SUBCASE("trim() - fonctione") {
        std::string input = "paris,mulhouse,basel,lyon";
        std::istringstream iss(input);
        questionnaireDeserialisateurTexte deserialisateur(iss);
        std::vector<std::string>  villes= {"paris","mulhouse","basel","lyon"};
        REQUIRE_EQ(villes.size(),4);
        REQUIRE_EQ(villes,deserialisateur.trim(input,SEPARATEUR));
    }
    SUBCASE("determineTypeObjet() - determine le type d'objet correctement "){
        std::string input = "";
        std::istringstream iss(input);
        questionnaireDeserialisateurTexte deserialisateur(iss);
        std::string qT{"QT \n"};
        std::string qN{"QN \n"};
        std::string qC{"QC\n"};
        REQUIRE_EQ(deserialisateur.determinerTypeObjet(qT),QT);
        REQUIRE_EQ(deserialisateur.determinerTypeObjet(qN),QN);
        REQUIRE_EQ(deserialisateur.determinerTypeObjet(qC),QC);


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
        std::string input = "{\n[Quelle est la capitale de la France?]\n[Paris,Londres,Berlin,Madrid]\n[1]\n}\n";
        std::istringstream iss(input);
        questionnaireDeserialisateurTexte deserialisateur(iss);

        questionChoixMultiple q = deserialisateur.lireQuestionChoixMultiple();
        REQUIRE_EQ(q.Intitule(),"Quelle est la capitale de la France?");
        REQUIRE_EQ(q.getReponseCorrecte(),"1");
    }
}
TEST_CASE("[questionnaireDeserialisateurTexte] lire une questionnaire correctement"){
    SUBCASE("lire questionaire()"){
        std::string input = "[questionaire]\nQT\n{\n[Question 01]\n[Réponse]\n}\nQC\n{\n[Quelle est la capitale de la France?]\n[Paris,Londres,Berlin,Madrid]\n[1]\n}\n";
        std::istringstream iss(input);
        questionnaireDeserialisateurTexte deserialisateur(iss);
        auto quest = deserialisateur.lire();

        REQUIRE_EQ(quest.titre(),"questionaire");
        REQUIRE_EQ(quest.getQuestionNumero(0)->Intitule(),"Question 01");
        REQUIRE_EQ(quest.getQuestionNumero(0)->getReponseCorrecte(),"Réponse");


        REQUIRE_EQ(quest.getQuestionNumero(1)->Intitule(),"Quelle est la capitale de la France?");
        REQUIRE_EQ(quest.getQuestionNumero(1)->getReponseCorrecte(),"1");


    }
}
