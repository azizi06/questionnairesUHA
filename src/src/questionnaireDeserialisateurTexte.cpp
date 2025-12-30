#include "../include/questionnaireDeserialisateurTexte.h"
questionnaireDeserialisateurTexte::questionnaireDeserialisateurTexte(std::istream &ifs):ifs{ifs}{

}

questionnaire questionnaireDeserialisateurTexte::lire(){
    questionnaire quest{};
}
questionTexte questionnaireDeserialisateurTexte::lireQuestionTexte(){

}
questionNumerique questionnaireDeserialisateurTexte::lireQuestionNumerique(){

}
questionChoixMultiple questionnaireDeserialisateurTexte::lireQuestionChoixMultiple(){

}

std::string questionnaireDeserialisateurTexte::lireString() {
    std::string ligne;
    if (std::getline(ifs, ligne)) {
         if (ligne.front() == '[' && ligne.back() == ']') {
            return ligne.substr(1, ligne.length() - 2);
            }
         return ligne;
    }
    return "";
}
