#include "../include/gestionnaire.h"
#include "../include/goto_xy_windows.h"
#include "../include/strategieEvaluation.h"
#include "../include/strategies.h"
#include "../include/apprentissage.h"
#include "../include/questionnaireDeserialisateurTexte.h"
#include <fstream>

gestionnaire::gestionnaire(std::istream &ist,std::ostream &ost):d_ist{ist},d_ost{ost},ecran{affichage{}}
{
    //ctor
}
questionnaire  gestionnaire::questionnaireParDefault(){
    std::ifstream f("../data/questionnaire-geographie.txt");
    if(!f){
        d_ost << "impossible ouvrire le fichier";
    }
    questionnaireDeserialisateurTexte d{f};
    questionnaire q = d.lire();
    f.close();
    return q;
}
std::string gestionnaire::entrer(){
    ecran.placerCurseurSaisie();
    std::string choix;
    d_ist >> choix;
    return choix;
}
void gestionnaire::affmenu(){
    ecran.clearCMD();
    ecran.dessinerCadre();
    ecran.afficherTitre("MENU PRINCIPAL");

    goto_xy(10, 6); d_ost << "1. MODE REVISION (Apprentissage)";
    goto_xy(10, 8); d_ost << "2. MODE EXAMEN (Evaluation)";
    goto_xy(10, 10); d_ost << "3. QUITTER";

    

}
strategieEvaluation*  gestionnaire::choisireStrategie(){
    ecran.clearCMD();
    ecran.dessinerCadre();
    ecran.afficherTitre("CHOIX DE LA STRATEGIE");

    goto_xy(5, 6); d_ost << "1. CLASSIQUE (Lineaire, pas d'aide)";
    goto_xy(5, 8); d_ost << "2. SECONDE CHANCE (2 essais autorises)";
    goto_xy(5, 10); d_ost << "3. ADAPTATIVE (Repose les questions ratees)";
    int choix ;
    bool choixValide = false;
    strategieEvaluation* maStrategie;
    while (!choixValide)
    {
        choix = std::stoi(entrer());
        if (choix == 1) {
            maStrategie = new StrategieTest(); 
            choixValide = true;
        } else if (choix == 2) {
            maStrategie = new StrategieSecondeChance();
            choixValide = true;

        } else if(choix == 3) {
            maStrategie = new StrategieAdaptative();
            choixValide = true;
        }else{
            goto_xy(5,12);d_ost << "choix invalide";
            ecran.pause();
        }

    }
    return maStrategie;
    



}
void gestionnaire::excuter(){
    bool encore = true;
    char option;

    while(encore){
        affmenu();
        int choix = std::stoi(entrer());
        if(choix == 1){
            auto q = questionnaireParDefault();
            apprentissage session(q);
            session.apprendre(); // Lance le mode r�vision
            ecran.clearCMD();
            ecran.dessinerCadre();
            ecran.afficherMessage("Revision terminee !");
            ecran.pause();

        }else if(choix == 2){

        }else if (choix == 3)
        {
            encore = false;
        }else{
            goto_xy(5,13);d_ost<<"choix invalide";
            ecran.pause();
        }
        

    }

}

