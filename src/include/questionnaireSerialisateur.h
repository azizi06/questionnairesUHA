#ifndef QUESTIONAIRESERIALISATEUR_H
#define QUESTIONAIRESERIALISATEUR_H
#include<string>
#include"questionnaire.h"
#include"question.h"
#include"questionTexte.h"
#include"questionNumerique.h"
#include"questionChoixMultiple.h"


class questionnaireSerialisateur
{
    public:
        questionnaireSerialisateur();
        virtual ~questionnaireSerialisateur();
        virtual void ecrire(const questionnaire &quest,const std::string &nomQUESTIONAIRE)=0;
        virtual void ecrireQuestion(const question &q)=0;
        virtual void ecrireQuestionTexte(const questionTexte &qt)=0;
        virtual void ecrireQuestionNumerique(const questionTexte &qn)=0;
        virtual void ecrireQuestionChoixMultiple(const questionTexte &qc)=0;

};

#endif // QUESTIONAIRESERIALISATEUR_H
