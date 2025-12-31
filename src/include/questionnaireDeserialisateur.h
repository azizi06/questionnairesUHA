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
        questionnaireDeserialisateur()=default;
        virtual ~questionnaireDeserialisateur()=default;
        virtual std::unique_ptr<questionnaire>  lire()=0;
        virtual questionTexte lireQuestionTexte()=0;
        virtual questionNumerique lireQuestionNumerique()=0;
        virtual questionChoixMultiple lireQuestionChoixMultiple()=0;
};

#endif //QUESTIONAIRESERIALISATEUR_H
