#include "./include/doctest.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../src/include/apprentissage.h"
#include "../src/include/affichageInterface.h"
#include "../src/include/questionnaire.h"
#include "../src/include/questionTexte.h"

#include <vector>
#include <string>
#include <memory>

class MockAffichage : public affichageInterface {
public:
    mutable std::vector<std::string> logs;

    void clearCMD() const override { logs.push_back("CLEAR"); }
    void afficherTitre(const std::string& t) const override { logs.push_back("TITRE:" + t); }
    void afficherQuestion(const std::string& q) const override { logs.push_back("QUESTION:" + q); }
    void afficherReponse(const std::string& r) const override { logs.push_back("REPONSE:" + r); }
    void afficherMessage(const std::string& m) const override { logs.push_back("MESSAGE:" + m); }

    void attendreTouche() const override { logs.push_back("WAIT"); } // ne bloque pas
};

TEST_CASE("apprentissage affiche chaque question et attend une touche") {
    questionnaire q;
    q.add(std::make_unique<questionTexte>(
        "Quelle est la capitale de la France ?",
        "Paris"
    ));

    MockAffichage mock;
    apprentissage app(q, mock);

    app.apprendre();

    REQUIRE(mock.logs.size() >= 6);
    CHECK(mock.logs[0] == "CLEAR");
    CHECK(mock.logs[1] == "TITRE:Vous etes dans le mode apprentissage");
    CHECK(mock.logs[2] == "QUESTION:Quelle est la capitale de la France ?");
    CHECK(mock.logs[3] == "REPONSE:Paris");
    CHECK(mock.logs[5] == "WAIT");
}
