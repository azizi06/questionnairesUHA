#include "../include/affichage.h"
#include "../include/goto_xy_windows.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void affichage::clearCMD() const {
    system("cls");
}

void affichage::dessinerCadre() const {
    // Haut
    goto_xy(0, 0);  cout << "+--------------------------------------------------+";
    // Bas
    goto_xy(0, 16); cout << "+--------------------------------------------------+";

    // Cotés
    for (int y = 1; y < 16; y++) {
        goto_xy(0, y);  cout << "|";
        goto_xy(51, y); cout << "|";
    }
}

void affichage::afficherTitre(const string& titre) const {
    goto_xy(2, 2);
    cout << "=== " << titre << " ===";
}

void affichage::afficherQuestion(const string& intitule) const {
    goto_xy(2, 5);
    cout << "QUESTION :";
    goto_xy(2, 6);
    cout << intitule;
}

void affichage::afficherReponse(const string& reponse) const {
    goto_xy(2, 11);
    cout << "CORRECTION : " << reponse;
}

void affichage::afficherMessage(const string& message) const {
    goto_xy(2, 9);
    cout << "RESULTAT : " << message;
}

void affichage::placerCurseurSaisie() const {
    goto_xy(2, 14);
    cout << "Votre reponse > ";
}
