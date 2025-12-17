#ifndef QUESTIONAIRESERIALISATEUR_H
#define QUESTIONAIRESERIALISATEUR_H
#include<string>

class questionaireDeserialisateur
{
    public:
        questionaireDeserialisateur();
        virtual ~questionaireDeserialisateur();
        questionaire lire(const std::string &nomFichier);\
        void lireQuestion(const question &q);
        questionTexte lireQuestionTexte(const questionTexte &qt);
        questionTexte lireQuestionNumerique(const questionNumerique &qn);
        questionChoixMultiple lireQuestionChoixMultiple(const questionChoixMultiple &qc);


    private:
};

#endif //QUESTIONAIRESERIALISATEUR_H
