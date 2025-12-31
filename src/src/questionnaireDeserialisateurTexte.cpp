#include "../include/questionnaireDeserialisateurTexte.h"
#include<iostream>
#include<vector>
questionnaireDeserialisateurTexte::questionnaireDeserialisateurTexte(std::istream &ifs):ifs{ifs}{

}
int questionnaireDeserialisateurTexte::determinerTypeObjet(const std::string &ligne){
    if(ligne.find("QT") == 0){
        return QT;
    }else if(ligne.find("QN") == 0){
        return QN;
    }else if(ligne.find("QC") == 0){
        return QC;
    }else{
        return 0;
    }
}

questionnaire questionnaireDeserialisateurTexte::lire(){
    //ifs.seekg(0);
    std::string titre = lireString();
    questionnaire quest{};
    quest.setTitre(titre);
    std::string ligne;
    while(std::getline(ifs,ligne)){
            switch(determinerTypeObjet(ligne)){
        case QT:{     std::cout << "hell\n";
            auto qT = lireQuestionTexte();
            quest.add(std::make_unique<questionTexte>(qT));
            break;
        }
        case QN:{//QN:
            auto qN = lireQuestionNumerique();
            quest.add(std::make_unique<questionNumerique>(qN));
            break;
        }
        case QC:{//QC
            auto qC = lireQuestionChoixMultiple();
            quest.add(std::make_unique<questionChoixMultiple>(qC));
            break;
        }
        default:{
            std::cout << "erreur syntaxique";
            break;
        }
            }

    }
    return quest;

}

questionTexte questionnaireDeserialisateurTexte::lireQuestionTexte(){
    std::string ligne;
    //lire{
    if (!std::getline(ifs, ligne)) {
        std::cout << "Erreur de lecture: ligne attendue pour question texte";
    }
    size_t pos = ligne.find('{');
    if (pos == std::string::npos) {
         std::cout << "Format invalide";
    }
    std::string enonce = lireString();
    std::string reponseCorrecte = lireString();
    //lire }
  if (!std::getline(ifs, ligne)) {
        std::cout << "Erreur de lecture: ligne attendue pour question texte";
    }
    return questionTexte(enonce, reponseCorrecte);


}
questionNumerique questionnaireDeserialisateurTexte::lireQuestionNumerique(){
    std::string ligne;
    //lire{
    if (!std::getline(ifs, ligne)) {
        std::cout << "Erreur de lecture: ligne attendue pour question";

    }
    size_t pos = ligne.find('{');
    if (pos == std::string::npos) {
        std::cout << "Format invalide pour question texte";
    }
    std::string enonce = lireString();
    int reponse = std::stoi(lireString());
    int valeurMin = std::stoi(lireString());
    int valeurMax = std::stoi(lireString());
    //lire }
    if (!std::getline(ifs, ligne)) {
       std::cout << "Erreur de lecture: ligne attendue pour question";
    }
    return questionNumerique(enonce, reponse,valeurMin,valeurMax);

}
questionChoixMultiple questionnaireDeserialisateurTexte::lireQuestionChoixMultiple(){
    std::string ligne;
    //lire{
    if (!std::getline(ifs, ligne)) {
        std::cout << "Erreur de lecture: ligne attendue pour question";
    }
    size_t pos = ligne.find('{');
    if (pos == std::string::npos) {
        std::cout << "Format invalide pour question texte";
    }
    std::string enonce = lireString();
    std::string strOptions{lireString()};
    std::vector<std::string> options =  trim(strOptions,SEPARATEUR);
    int reponse =   std::stoi(lireString());

    //lire }
  if (!std::getline(ifs, ligne)) {
       std::cout << "Erreur de lecture: ligne attendue pour question";
    }
    return questionChoixMultiple(enonce,options,reponse);
}
std::vector<std::string> questionnaireDeserialisateurTexte::trim(std::string& phrase, char sep) {
    std::vector<std::string> resultat;
    if (phrase.empty()) {
        return resultat;
    }
    int debut = 0;
    int fin = 0;
    while (debut < phrase.size()) {
        fin = phrase.find(sep, debut);
        std::string element;
        if (fin == std::string::npos) {
            element = phrase.substr(debut);
        } else {
            element = phrase.substr(debut, fin - debut);
        }
        resultat.push_back(element);
        if (fin == std::string::npos) {
            break;
        }
        debut = fin + 1;
    }
    return resultat;
}
std::string questionnaireDeserialisateurTexte::lireString() {
    std::string ligne;
    if (std::getline(ifs, ligne)) {
         if (ligne.front() == DEBUTTEXT && ligne.back() == FINTEXT) {
            return ligne.substr(1, ligne.length() - 2);
            }
         return ligne;
    }
    return "";
}
