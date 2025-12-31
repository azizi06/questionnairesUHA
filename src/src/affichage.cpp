#include "../include/affichage.h"
#include "../include/goto_xy_windows.h"
#include <iostream>
#include <cstdlib>
#include "../include/utiles.h"

using namespace std;
affichage::affichage(std::ostream& ost, std::istream &ist):d_ost{ost},d_ist{ist}{

}
std::string affichage::entrer(){
    placerCurseurSaisie();
    std::string choix;
    d_ist >> choix;
    util::make_lower(choix);
    return choix;
}

void affichage::clearCMD() const {
    system("cls");
}
void affichage::pause(){
        goto_xy(2, 17);
        system("pause");
}

void affichage::dessinerCadre() const {
    std::string ligne{"+-------------------------------------------------------------------------------+"};
    int hauteur = 25;
    // Haut
    goto_xy(0, 0);  d_ost << ligne;
    // Bas
    goto_xy(0, hauteur); d_ost << ligne;

    // Cot�s
    for (int y = 1; y < hauteur; y++) {
        goto_xy(0, y);  d_ost << "|";
        goto_xy(ligne.size()-1, y); d_ost << "|";
    }
}
void affichage::curseur(int x,int y){
    goto_xy(x, y);
}

void affichage::afficherTitre(const string& titre) const {
    goto_xy(2, 2);
    d_ost << "=== " << titre << " ===";
}

void affichage::afficherQuestion(const string& intitule) const {
    goto_xy(2, 5);
    d_ost << "QUESTION :";
    goto_xy(2, 6);
    d_ost << intitule;
}

void affichage::afficherReponse(const string& reponse) const {
    goto_xy(2, 9);
    d_ost << "CORRECTION : " << reponse;
}

void affichage::afficherMessage(const string& message) const {
    goto_xy(2, 13);
    d_ost << "RESULTAT : " << message;
}

void affichage::placerCurseurSaisie() const {
    goto_xy(2, 14);
    d_ost << "Votre reponse > ";
}
