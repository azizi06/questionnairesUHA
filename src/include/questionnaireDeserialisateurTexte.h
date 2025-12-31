#ifndef QUESTIONAIREDESERIALISATEURTEXTE_H
#define QUESTIONAIREDESERIALISATEURTEXTE_H
#include<iostream>
#include"../include/questionnaire.h"
#include"../include/questionnaireDeserialisateur.h"

class questionnaireDeserialisateurTexte : public  questionnaireDeserialisateur
{
    public:
        questionnaireDeserialisateurTexte(std::istream &ifs);
        questionnaire lire() override;
        questionTexte lireQuestionTexte() override;
        questionNumerique lireQuestionNumerique() override;
        questionChoixMultiple lireQuestionChoixMultiple() override;
        /*
        retourne le type d'objet
        QN -> pour question numerique
        QT -> pour question text
        QC -> pour question ChoixsMultiple
        **/
        int determinerTypeObjet(const std::string &ligne);
        // lire des phrase ex : [phrase]
        std::string lireString();
     std::vector<std::string> trim(std::string& phrase, char sep);
    private:
        std::istream &ifs;

};

#endif // QUESTIONAIREDESERIALISATEURTEXTE_H
