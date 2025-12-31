#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>

// --- TES INCLUDES (LOGIQUE) ---
#include "../include/evaluation.h"
#include "../include/strategies.h"
#include "../include/questionnaire.h"
#include "../include/questionTexte.h"
#include "../include/apprentissage.h"

// --- TON INCLUDE (VISUEL) ---
#include "../include/affichage.h"
#include "../include/goto_xy_windows.h"

using namespace std;

// Fonction utilitaire pour faire une pause propre
void pauseJeu() {
    goto_xy(2, 17); // En bas du cadre
    system("pause");
}

int main() {
    // =========================================================
    // 1. CRÉATION DE LA BASE DE DONNÉES (QUESTIONS)
    // =========================================================
    // On crée le questionnaire une seule fois au début
    questionnaire q;

    // Remplissage (Tu peux en ajouter autant que tu veux)
    q.add(make_unique<questionTexte>("Capitale de la France ?", "Paris"));
    q.add(make_unique<questionTexte>("Resultat de 3 * 7 ?", "21"));
    q.add(make_unique<questionTexte>("Mot cle pour une boucle ?", "while"));
    q.add(make_unique<questionTexte>("Animal qui aboie ?", "Chien"));
    q.add(make_unique<questionTexte>("Couleur du ciel ?", "Bleu"));

    affichage ecran;
    int choixMenu = 0;

    // =========================================================
    // 2. BOUCLE PRINCIPALE (MENU)
    // =========================================================
    do {
        ecran.clearCMD();
        ecran.dessinerCadre();
        ecran.afficherTitre("MENU PRINCIPAL");

        // Affichage du menu centré manuellement
        goto_xy(10, 6); cout << "1. MODE REVISION (Apprentissage)";
        goto_xy(10, 8); cout << "2. MODE EXAMEN (Evaluation)";
        goto_xy(10, 10); cout << "3. QUITTER";

        // Saisie du choix
        ecran.placerCurseurSaisie();
        cin >> choixMenu;

        // =====================================================
        // CAS 1 : MODE APPRENTISSAGE
        // =====================================================
        if (choixMenu == 1) {
            // On lance le module d'apprentissage
            // Il gère son propre affichage via sa méthode apprendre()
            apprentissage session(q);
            session.apprendre();

            // Quand c'est fini :
            ecran.clearCMD();
            ecran.dessinerCadre();
            ecran.afficherMessage("Revision terminee !");
            pauseJeu();
        }

        // =====================================================
        // CAS 2 : MODE ÉVALUATION
        // =====================================================
        else if (choixMenu == 2) {
            // 1. On configure la stratégie (Ici Adaptative, c'est la plus cool)
            StrategieAdaptative strat;
            strat.init(q.taille()); // On initialise avec la taille réelle du questionnaire

            // 2. On prépare le moteur
            evaluation moteur(&q, &strat);
            moteur.commencer();

            // 3. Boucle de jeu de l'examen
            while (moteur.aDesQuestions()) {
                // A. Mise en page
                ecran.clearCMD();
                ecran.dessinerCadre();
                ecran.afficherTitre("MODE EXAMEN");

                // B. Affichage Question
                const question* qCourante = moteur.questionCourante();
                if (qCourante) {
                    ecran.afficherQuestion(qCourante->Intitule());
                }

                // C. Saisie Réponse
                ecran.placerCurseurSaisie();
                string reponseUtilisateur;
                cin >> reponseUtilisateur;

                // D. Vérification
                bool estCorrect = moteur.repondre(reponseUtilisateur);

                // E. Feedback (Bravo/Raté)
                if (estCorrect) {
                    ecran.afficherMessage("BRAVO ! Bonne reponse.");
                } else {
                    ecran.afficherMessage("RATE...");

                    // Si la stratégie le permet (ex: après 2 essais), on aide
                    if (moteur.peutAfficherCorrection()) {
                        ecran.afficherReponse(qCourante->getReponseCorrecte());
                    }
                }

                // F. Suite
                moteur.questionSuivante();
                pauseJeu();
            }

            // 4. Fin de l'examen et Résultats
            ecran.clearCMD();
            ecran.dessinerCadre();
            ecran.afficherTitre("RESULTATS");

            // On affiche le score proprement
            goto_xy(2, 6);
            moteur.afficherResultats();

            pauseJeu();
        }

    } while (choixMenu != 3); // Tant qu'on ne choisit pas 3, on revient au menu

    // =========================================================
    // 3. FIN DU PROGRAMME
    // =========================================================
    ecran.clearCMD();
    ecran.dessinerCadre();
    goto_xy(15, 8); cout << "AU REVOIR !";
    goto_xy(0, 18);

    return 0;
}
