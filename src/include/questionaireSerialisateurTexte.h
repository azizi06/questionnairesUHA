#ifndef QUESTIONAIRESERIALISATEURTEXTE_H
#define QUESTIONAIRESERIALISATEURTEXTE_H
#include"questionaireSerialisateur.h"

class questionaireSerialisateurTexte : public questionaireSerialisateur
{
    public:
        questionaireSerialisateurTexte();
        virtual ~questionaireSerialisateurTexte();

        void ecrire(const questionaire &quest,const std::string &nomQuestionaire) override;
        void ecrireQuestion(const question &q) override;
        void ecrireQuestionTexte(const questionTexte &qt) override;
        void ecrireQuestionNumerique(const questionTexte &qn) override;
        void ecrireQuestionChoixMultiple(const questionTexte &qc) override;

    private:
};

#endif // QUESTIONAIRESERIALISATEURTEXTE_H
