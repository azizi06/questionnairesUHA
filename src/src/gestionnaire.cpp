#include "../include/gestionnaire.h"
#include "../include/goto_xy_windows.h"
#include "../include/strategieEvaluation.h"
#include "../include/evaluation.h"
#include "../include/strategies.h"
#include "../include/apprentissage.h"
#include "../include/questionnaireDeserialisateurTexte.h"
#include "../include/dirent.h"
#include "../include/utiles.h"
#include <fstream>

gestionnaire::gestionnaire(std::istream &ist,std::ostream &ost):d_ist{ist},d_ost{ost},ecran{affichage{}}
{
    //ctor
}
std::unique_ptr<questionnaire>  gestionnaire::questionnaireParDefault(){
    std::ifstream f("../data/questionnaire-geographie.txt");
    if(!f){
        d_ost << "impossible ouvrire le fichier";
    }
    questionnaireDeserialisateurTexte d{f};
    auto q = d.lire();

    f.close();
    return std::move(q);
}

void gestionnaire::affmenu(){
    ecran.clearCMD();
    ecran.dessinerCadre();
    ecran.afficherTitre("MENU PRINCIPAL");

    goto_xy(10, 6); d_ost << "1. MODE REVISION (Apprentissage)";
    goto_xy(10, 8); d_ost << "2. MODE EXAMEN (Evaluation)";
    goto_xy(10, 10); d_ost << "3. QUITTER";

}
std::unique_ptr<strategieEvaluation>  gestionnaire::choisireStrategie(){
    ecran.clearCMD();
    ecran.dessinerCadre();
    ecran.afficherTitre("CHOIX DE LA STRATEGIE");

    goto_xy(5, 6); d_ost << "1. CLASSIQUE (Lineaire, pas d'aide)";
    goto_xy(5, 8); d_ost << "2. SECONDE CHANCE (2 essais autorises)";
    goto_xy(5, 10); d_ost <<"3. ADAPTATIVE (Repose les questions ratees)";
    goto_xy(5, 12); d_ost <<"4. retour au menu principale";
    int choix ;
    bool choixValide = false;
    std::unique_ptr<strategieEvaluation>  maStrategie;
    while (!choixValide)
    {
        choix = std::stoi(ecran.entrer());
        if (choix == 1) {
            maStrategie =std::make_unique<StrategieTest>(); 
            choixValide = true;
        } else if (choix == 2) {
            maStrategie = std::make_unique<StrategieSecondeChance>();
            choixValide = true;

        } else if(choix == 3) {
            maStrategie   = std::make_unique<StrategieAdaptative>();
            choixValide = true;
        }
        else if(choix == 4) {
                maStrategie   = nullptr;
                choixValide = true;
            
        }else{
            ecran.curseur(5,12);d_ost << "choix invalide\n";
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
        int choix = std::stoi(ecran.entrer());
        if(choix == 1){
            auto q = choisirquestionnaire();//questionnaireParDefault();
            if(q != nullptr){
                apprentissage session(*q);
                session.apprendre(); 
                ecran.clearCMD();
                ecran.dessinerCadre();
                ecran.afficherMessage("Revision terminee !");
                ecran.pause();
            }
        }else if(choix == 2){
           auto q= choisirquestionnaire();//questionnaireParDefault();
           auto maStrategie = choisireStrategie();
           if(maStrategie != nullptr && q!= nullptr){
            evaluation maEvaluation{q.get(),maStrategie.get()};
            maEvaluation.commencer();
            maEvaluation.evaluer(ecran); 
            }        

        }else if (choix == 3){
            encore = false;
        }else{
            ecran.curseur(5,13);d_ost<<"choix invalide\n";
            ecran.pause();
        }
        

    }

}
std::unique_ptr<questionnaire>  gestionnaire::choisirquestionnaire(){
    std::vector<std::string> list = listeQuestionnair();
    if(list.size()==0){ 
        return questionnaireParDefault();
    }
    ecran.clearCMD();
    ecran.dessinerCadre();
    ecran.afficherTitre("Liste Questionnaires");
    std::string strList = "";

    for (int i = 0; i < list.size(); ++i) {
        strList += std::to_string(i) + ". " + list[i] + "\n  ";
    }
    strList += std::to_string(list.size()) +". quitter";
    ecran.curseur(5,6);
    d_ost << strList;
    int choix ;
    bool estValid = false;
    while(!estValid){
        choix = std::stoi(ecran.entrer());
        if(choix >= 0 && choix <= list.size() -1){
            estValid = true;
        }else if(choix == list.size()){
            return nullptr;
        }else{
            ecran.curseur(5,20);d_ost<<"choix invalide\n";
            ecran.pause();
        }
    }

    std::fstream f(DATAREP+"/"+list[choix]);
    questionnaireDeserialisateurTexte deserialisateur{f};
    auto q = deserialisateur.lire();
    f.close();
    return q;
}
std::vector<std::string> gestionnaire::listeQuestionnair(){
    std::vector<std::string> listQ{};
    DIR* rep = opendir(gestionnaire::DATAREP.c_str());
    dirent *elem;
    while ((elem=readdir(rep))!=nullptr){
        std::string fichier{elem->d_name};
        if(fichier != "." && fichier!=".." && elem->d_type == DT_REG){
            listQ.push_back(fichier);
        }
    }
    return listQ;


}

