#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
#include <fstream>
#include "include/evaluation.h"
#include "include/strategies.h"
#include "include/affichage.h"
#include "include/goto_xy_windows.h"
#include "./include/questionnaire.h"
#include "./include/questionTexte.h"
#include "./include/questionNumerique.h"
#include "./include/questionChoixMultiple.h"
#include "./include/apprentissage.h"
#include "./include/questionnaireDeserialisateurTexte.h"
#include"./include/gestionnaire.h"

using namespace std;



void pauseJeu() {
    goto_xy(2, 17);
    system("pause");
}

void testApprentissage()
{
    questionnaire q;
    q.setTitre("Questionnaire de test");

    // Question texte
    q.add(make_unique<questionTexte>(
        "Quelle est la capitale de la France ?",
        "Paris"
    ));

    // Question num�rique
    q.add(make_unique<questionNumerique>(
        "Combien font 6 x 7 ?",
        42,
        0,
        100
    ));

    // Question � choix multiple
    vector<string> options = {
        "Rouge",
        "Vert",
        "Bleu"
    };

    q.add(make_unique<questionChoixMultiple>(
        "Quelle est la couleur du ciel par temps clair ?",
        options,
        3   // r�ponse correcte = option 3 (Bleu)
    ));

    // Lancement du mode apprentissage

    apprentissage app(q);
    app.apprendre();
}
void testEvaluation(){

 // =========================================================
    // 1. BASE DE DONN�ES (QUESTIONS)
    // =========================================================
    questionnaire q;
    q.add(make_unique<questionTexte>("Capitale de la France ?", "Paris"));
    q.add(make_unique<questionTexte>("5 * 5 ?", "25"));
    q.add(make_unique<questionTexte>("Mot cle pour l'heritage ?", "public"));
    q.add(make_unique<questionTexte>("Animal qui miaule ?", "Chat"));

    // Ajoute d'autres questions ici si tu veux...

    affichage ecran;
    int choixMenu = 0;

    // =========================================================
    // 2. BOUCLE PRINCIPALE
    // =========================================================
    do {
        // --- AFFICHAGE MENU PRINCIPAL ---
        ecran.clearCMD();
        ecran.dessinerCadre();
        ecran.afficherTitre("MENU PRINCIPAL");

        goto_xy(10, 6); cout << "1. MODE REVISION (Apprentissage)";
        goto_xy(10, 8); cout << "2. MODE EXAMEN (Evaluation)";
        goto_xy(10, 10); cout << "3. QUITTER";

        ecran.placerCurseurSaisie();
        cin >> choixMenu;

        // -----------------------------------------------------
        // CAS 1 : APPRENTISSAGE
        // -----------------------------------------------------
        if (choixMenu == 1) {
            apprentissage session(q);
            session.apprendre(); // Lance le mode r�vision

            ecran.clearCMD();
            ecran.dessinerCadre();
            ecran.afficherMessage("Revision terminee !");
            pauseJeu();
        }

        // -----------------------------------------------------
        // CAS 2 : EVALUATION (EXAMEN)
        // -----------------------------------------------------
        else if (choixMenu == 2) {

            // --- SOUS-MENU : CHOIX DE LA STRAT�GIE ---
            ecran.clearCMD();
            ecran.dessinerCadre();
            ecran.afficherTitre("CHOIX DE LA STRATEGIE");

            goto_xy(5, 6); cout << "1. CLASSIQUE (Lineaire, pas d'aide)";
            goto_xy(5, 8); cout << "2. SECONDE CHANCE (2 essais autorises)";
            goto_xy(5, 10); cout << "3. ADAPTATIVE (Repose les questions ratees)";

            ecran.placerCurseurSaisie();
            int choixStrat;
            cin >> choixStrat;

            // --- CR�ATION DYNAMIQUE DE LA STRAT�GIE ---
            // C'est ici que le polymorphisme op�re !
            strategieEvaluation* maStrategie = nullptr;

            if (choixStrat == 1) {
                maStrategie = new StrategieTest(); // Ou StrategieClassique selon tes noms
            } else if (choixStrat == 2) {
                maStrategie = new StrategieSecondeChance();
            } else {
                maStrategie = new StrategieAdaptative();
            }

            // Initialisation de la strat�gie choisie
            maStrategie->init(q.taille());

            // --- LANCEMENT DU MOTEUR ---
            evaluation moteur(&q, maStrategie);
            moteur.commencer();

            // Boucle de jeu (Examen)
            while (moteur.aDesQuestions()) {
                ecran.clearCMD();
                ecran.dessinerCadre();
                ecran.afficherTitre("MODE EXAMEN");

                // Affichage question
                const question* qCourante = moteur.questionCourante();
                if (qCourante) {
                    ecran.afficherQuestion(qCourante->Intitule());
                }

                // Saisie
                ecran.placerCurseurSaisie();
                string reponseUtilisateur;
                cin >> reponseUtilisateur;

                // V�rification
                bool estCorrect = moteur.repondre(reponseUtilisateur);

                // Feedback
                if (estCorrect) {
                    ecran.afficherMessage("BRAVO ! Bonne reponse.");
                } else {
                    ecran.afficherMessage("RATE...");

                    // Si la strat�gie choisie autorise la correction
                    if (moteur.peutAfficherCorrection()) {
                        ecran.afficherReponse(qCourante->getReponseCorrecte());
                    }
                }

                moteur.questionSuivante();
                pauseJeu();
            }

            // --- FIN DE L'EXAMEN ---
            ecran.clearCMD();
            ecran.dessinerCadre();
            ecran.afficherTitre("RESULTATS");

            goto_xy(2, 6);
            moteur.afficherResultats();

            // Nettoyage de la m�moire (car on a fait un 'new')
            delete maStrategie;

            pauseJeu();
        }

    } while (choixMenu != 3);

    // FIN
    ecran.clearCMD();
    goto_xy(0, 0);
}


int main() {
    gestionnaire g{};
    g.excuter();
    return 0;
}
