#ifndef QUESTIONAIREDESERIALISATEURTEXTE_H
#define QUESTIONAIREDESERIALISATEURTEXTE_H
#include<iostream>
#include"questionnaire.h"
#include"questionnaireDeserialisateur.h"

class questionnaireDeserialisateurTexte : public  questionnaireDeserialisateur
{
    public:
        questionnaireDeserialisateurTexte(ifstream &ifs);
        virtual ~questionnaireDeserialisateurTexte();
        questionnaire lire() override;
        question lireQuestionTexte() override;
        questionTexte lireQuestionTexte() override;
        questionTexte lireQuestionNumerique() override;
        questionChoixMultiple lireQuestionChoixMultiple override;

    private:
        ifstream &ifs;
        /*
        retourne le type d'objet
        QN -> pour question numerique
        QT -> pour question text
        QC -> pour question ChoixsMultiple
        **/
        string determinerTypeObjet()

};

#endif // QUESTIONAIREDESERIALISATEURTEXTE_H
