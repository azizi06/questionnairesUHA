#include "affichage.h"
#include <iostream>
#include <cstdlib>
#include "goto_xy_windows.h"

using namespace std;

void affichage::clearCMD(){
    system("cls");
}

void affichage::afficherTitre(const string& titre){
    goto_xy(5, 2);
    cout << titre;
}

void affichage::afficherQuestion(const string& intitule){
    goto_xy(5, 6);
    cout << "Question :";
    goto_xy(5, 7);
    cout << intitule;
}

void affichage::afficherReponse(const string& reponse){
    goto_xy(5, 9);
    cout << "Reponse :";
    goto_xy(5, 10);
    cout << reponse;
}

void affichage::afficherMessage(const string& message){
    goto_xy(5, 13);
    cout << message;
}

