#include "../include/affichage.h"
#include <iostream>
#include <cstdlib>
#include "../include/goto_xy_windows.h"
using namespace std;

void affichage::clearCMD()const{
    system("cls");
}
//les coordonnees seront modifiees plus tard pour ameliorer l'affichage,
// Aucune vrai mise en forme n'est encore mise en place
void affichage::afficherTitre(const string& titre)const{
    goto_xy(1,1);
    cout << titre;
}
void affichage::afficherQuestion(const string& intitule)const{
     goto_xy(1,3);
     cout << "La question :";
     goto_xy(1,4);
     cout << intitule;
}
void affichage::afficherReponse(const string& reponse)const{
     goto_xy(1,6);
     cout << "La reponse :";
     goto_xy(1,7);
     cout << reponse;
}
void affichage::afficherMessage(const string& message)const{
    goto_xy(1,9);
    cout << message;
}

