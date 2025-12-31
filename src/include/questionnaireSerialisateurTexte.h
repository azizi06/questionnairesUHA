#ifndef QUESTIONAIRESERIALISATEURTEXTE_H
#define QUESTIONAIRESERIALISATEURTEXTE_H
#include"questionnaireSerialisateur.h"

class questionnaireSerialisateurTexte : public questionnaireSerialisateur
{
    public:
        questionnaireSerialisateurTexte();
        virtual ~questionnaireSerialisateurTexte();

        void ecrire() override;
        void ecrireQuestion(const question &q) override;
        void ecrireQuestionTexte(const questionTexte &qt) override;
        void ecrireQuestionNumerique(const questionTexte &qn) override;
        void ecrireQuestionChoixMultiple(const questionTexte &qc) override;

    private:

};

#endif // QUESTIONAIRESERIALISATEURTEXTE_H
