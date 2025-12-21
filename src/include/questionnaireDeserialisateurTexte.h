#ifndef QUESTIONAIREDESERIALISATEURTEXTE_H
#define QUESTIONAIREDESERIALISATEURTEXTE_H
#include<iostream>
#include"questionnaire.h"
#include"questionnaireDeserialisateur.h"

class questionnaireDeserialisateurTexte : public  questionnaireDeserialisateur
{
    public:
        questionnaireDeserialisateurTexte(std::ifstream &ifs);
        questionnaire lire() override;
        questionTexte lireQuestionTexte() override;
        questionNumerique lireQuestionNumerique() override;
        questionChoixMultiple lireQuestionChoixMultiple() override;
    private:
        std::ifstream &ifs;
        /*
        retourne le type d'objet
        QN -> pour question numerique
        QT -> pour question text
        QC -> pour question ChoixsMultiple
        **/
        std::string determinerTypeObjet();
        // lire des phrase ex : [phrase]
        std::string lireString();
};

#endif // QUESTIONAIREDESERIALISATEURTEXTE_H
