#include "Affichage.h"
#include <iostream>
#include <cstdlib> // system
#include "goto_xy_windows.h"

using namespace std;

void Affichage::nettoyer()
{
    system("cls");
}

void Affichage::afficherTitre(const string& titre)
{
    goto_xy(5, 1);
    cout << "============================================";
    goto_xy(5, 2);
    cout << titre;
    goto_xy(5, 3);
    cout << "============================================";
}

void Affichage::afficherQuestion(const string& intitule)
{
    goto_xy(5, 6);
    cout << "Question :";
    goto_xy(5, 7);
    cout << intitule;
}

void Affichage::afficherReponse(const string& reponse)
{
    goto_xy(5, 9);
    cout << "Reponse :";
    goto_xy(5, 10);
    cout << reponse;
}

void Affichage::afficherMessage(const string& msg)
{
    goto_xy(5, 13);
    cout << msg;
}

