#include <iostream>
#include <memory>

#include "./include/questionnaire.h"
#include "./include/questionTexte.h"
#include "./include/questionNumerique.h"
#include "./include/questionChoixMultiple.h"
#include "./include/apprentissage.h"

using namespace std;

void testApprentissage()
{
    questionnaire q;
    q.setTitre("Questionnaire de test");

    // Question texte
    q.add(make_unique<questionTexte>(
        "Quelle est la capitale de la France ?",
        "Paris"
    ));

    // Question numérique
    q.add(make_unique<questionNumerique>(
        "Combien font 6 x 7 ?",
        42,
        0,
        100
    ));

    // Question à choix multiple
    vector<string> options = {
        "Rouge",
        "Vert",
        "Bleu"
    };

    q.add(make_unique<questionChoixMultiple>(
        "Quelle est la couleur du ciel par temps clair ?",
        options,
        3   // réponse correcte = option 3 (Bleu)
    ));

    // Lancement du mode apprentissage
    apprentissage app(q);
    app.apprendre();
}

int main()
{
    testApprentissage();
    return 0;
}
