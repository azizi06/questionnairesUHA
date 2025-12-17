#ifndef QUESTIONAIREDESERIALISATEURTEXTE_H
#define QUESTIONAIREDESERIALISATEURTEXTE_H
#include"questionaire.h"
#include"questionaireDeserialisateur.h"

class questionaireDeserialisateurTexte : public  questionaireSerialisateur
{
    public:
        questionaireDeserialisateurTexte();
        virtual ~questionaireDeserialisateurTexte();
        questionaire lire(const std::string &nomFichier) override;
        question lireQuestionTexte() override;
        questionTexte lireQuestionTexte() override;
        questionTexte lireQuestionNumerique() override;
        questionChoixMultiple lireQuestionChoixMultiple override;

    private:
};

#endif // QUESTIONAIREDESERIALISATEURTEXTE_H
