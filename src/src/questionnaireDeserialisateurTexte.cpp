#include "../include/questionnaireDeserialisateurTexte.h"
#include<iostream>
#include<vector>
questionnaireDeserialisateurTexte::questionnaireDeserialisateurTexte(std::istream &ifs):ifs{ifs}{

}

questionnaire questionnaireDeserialisateurTexte::lire(){
    questionnaire quest{};

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
