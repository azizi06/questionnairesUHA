#include "./include/doctest.h"

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

    REQUIRE_EQ(mock.logs[0], "CLEAR");
    REQUIRE_EQ(mock.logs[1], "TITRE:Vous etes dans le mode apprentissage");
    REQUIRE_EQ(mock.logs[2], "QUESTION:Quelle est la capitale de la France ?");
    REQUIRE_EQ(mock.logs[3], "REPONSE:Paris");
    REQUIRE_EQ(mock.logs[5], "WAIT");
}
