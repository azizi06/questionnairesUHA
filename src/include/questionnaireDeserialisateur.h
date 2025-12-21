#ifndef QUESTIONAIRESERIALISATEUR_H
#define QUESTIONAIRESERIALISATEUR_H
#include<string>
#include"questionnaire.h"
#include"question.h"
#include"questionTexte.h"
#include"questionNumerique.h"
#include"questionChoixMultiple.h"

class questionnaireDeserialisateur
{
    public:
        questionnaireDeserialisateur();
        virtual ~questionnaireDeserialisateur();
        virtual questionnaire lire()=0;
        virtual questionTexte lireQuestionTexte()=0;
        virtual questionTexte lireQuestionNumerique()=0;
        virtual questionChoixMultiple lireQuestionChoixMultiple()=0;

    private:
};

#endif //QUESTIONAIRESERIALISATEUR_H
