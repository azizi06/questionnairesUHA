#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>

// Tes includes
#include "../include/evaluation.h"
#include "../include/strategies.h"
#include "../include/questionnaire.h"
#include "../include/questionTexte.h"
#include "../include/affichage.h"
#include "../include/goto_xy_windows.h"

using namespace std;

int main() {

    questionnaire q;
    q.add(make_unique<questionTexte>("Capitale de la France ?", "Paris"));
    q.add(make_unique<questionTexte>("4 * 2 ?", "8"));
    q.add(make_unique<questionTexte>("Couleur du cheval blanc ?", "Blanc"));

    StrategieAdaptative strat; // ou StrategieSecondeChance
    strat.init(3);

    evaluation moteur(&q, &strat);
    affichage ecran;

    // 2. BOUCLE
    moteur.commencer();

    while (moteur.aDesQuestions()) {
        ecran.clearCMD();
        ecran.dessinerCadre(); // Affiche le dessin
        ecran.afficherTitre("QUIZ C++");

        const question* qCourante = moteur.questionCourante();
        if (qCourante) {
            ecran.afficherQuestion(qCourante->Intitule());
        }

        // Saisie
        ecran.placerCurseurSaisie();
        string reponse;
        cin >> reponse;

        // Logique
        bool correct = moteur.repondre(reponse);

        // Feedback
        if (correct) {
            ecran.afficherMessage("BRAVO !");
        } else {
            ecran.afficherMessage("RATE...");
            if (moteur.peutAfficherCorrection()) {
                ecran.afficherReponse(qCourante->getReponseCorrecte());
            }
        }

        moteur.questionSuivante();

        // Pause propre en bas
        goto_xy(0, 18);
        system("pause");
    }

    ecran.clearCMD();
    ecran.dessinerCadre();
    ecran.afficherMessage("FIN DE L'EVALUATION");
    moteur.afficherResultats();

    goto_xy(0, 20);
    return 0;
}
