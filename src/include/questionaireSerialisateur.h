#ifndef QUESTIONAIRESERIALISATEUR_H
#define QUESTIONAIRESERIALISATEUR_H
#include<string>
#include"questionaire.h"
#include"question.h"
#include"questionTexte.h"
#include"questionNumerique.h"
#include"questionChoixMultiple.h"


class questionaireSerialisateur
{
    public:
        questionaireSerialisateur();
        virtual ~questionaireSerialisateur();
        virtual void ecrire(const questionaire &quest,const std::string &nomQuestionaire)=0;
        virtual void ecrireQuestion(const question &q)=0;
        virtual void ecrireQuestionTexte(const questionTexte &qt)=0;
        virtual void ecrireQuestionNumerique(const questionTexte &qn)=0;
        virtual void ecrireQuestionChoixMultiple(const questionTexte &qc)=0;

};

#endif // QUESTIONAIRESERIALISATEUR_H
