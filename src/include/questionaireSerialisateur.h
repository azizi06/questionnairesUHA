#ifndef QUESTIONAIRESERIALISATEUR_H
#define QUESTIONAIRESERIALISATEUR_H
#include<string>
#include"question.h"
#include"questionChoixMultiple.h"
#include"questionNumerique.h"
#include"questionTexte.h"

class questionaireSerialisateur
{
    public:
        questionaireSerialisateur();
        virtual ~questionaireSerialisateur();
        void ecrire(const questionaire &quest,const std::string &nomQuestionaire);
        void ecrireQuestion(const question &q);
        void ecrireQuestionTexte(const questionTexte &qt);
        void ecrireQuestionNumerique(const questionTexte &qn);
        void ecrireQuestionChoixMultiple(const questionTexte &qc);

    protected:

    private:
};

#endif // QUESTIONAIRESERIALISATEUR_H
